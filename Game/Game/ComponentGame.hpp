#ifndef ___Class_ComponentGame
#define ___Class_ComponentGame

#include <vector>
#include <random>
#include <list>

#include "Component.hpp"
#include "Block.hpp"
#include "BlockAir.hpp"
#include "Vector.hpp"
#include "Player.hpp"
#include "NormalEnemy.hpp"
#include "Decoy.hpp"
#include "Size.hpp"
#include "ItemBlock.hpp"
#include "Global.hpp"
#include "EnemyGenerator.hpp"
#include "RegionSet.hpp"

#include "GL/glut.h"
#include "AL/alut.h"

class ComponentGame : public Component {
public:
	class CannotAllocateException{};	//メモリ確保に失敗

private:
	static const int MAP_WIDTH;			//マップ配列の幅
	static const int MAP_HEIGHT;		//マップ配列の高さ
	static const int DIVISION_NUMBER;	//当たり判定における分割数

private:
	//マップの生成に用いる乱数
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_real_distribution<double> rnd;

	Block*** map;					//マップ
	std::vector<Player*> players;	//プレイヤー
	std::vector<Decoy*> decoys;		//デコイ
	std::vector<Enemy*> enemies;	//敵
	std::vector<ItemBlock*> itemBlocks;	//アイテム
	Size<double> blockSize;			//ブロックの大きさ
	Audio audio;
	RegionSet regionSet;			//マップの空間の認識に用いる（敵の死亡処理用）
	Block*** visibleMap;
	EnemyGenerator enemyGenerator;

private:
	/**
	 * マップの配列を生成する
	 * ただし，ブロックのインスタンス生成は行わない
	 */
	void allocMap(void);
	void allocIsVisibleMap(void);
	/**
	 * マップの配列を生成しなおす
	 * ただし，ブロックのインスタンス生成は行わない
	 */
	void clearMap(void);
	/**
	 * マップを生成する
	 * 必ずallocMap()の後に行わなければならない
	 */
	void generateMap(void);
	/**
	 * 壁を4マス生成することのできる方向を取得する
	 *
	 * @param v マップ上の位置
	 * @return vを中心に4マス壁を生成することのできる方向の単位ベクトル
	 */
	std::vector<int> getValidDirections(const Vector<int>& v);
	/**
	 * マップの配列を解放する
	 * この後にgenerateMap()を行ってはならない
	 *
	 * @param map マップ
	 */
	void deleteMap(Block*** map);
	void deleteIsVisibleMap(void);
	/**
	 * プレイヤーを一人追加する
	 * ランダムな位置に追加される
	 */
	void addPlayer(void);
	/**
	 * プレイヤーを全員解放する
	 */
	void deletePlayers(void);
	/**
	 * 敵を一体追加する
	 * ランダムな位置に追加される
	 */
	void addEnemy(void);
	/**
	 * 敵を一体追加する
	 *
	 * @param position 座標
	 */
	void addEnemy(const Vector<double>& position);
	/**
	 * 敵を全員解放する
	 */
	void deleteEnemies(void);
	/**
	 * 条件を満たす敵を殺す
	 */
	void killEnemies(void);
	/**
	 * キャラクターを描画する
	 *
	 * @param characters キャラクターのvector配列
	 */
	template <typename T>
	void drawCharacters(const std::vector<T*> characters) const;
	/**
	 * ある地点から一定距離内のキャラクターを描画する
	 *
	 * @param characters キャラクターのvector配列
	 * @param position 中心地点
	 * @param distance 距離
	 */
	template <typename T>
	void drawCharacters(const std::vector<T*> characters, const Vector<double>& position, double distance) const;
	/**
	 * ある地点から一定距離内のアイテムを描画する
	 *
	 * @param position 中心地点
	 * @param distance 距離
	 */
	void drawItemBlocks(const Vector<double>& position, double distance);
	/**
	 * キャラクターの視界を描画する
	 */
	template <typename T>
	void drawCharacterVisibilities(const std::vector<T*>& characters) const;
	/**
	 * ある地点から一定距離内の敵の視界を描画する
	 *
	 * @param position 中心地点
	 * @param distance 距離
	 */
	void drawEnemyVisibilities(const Vector<double>& position, double distance) const;
	/**
	 * 敵の情報を描画する
	 */
	void drawEnemyInformations(void);
	/**
	 * キャラクターを移動させる
	 *
	 * @param characters キャラクターのvector配列
	 */
	template <typename T>
	void moveCharacters(const std::vector<T*> characters);
	/**
	 * 敵をAIに基づいて移動させる
	 */
	void moveEnemiesAI(void);
	/**
	 * Rectangleが敵の視界に入っているか判定する
	 *
	 * @param rectanglePosition Rectangleの位置
	 * @param rectangle Rectangle
	 * @param enemy 敵
	 * @return true : 視界に入っている / false : そうでない
	 */
	bool isFound(const Vector<double>& rectanglePosition, const Utility::Rectangle& rectangle, const Enemy& enemy) const;
	/**
	 * キャラクターが敵の視界に入っているか判定する
	 *
	 * @param character キャラクター
	 * @param enemy 敵
	 * @return true : 視界に入っている / false : そうでない
	 */
	bool isFound(const Character& character, const Enemy& enemy) const;
	/**
	 * 2点がマップ上のブロックで遮られているか判定する
	 *
	 * @param position1 地点1
	 * @param position2 地点2
	 * @return true : 遮られている / false : そうでない
	 */
	bool isBlocked(const Vector<double>& position1, const Vector<double>& position2) const;
	/**
	 * ある点がブロックに当たっているか判定する
	 *
	 * @param position1 ブロックの左下の座標
	 * @param positoin2 対象の点
	 * @return true : 当たっている / false : そうでない
	 */
	bool isHit(const Vector<double>& position1, const Vector<double>& position2) const;
	/**
	 * キャラクター同士の当たり判定
	 *
	 * @param character1 キャラクター
	 * @param character2 キャラクター
	 */
	bool isHit(const Character& character1, const Character& character2) const;
	/**
	 * キャラクター同士の当たり判定
	 *
	 * @param character キャラクター
	 * @param characters キャラクター配列
	 */
	template <typename T>
	bool isHit(const Character& character, const std::vector<T*>& characters) const;
	/**
	 * ある点がマップ上のブロックに当たっているか判定する
	 *
	 * @param position 対象の点
	 * @param isTransparent 透過ブロックの判定に使用する関数のポインタ
	 * @return nullptr : 当たっていない / else : そうでない
	 */
	Block* isHit(const Vector<double>& position, bool (Block::*isTransparent)() const) const;
	/**
	 * ある点がマップ上のブロックに当たっているか判定する
	 *
	 * @param position 対象の点
	 * @param isTransparent 透過ブロックの判定に使用する関数のポインタ
	 * @param blockPosition ブロックの座標
	 * @return nullptr : 当たっていない / else : そうでない
	 */
	Block* isHit(const Vector<double>& position, bool (Block::*isTransparent)() const, Vector<int>& blockPosition) const;
	/**
	 * キャラクターがマップ上のブロックに当たっているか判定する
	 *
	 * @param character キャラクター
	 * @param isTransparent 透過ブロックの判定に使用する関数のポインタ
	 * @return nullptr : 当たっていない / else : そうでない
	 */
	Block* isHit(const Character& character, bool (Block::*isTransparent)() const) const;
	/**
	 * キャラクターがマップ上のブロックに当たっているか判定する
	 *
	 * @param character キャラクター
	 * @param isTransparent 透過ブロックの判定に使用する関数のポインタ
	 * @param position ブロックの位置
	 * @return nullptr : 当たっていない / else : そうでない
	 */
	Block* isHit(const Character& character, bool (Block::*isTransparent)() const, Vector<int>& position) const;
	/**
	 * ブロックを置けるか判定する
	 * プレイヤーや敵がいるかどうかも判定する
	 *
	 * @param position 座標
	 * @return true : 置ける / false : そうでない
	 */
	bool isPlaceable(const Vector<double>& position) const;
	/**
	 * ブロックを置いた場合にキャラクターと当たるか判定する
	 *
	 * @param position 座標
	 * @return true : 置ける / false : そうでない
	 */
	template <typename T>
	bool isPlaceable(const Vector<double>& position, const std::vector<T*>& characters) const;
	/**
	 * キャラクターがマップ上のブロックに当たっているか判定し，当たって入ればCharacter::onHit()イベントを発生させる
	 *
	 * @param characters キャラクター配列
	 * @param isTransparent 透過ブロックの判定に使用する関数のポインタ
	 */
	template <typename T>
	void hitDetectCharacters(const std::vector<T*> characters, bool (Block::*isTransparent)() const);
	void hitDetectInformations(void);
	void hitDetectInformations(std::vector<Information>& informations);
	void hitDetectInformation(Information& information);
	/**
	 * ブロックの破壊を行う
	 */
	void breakBlock(void);
	/**
	 * ブロックの破壊を行う
	 *
	 * @param characters キャラクター配列
	 */
	template <typename T>
	void breakBlock(const std::vector<T*> characters);
	/**
	 * ブロックの設置を行う
	 */
	void placeBlock(const std::vector<Player*> players);

	/**
	 * キャラクターを配置可能な座標のリストを取得する
	 *
	 * @return キャラクターを配置可能な座標のリスト
	 */
	std::vector<Vector<int>> getTransparentBlockVectors(void) const;
	/**
	 * ブロックサイズをマップ上のブロックやプレイヤー・敵に反映させる
	 * 画面幅の変更時などに呼び出す
	 */
	void setBlockSize(void);
	/**
	 * 既に押されているキーのキー配列を検索する
	 *
	 * @param key キー
	 * @return イテレータ : 見つかったキーのイテレータ / list<Key>::iterator.end() : 見つからなかった
	 */
	std::list<Key>::iterator searchKey(const Key& key);
	/**
	 * Characterの移動イベントを発生させる
	 * EnemyのAIイベントを発生させる
	 */
	void moveEvent(void);
	/**
	 * Characterの当たり判定を行う
	 */
	void hitEvent(void);
	/**
	 * キャラクターが敵の視界に入ったときのイベントを発生させる
	 */
	template <typename T>
	void findCharacterEvent(const std::vector<T*>& characters);
	/**
	 * ブロックが敵の視界に入ったときのイベントを発生させる
	 */
	void findBlockEvent(void);
	/**
	 * ブロックを破壊したときのイベントを発生させる
	 */
	void breakBlockEvent(void);
	/**
	 * ブロックを設置したときのイベントを発生させる
	 */
	void placeBlockEvent(void);
	template <typename T>
	void killCharacterEvent(std::vector<T*>& characters);
	void spawnEnemyEvent(void);
	/**
	 * キーに対応したプレイヤーのキーイベントを発生させる
	 *
	 * @param key 対象のキー
	 * @param player プレイヤー
	 * @param fundUp upキーイベントプロシージャ
	 * @param fundDown downキーイベントプロシージャ
	 * @param fundLeft leftキーイベントプロシージャ
	 * @param funcRight rightキーイベントプロシージャ
	 * @param funcBreakBlock breakBlockイベントプロシージャ
	 * @param funcPlaceBlock placeBlockイベントプロシージャ
	 * @param funcPlaceTrap placeTrapイベントプロシージャ
	 * @param funcPlaceDecoy placeDecoyイベントプロシージャ
	 */
	void keyEvent(const Key& key, Player& player, void (Player::*funcUp)(), void (Player::*funcDown)(), void (Player::*funcLeft)(), void (Player::*funcRight)(), void (Player::*funcBreakBlock)(), void (Player::*funcPlaceBlock)(), void (Player::*funcPlaceTrap)(), void (Player::*funcPlaceDecoy)());
	/**
	 * キーに対応したプレイヤーのキーイベントを発生させる
	 *
	 * @param key 対象のキー
	 * @param fundUp upキーイベントプロシージャ
	 * @param fundDown downキーイベントプロシージャ
	 * @param fundLeft leftキーイベントプロシージャ
	 * @param funcRight rightキーイベントプロシージャ
	 * @param funcBreakBlock breakBlockイベントプロシージャ
	 * @param funcPlaceBlock placeBlockイベントプロシージャ
	 * @param funcPlaceTrap placeTrapイベントプロシージャ
	 * @param funcPlaceDecoy placeDecoyイベントプロシージャ
	 */
	void keyEvent(const Key& key, void (Player::*funcUp)(), void (Player::*funcDown)(), void (Player::*funcLeft)(), void (Player::*funcRight)(), void (Player::*funcBreakBlock)(), void (Player::*funcPlaceBlock)(), void (Player::*funcPlaceTrap)(), void (Player::*funcPlaceDecoy)());
	/**
	 * キャラクターとの距離を取得する
	 *
	 * @param characters 距離を取得する対象のキャラクター配列
	 * @param position 位置
	 * @return positionと各characterとの距離の2乗を格納するvector配列
	 */
	template <typename T>
	std::vector<double> getDistances(const std::vector<T*>& characters, const Vector<double>& position) const;

public:
	ComponentGame(const Size<double>& size = Size<double>(0.0, 0.0), const std::string& fpath = "");
	~ComponentGame();

	void setSize(const Size<double>& size);

	virtual void init(void);
	virtual void draw(void);
	virtual void mouse(int button, int state, int x, int y);
	virtual void keyboard(unsigned char key, int x, int y);
	virtual void keyboardOnce(unsigned char key, int x, int y);
	virtual void keyboardup(unsigned char key, int x, int y);
	virtual void keyboardupOnce(unsigned char key, int x, int y);
	virtual void special(int key, int x, int y);
	virtual void specialOnce(int key, int x, int y);
	virtual void specialup(int key, int x, int y);
	virtual void specialupOnce(int key, int x, int y);
};

template <typename T>
inline void ComponentGame::drawCharacters(const std::vector<T*> characters) const
{
	double distance = Global::WORLD_WIDTH;
	if (Global::WORLD_HEIGHT > distance)
		distance = Global::WORLD_HEIGHT;
	drawCharacters(characters, Vector<double>(MAP_WIDTH / 2, MAP_HEIGHT / 2), distance);
}

template <typename T>
inline void ComponentGame::drawCharacters(const std::vector<T*> characters, const Vector<double>& position, double distance) const
{
	double blockWidth = blockSize.getWidth();
	double blockHeight = blockSize.getHeight();
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		glPushMatrix();
		T& character = **itr;
		const Vector<double>& characterPosition = character.getPosition();
		Vector<double> displacement = position - characterPosition;
		displacement.setX(displacement.getX() * blockSize.getWidth());
		displacement.setY(displacement.getY() * blockSize.getHeight());
		if (displacement.norm2() > distance * distance)
			continue;
		double x = characterPosition.getX();
		double y = characterPosition.getY();
		glTranslated(x * blockWidth, y * blockHeight, 0.0);
		character.draw();
		glPopMatrix();
	}
}

template <typename T>
void ComponentGame::drawCharacterVisibilities(const std::vector<T*>& characters) const
{
	double blockWidth = blockSize.getWidth();
	double blockHeight = blockSize.getHeight();
	glColor3d(0.0, 1.0, 0.0);
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		Character& character = **itr;
		glPushMatrix();
		const Vector<double>& position = character.getPosition();
		double x = position.getX();
		double y = position.getY();
		glTranslated(x * blockWidth, y * blockHeight, 0.0);
		const Size<double>& size = character.getSize();
		double width = size.getWidth();
		double height = size.getHeight();
		CircularSector circularSector(Vector<double>(width / 2, height / 2), 0.0, 360.0, Global::PLAYER_RADIUS, false);
		circularSector.draw();
		glPopMatrix();
	}
}

template <typename T>
inline void ComponentGame::moveCharacters(const std::vector<T*> characters)
{
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		T& character = **itr;
		character.move();
	}
}

inline bool ComponentGame::isFound(const Character& character, const Enemy& enemy) const
{
	return isFound(character.getPosition(), character, enemy);
}

inline bool ComponentGame::isHit(const Vector<double>& position1, const Vector<double>& position2) const
{
	double bottom = position1.getY();
	double left = position1.getX();
	double top = bottom + 1.0;
	double right = left + 1.0;
	double x = position2.getX();
	double y = position2.getY();

	return (x > left && x < right) && (y > bottom && y < top);
}

inline bool ComponentGame::isHit(const Character& character1, const Character& character2) const
{
	const Vector<double>& position1 = character1.getPosition();
	const Vector<double>& position2 = character2.getPosition();
	if ((position1 - position2).norm2() > 0.5)
		return false;
	return true;
}

template <typename T>
inline bool ComponentGame::isHit(const Character& character, const std::vector<T*>& characters) const
{
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		const T& c = **itr;
		if (isHit(character, c))
			return true;
	}
	return false;
}

inline Block* ComponentGame::isHit(const Vector<double>& position, bool (Block::*isTransparent)() const) const
{
	Vector<int> dummy;
	return isHit(position, isTransparent, dummy);
}

inline Block* ComponentGame::isHit(const Vector<double>& position, bool (Block::*isTransparent)() const, Vector<int>& blockPosition) const
{
	int i = (int)position.getY();
	int j = (int)position.getX();
	if (i < 0 || i >= MAP_HEIGHT)
		return nullptr;
	if (j < 0 || j >= MAP_WIDTH)
		return nullptr;
	Block& block = *map[i][j];
	if (((&block)->*isTransparent)())
		return nullptr;
	blockPosition = Vector<int>(j, i);
	return &block;
}

template <typename T>
inline bool ComponentGame::isPlaceable(const Vector<double>& position, const std::vector<T*>& characters) const
{
	int row = (int)position.getY();
	int col = (int)position.getX();
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		T& character = **itr;
		const Vector<double>& position2 = character.getIsMoving() ? character.getSource() : character.getPosition();
		int row2 = (int)position2.getY();
		int col2 = (int)position2.getX();
		if (row == row2 && col == col2)
			return false;
	}
	return true;
}

template <typename T>
inline void ComponentGame::hitDetectCharacters(const std::vector<T*> characters, bool (Block::*isTransparent)() const)
{
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		T& character = **itr;
		Vector<int> position;
		Block* block = isHit(character, &Block::isTransparent, position);
		if (block != nullptr)
			block->onHit(character, position);
		if (isHit(character, isTransparent) != nullptr)
			character.onHit();
	}
}

template <typename T>
inline void ComponentGame::breakBlock(const std::vector<T*> characters)
{
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		T& character = **itr;
		if (character.getIsMoving()) {
			character.setIsBreaking(false);
			continue;
		}
		if (!character.getIsBreaking())
			continue;
		character.setIsBreaking(false);
		const Vector<double>& directionVector = character.getDirectionVector();
		const Vector<double>& position = character.getPosition();
		Vector<double> destination = position + directionVector;
		int row = (int)destination.getY();
		int col = (int)destination.getX();
		if (row < 0 || row >= MAP_HEIGHT || col < 0 || col >= MAP_WIDTH)
			continue;
		const Block& block = *map[row][col];
		if (block.isTransparent())
			continue;
		if (!block.isBreakable())
			continue;
		//delete map[row][col];
		itemBlocks.push_back(new ItemBlock(Vector<double>(col, row), map[row][col]));
		map[row][col] = map[row][col]->brokenBlock();
		Vector<int> nodePosition(col, row);
		regionSet += nodePosition;
		//test code
		cout << "num of regions : " << regionSet.getRegionNum() << endl;
		audio.play();
	}
}

template <typename T>
inline void ComponentGame::findCharacterEvent(const std::vector<T*>& characters)
{
	for (auto itr1 = characters.begin(); itr1 != characters.end(); ++itr1) {
		Character& character = **itr1;
		for (auto itr2 = enemies.begin(); itr2 != enemies.end(); ++itr2) {
			Enemy& enemy = **itr2;
			if (isFound(character, enemy))
				enemy.onFindDirect(character);
		}
	}
}

template <typename T>
inline void ComponentGame::killCharacterEvent(std::vector<T*>& characters)
{
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		const T& character = **itr;
		if (isHit(character, enemies)) {
			delete *itr;
			itr = characters.erase(itr);
		}
		if (itr == characters.end())
			break;
	}
}

template <typename T>
inline std::vector<double> ComponentGame::getDistances(const std::vector<T*>& characters, const Vector<double>& position) const
{
	std::vector<double> distances;
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		Character& character = **itr;
		const Vector<double>& characterPosition = character.getPosition();
		double distance = (characterPosition - position).norm2();
		distances.push_back(distance);
	}
	return distances;
}

#endif

