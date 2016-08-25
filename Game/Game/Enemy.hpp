#ifndef __Class_Enemy
#define __Class_Enemy

#include <vector>

#include "Character.hpp"
#include "Size.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Information.hpp"
#include "Route.hpp"
#include "Region.hpp"
#include "RegionSet.hpp"


class Enemy : public Character {
private:
	double viewAngle;	//見ている方向
	double radius;		//視界の半径
	bool first;			//AIのサンプルに使用．不要であれば消す
	std::vector<Information> informations;	//プレイヤーの伝達情報
	int life;			//ブロックを破壊できる回数
	double informationSpeed;	//情報伝達速度
	bool isFindPlayer;	//プレイヤーを発見中かどうか
	bool isLookingPlayer;
	bool isLookingPlayerThisFrame;
	Region region;		//敵が把握しているマップ情報
	Route route;
	Vector<int> playerPosition;
	bool isDestroyBock;

protected:
	void loadAnimations(void);

public:

	Enemy(const Vector<double>& position = Vector<double>(0.0, 0.0), const Size<double>& size = Size<double>(0.0, 0.0), double speed = 1.0, double viewAngle = 45.0, double radius = 100.0, int life = 0, double informationSpeed = 0.0);
	virtual ~Enemy();

	/**
	 * アクセッサ
	 */
	double getViewAngle(void) const;
	double getRadius(void) const;
	std::vector<Information>& getInformations(void);
	int getLife(void) const;
	double getInformationSpeed(void) const;

	void updateRoute(void);
	/**
	 * 毎フレーム呼び出される
	 * AI関係の処理を記述する
	 */
	void onMoveAI();
	/**
	 * 壁に衝突したときに呼び出される
	 * AI関係の処理を記述する
	 */
	void onHit(void);
	/**
	 * プレイヤーを目視で発見したときに呼び出される
	 * 情報伝達オブジェクトのインスタンス化などを行う
	 *
	 * @param character キャラクター
	 */
	void onFindDirect(const Character& character);
	/**
	 * プレイヤーを発見したときに呼び出される
	 * 情報伝達で情報が伝わった場合にも呼び出される
	 *
	 * @param character キャラクター
	 */
	void onFind(const Character& character);
	/**
	 * プレイヤーを始めて発見したときに呼び出される
	 * 一度見失うまでは再び呼び出されない
	 * 情報伝達オブジェクトのインスタンス化などを行う
	 *
	 * @param character キャラクター
	 */
	void onFindFirst(const Character& character);
	/**
	 * ブロックを発見したときに呼び出される
	 * 透過ブロックに対しては呼び出されない
	 * マッピングの処理を記述する
	 *
	 * @param position ブロックの左下の位置（マップ配列におけるインデックス）
	 * @param block ブロック
	 */
	void onFind(const Vector<int>& position, const Block& block);
	/**
	 * 描画色を設定する
	 * テクスチャ実装後に削除される
	 */
	void changeColor(void) const;

	void draw(void);
	/**
	 * 視界の表示
	 */
	void drawVisibility(void) const;
	/**
	 * 情報伝達の表示
	 */
	void drawInformations(void);
	/**
	 * 移動経路の表示
	 */
	void drawRoute(void) const;
	/**
	 * マップの表示
	 */
	void drawRegion(void) const;
	Vector<int> getNearestReachablePosition(void) const;
};

inline double Enemy::getViewAngle(void) const
{
	return viewAngle;
}

inline double Enemy::getRadius(void) const
{
	return radius;
}

inline vector<Information>& Enemy::getInformations(void)
{
	return informations;
}

inline int Enemy::getLife(void) const
{
	return life;
}

inline double Enemy::getInformationSpeed(void) const
{
	return informationSpeed;
}

#endif
