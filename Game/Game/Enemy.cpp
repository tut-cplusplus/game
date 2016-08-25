#define _USE_MATH_DEFINES
#include <random>
#include <cmath>

#include "Global.hpp"
#include "Enemy.hpp"
#include "CircularSector.hpp"
#include "RegionSet.hpp"

#include <GL/glut.h>

using namespace std;

void Enemy::loadAnimations(void)
{
	animation = Animation("data/animations/Enemy/Enemy.ani");
	animations.push_back(animation);
	Character::loadAnimations();
}

Enemy::Enemy(const Vector<double>& position, const Size<double>& size, double speed, double viewAngle, double radius, int life, double informationSpeed)
	: Character(position, size, speed), viewAngle(viewAngle), radius(radius), first(true), life(life), informationSpeed(informationSpeed), isFindPlayer(false), isLookingPlayer(false), isDestroyBlock(false), isUpdateTarget(false)
{
	init();
}

Enemy::~Enemy()
{

}

void Enemy::onMoveAI(RegionSet const &regionSet)
{
	static random_device rd;
	static mt19937 mt(rd());
	static uniform_int_distribution<int> randomDirection(NORTH, WEST);

	//移動中であれば何もしない
	if (isMoving) {
		return;
	}

	//HACK: 依存大きくなるけど引数でregionもらいました
	Vector<int> old(oldTarget);
	Vector<int> start(position);
	Vector<int> end(newTarget);
	Region const region = regionSet.search(start);

	if (region.getPositionNum() <= Global::KILL_ENEMY_THRESHOLD) {
		isDestroyBlock = true;
	}

	if (isUpdateTarget) {
		isUpdateTarget = false;
		try {
			route = region.breadthFirstSearch(start, end);
		}
		catch (Region::CannotArriveException const &e) {
			isDestroyBlock = true;
		}
	}

	if (isFindPlayer) {
		if (route.getPositionNum()) {
			Vector<int> next = route.getNextPosition();
			route = --route;

			if (next.getX() > start.getX()) {
				direction = EAST;
			}
			else if (next.getX() < start.getX()) {
				direction = WEST;
			}
			else if (next.getY() > start.getY()) {
				direction = NORTH;
			}
			else if (next.getY() < start.getY()) {
				direction = SOUTH;
			}
		}
		else {
			isFindPlayer = false;
			isLookingPlayer = false;
		}
	}

	//移動の開始
	startMoving();
}

void Enemy::onHit(void)
{
	static random_device rd;
	static mt19937 mt(rd());
	static uniform_int_distribution<int> randomDirection(NORTH, WEST);

	Character::onHit();

	if (isDestroyBlock && life) {
		isBreaking = true;
		isDestroyBlock = false;
		life --;
		return ;
	}

	if (!isBreaking) {
			direction = (Direction)randomDirection(mt);
	}

	//移動の開始
	startMoving();
}

void Enemy::onFindDirect(const Character& character)
{
	//初めて見つけたプレイヤーを目視したとき情報伝達を行う
	//もしくは見失ってから再度見つけたとき
	if (!isLookingPlayer) {
		onFindFirst(character);
	}

	isLookingPlayer = true;
	onFind(character);
}

void Enemy::onFind(const Character& character)
{
	oldTarget = newTarget;
	newTarget = character.getPosition();
	isFindPlayer = true;
	isUpdateTarget = true;
}

void Enemy::onFindFirst(const Character& character)
{
	Vector<double> position = this->position;
	const Size<double>& size = character.getSize();
	position.setX(position.getX() * size.getWidth());
	position.setY(position.getY() * size.getHeight());
	Information information(position, 50, character, informationSpeed);
	information.registerID(ID);
	informations.push_back(information);
}

void Enemy::onFind(const Vector<int>& position, const Block& block)
{
	bool flag = region.search(position);
	if (block.isTransparentByEnemy()) {
		if (flag)
			return;
		region += position;
	} else {
		if (!flag)
			return;
		region -= position;
	}
}

void Enemy::changeColor(void) const
{
	glColor3d(1.0, 1.0, 1.0);
}

void Enemy::draw(void)
{
	if (!isFindPlayer)
		isLookingPlayer = false;
	//本体の表示
	Character::draw();
}

void Enemy::drawVisibility() const
{
	double width = size.getWidth();
	double height = size.getHeight();
	double angle = getAngle();
	//視界の表示
	CircularSector circularSector(Vector<double>(width / 2, height / 2), angle, viewAngle, radius);
	circularSector.draw();
}

void Enemy::drawInformations(void)
{
	//伝達情報の表示
	for (auto itr = informations.begin(); itr != informations.end(); ++itr) {
		Information& information = *itr;
		information.draw();
		double radius = information.getRadius();
		if (radius > 2 * Global::WORLD_WIDTH) {
			itr = informations.erase(itr);
			break;
		}
	}
}

void Enemy::drawRoute(void)
{
	glColor3d(1.0, 1.0, 1.0);
	const list<Vector<int>>& positions = route.getPositions();
	const Size<double>& size = getSize();
	double width = size.getWidth();
	double height = size.getHeight();
	for (auto itr = positions.begin(); itr != positions.end(); ++itr) {
		const Vector<int>& position = *itr;
		glPushMatrix();
		glTranslated(position.getX() * width, position.getY() * height, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2d(0.0, 0.0);
		glVertex2d(width, 0.0);
		glVertex2d(width, height);
		glVertex2d(0.0, height);
		glVertex2d(width, 0.0);
		glVertex2d(width, height);
		glEnd();
		glPopMatrix();
	}
}

void Enemy::drawRegion(void)
{
	static double colors[][3] = {
		{1.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{0.0, 0.0, 1.0},
		{1.0, 1.0, 0.0},
		{1.0, 0.0, 1.0},
		{0.0, 1.0, 1.0},
		{1.0, 1.0, 1.0},
	};
	unsigned n = sizeof(colors) / sizeof(colors[0]);
	unsigned idx = getID() % n;
	const double* color = colors[idx];
	glColor3d(color[0], color[1], color[2]);
	const list<Vector<int>>& positions = region.getPositions();
	const Size<double>& size = getSize();
	double width = size.getWidth();
	double height = size.getHeight();
	for (auto itr = positions.begin(); itr != positions.end(); ++itr) {
		const Vector<int>& position = *itr;
		glPushMatrix();
		glTranslated(position.getX() * width, position.getY() * height, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2d(0.0, 0.0);
		glVertex2d(width, 0.0);
		glVertex2d(width, height);
		glVertex2d(0.0, height);
		glEnd();
		glPopMatrix();
	}
}

