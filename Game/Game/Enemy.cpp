#define _USE_MATH_DEFINES
#include <random>
#include <cmath>
#include <limits>

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
	: Character(position, size, speed), viewAngle(viewAngle), radius(radius), first(true), life(life), informationSpeed(informationSpeed), isFindPlayer(false)
{
	init();
}

Enemy::~Enemy()
{

}

void Enemy::updateRoute(void)
{
	static std::random_device rd;
	static std::mt19937 mt;

	Vector<int> start(position);
	if (isFindPlayer) {
		try {
			route = region.breadthFirstSearch(start, playerPosition);
		}
		catch (Region::CannotArriveException const &e) {
			route = Route(start, playerPosition);
		}
	} else {
		auto randomRoute = [&]() {
			uniform_int_distribution<int> randomDirection(NORTH, WEST);
			int direction = randomDirection(mt);
			static Vector<int> directionTable[] = {
				Vector<int>(),
				Vector<int>(0, 1),
				Vector<int>(0, -1),
				Vector<int>(1, 0),
				Vector<int>(-1, 0),
			};
			route += start + directionTable[direction];
		};
		const list<Vector<int>>& positions = region.getPositions();
		if (!positions.size()) {
			randomRoute();
			return;
		}
		std::uniform_int_distribution<int> rnd(0, positions.size() - 1);
		int idx = rnd(mt);
		auto itr = positions.begin();
		while (idx-- > 0)
			++itr;
		Vector<int> end = *itr;
		try {
			route = region.breadthFirstSearch(start, end);
		}
		//このcatch節は、敵自身がマップに含まれない場合に通過する
		//毎フレームマップ全体を走査しないため、このcatch節が必要
		catch (Region::CannotArriveException const &e) {
			randomRoute();
		}
	}
}

void Enemy::onMoveAI()
{
	if (!isLookingPlayerThisFrame)
		isLookingPlayer = false;
	isLookingPlayerThisFrame = false;

	//移動中であれば何もしない
	if (isMoving) {
		return;
	}

	Vector<int> start(position);
	if (route.getPositionNum()) {
		Vector<int> next = route.getNextPosition();
		if (start == next)
			--route;
		if (isFindPlayer && !route.getPositionNum() && start == playerPosition)
			isFindPlayer = false;
	}

	if (route.getPositionNum()) {
		Vector<int> next = route.getNextPosition();

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
		//移動の開始
		startMoving();
		return;
	}

	updateRoute();
}

void Enemy::onHit(void)
{
	static std::random_device rd;
	static std::mt19937 mt;
	uniform_int_distribution<int> rnd(0, 5);
	Character::onHit();
	if ((isFindPlayer || !rnd(mt)) && life) {
		isBreaking = true;
		life--;
		return;
	}

	isFindPlayer = false;
	route = Route();
	static Vector<int> directionTable[] = {
		Vector<int>(),
		Vector<int>(0, 1),
		Vector<int>(0, -1),
		Vector<int>(1, 0),
		Vector<int>(-1, 0),
	};
	Vector<int> newPosition = Vector<int>(getSource()) + directionTable[getDirection()];
	if (region.search(newPosition))
		region -= newPosition;
}

void Enemy::onFindDirect(const Character& character)
{
	isLookingPlayerThisFrame = true;
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
	playerPosition = Vector<int>(character.getPosition());
	isFindPlayer = true;
	updateRoute();
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

void Enemy::drawRoute(void) const
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

void Enemy::drawRegion(void) const
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

Vector<int> Enemy::getNearestReachablePosition(void) const
{
	double minNorm = numeric_limits<double>::max();
	Vector<int> minPosition;
	const list<Vector<int>>& positions = region.getPositions();
	for (auto itr = positions.begin(); itr != positions.end(); ++itr) {
		const Vector<int>& position = *itr;
		double norm = (position - playerPosition).norm2();
		if (norm < minNorm) {
			minNorm = norm;
			minPosition = position;
		}
	}
	return minPosition;
}

