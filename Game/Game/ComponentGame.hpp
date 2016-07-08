#ifndef ___Class_ComponentGame
#define ___Class_ComponentGame

#include <vector>
#include <random>
#include <list>

#include "Component.hpp"
#include "Block.hpp"
#include "Vector.hpp"
#include "Player.hpp"
#include "NormalEnemy.hpp"
#include "Size.hpp"

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
	Size<double> blockSize;			//ブロックの大きさ
	std::list<Key> keys;			//押されているキー

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
	 * ブロックが敵の視界に入っているか判定する
	 *
	 * @param blockPosition ブロックの位置
	 * @param block ブロック
	 * @param enemy 敵
	 * @return true : 視界に入っている / false : そうでない
	 */
	bool isFound(const Vector<double>& blockPosition, const Block& block, const Enemy& enemy) const;
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
	 * @return true : 当たっている / false : そうでない
	 */
	bool isHit(const Vector<double>& position) const;
	/**
	 * キャラクターがマップ上のブロックに当たっているか判定する
	 *
	 * @param character キャラクター
	 * @return true : 当たっている / false : そうでない
	 */
	bool isHit(const Character& character) const;
	/**
	 * キャラクターがマップ上のブロックに当たっているか判定し，当たって入ればCharacter::onHit()イベントを発生させる
	 *
	 * @param characters キャラクター配列
	 */
	template <typename T>
	void hitDetectCharacters(const std::vector<T*> characters);

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
	 * 押されているキーの配列にキーを追加する
	 *
	 * @param key 追加するキー
	 */
	void addKey(const Key& key);
	/**
	 * 押されているキーの配列からキーを削除する
	 *
	 * @param key 削除するキー
	 */
	void deleteKey(const Key& key);
	/**
	 * プレイヤーのキーイベントを発生させる
	 */
	void keyEvent(void);
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
	virtual void keyboardup(unsigned char key, int x, int y);
	virtual void special(int key, int x, int y);
	virtual void specialup(int key, int x, int y);
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
inline void ComponentGame::hitDetectCharacters(const std::vector<T*> characters)
{
	for (auto itr = characters.begin(); itr != characters.end(); ++itr) {
		T& character = **itr;
		if (isHit(character))
			character.onHit();
	}
}

#endif

