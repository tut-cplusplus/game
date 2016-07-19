#ifndef __Class_Enemy
#define __Class_Enemy

#include <vector>

#include "Character.hpp"
#include "Size.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Information.hpp"

class Enemy : public Character {
private:
	double viewAngle;	//見ている方向
	double radius;		//視界の半径
	bool first;			//AIのサンプルに使用．不要であれば消す
	Vector<double> oldTarget;
	Vector<double> newTarget;
	bool onEyes;
	int count;
	bool isFindPlayer;
	bool isLookingPlayer;
	std::vector<Information> informations;	//プレイヤーの伝達情報

protected:
	void loadAnimations(void);

public:

	Enemy();

	Enemy(const Vector<double>& position, const Size<double>& size);
	Enemy(const Vector<double>& position);
	virtual ~Enemy();

	/**
	 * アクセッサ
	 */
	double getViewAngle(void) const;
	double getRadius(void) const;
	std::vector<Information>& getInformations(void);

	/**
	 * 毎フレーム呼び出される
	 * AI関係の処理を記述する
	 */
	void onMoveAI(void);
	/**
	 * 壁に衝突したときに呼び出される
	 * AI関係の処理を記述する
	 */
	void onHit(void);
	/**
	 * プレイヤーを発見したときに呼び出される
	 * 情報伝達オブジェクトのインスタンス化などを行う
	 *
	 * @param player プレイヤー
	 */
	void onFind(const Player& player);
	/**
	 * プレイヤーを始めて発見したときに呼び出される
	 * 一度見失うまでは再び呼び出されない
	 * 情報伝達オブジェクトのインスタンス化などを行う
	 *
	 * @param player プレイヤー
	 */
	void onFindFirst(const Player& player);
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
};

#endif
