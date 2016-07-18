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
#include "Size.hpp"
#include "ItemBlock.hpp"

#include "GL/glut.h"

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
	std::vector<Enemy*> enemies;	//敵
	std::vector<ItemBlock*> itemBlocks;	//アイテム
	Size<double> blockSize;			//ブロックの大きさ

private:
	/**
	 * マップの配列を生成する
	 * ただし，ブロックのインスタンス生成は行わない
	 */
	void allocMap(void);
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
	 */
	void deleteMap(void);
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
	 * 敵を全員解放する
	 */
	void deleteEnemies(void);
	/**
	 * キャラクターを描画する
	 *
	 * @param characters キャラクターのvector配列
	 */
	template <typename T>
	void drawCharacters(const std::vector<T*> characters) const;
	/**
	 * アイテムを描画する
	 */
	void drawItemBlocks(void);
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
	 * プレイヤーが敵の視界に入っているか判定する
	 *
	 * @param player プレイヤー
	 * @param enemy 敵
	 * @return true : 視界に入っている / false : そうでない
	 */
	bool isFound(const Player& player, const Enemy& enemy) const;
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
	 * ある点がマップ上のブロックに当たっているか判定する
	 *
	 * @param position 対象の点
	 * @param isTransparent 透過ブロックの判定に使用する関数のポインタ
	 * @return true : 当たっている / false : そうでない
	 */
	bool isHit(const Vector<double>& position, bool (Block::*isTransparent)() const) const;
	/**
	 * キャラクターがマップ上のブロックに当たっているか判定する
	 *
	 * @param character キャラクター
	 * @param isTransparent 透過ブロックの判定に使用する関数のポインタ
	 * @return true : 当たっている / false : そうでない
	 */
	bool isHit(const Character& character, bool (Block::*isTransparent)() const) const;
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
	/**
	 * ブロックの破壊を行う
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
	 * プレイヤーが敵の視界に入ったときのイベントを発生させる
	 */
	void findPlayerEvent(void);
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

public:
	ComponentGame();
	ComponentGame(int width, int height);
	~ComponentGame();

	void setWidth(int width);
	void setHeight(int height);

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
	double blockWidth = blockSize.getWidth();
	double blockHeight = blockSize.getHeight();
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		glPushMatrix();
		T& character = **itr;
		Vector<double> position = character.getPosition();
		double x = position.getX();
		double y = position.getY();
		glTranslated(x * blockWidth, y * blockHeight, 0.0);
		character.draw();
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

template <typename T>
inline bool ComponentGame::isPlaceable(const Vector<double>& position, const std::vector<T*>& characters) const
{
	int row = position.getY();
	int col = position.getX();
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		T& character = **itr;
		Vector<double> position2 = character.getPosition();
		if (character.getIsMoving())
			position2 = character.getSource();
		int row2 = position2.getY();
		int col2 = position2.getX();
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
		if (isHit(character, isTransparent))
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
		Vector<double> directionVector = character.getDirectionVector();
		Vector<double> position = character.getPosition();
		Vector<double> destination = position + directionVector;
		int row = destination.getY();
		int col = destination.getX();
		if (row < 0 || row >= MAP_HEIGHT || col < 0 || col >= MAP_WIDTH)
			continue;
		const Block& block = *map[row][col];
		if (block.isTransparent())
			continue;
		if (!block.isBreakable())
			continue;
		//delete map[row][col];
		itemBlocks.push_back(new ItemBlock(Vector<double>(col, row), map[row][col]));
		map[row][col] = new BlockAir(blockSize);
	}
}

#endif

