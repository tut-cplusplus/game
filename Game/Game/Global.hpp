#ifndef ___Class_Global
#define ___Class_Global

class Global
{
public:
	static const int WINDOW_WIDTH;		//ウィンドウの幅
	static const int WINDOW_HEIGHT;		//ウィンドウの高さ
	static const int WORLD_WIDTH;			//描画系の幅
	static const int WORLD_HEIGHT;		//描画系の高さ
	static const unsigned KILL_ENEMY_THRESHOLD;	//敵を倒せる空間の最大サイズ
	static const int PLAYER_DEFAULT_RADIUS;
	static double PLAYER_RADIUS;	//プレイヤーの視界の半径
};

#endif

