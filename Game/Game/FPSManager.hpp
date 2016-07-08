#ifndef ___Class_FPSManager
#define ___Class_FPSManager

class FPSManager {
private:
	static double start;
	static double startTmp;
	static double end;

	static int count;
	static double nowFps;
	static int numberOfSample; //サンプリング回数
	static double setFps;	//目標とするFPS
	static double processTime;	//処理時間
	static double processTimeSum;	//処理時間の合計
	static double utilization; //負荷率

private:
	static double getTime(void);
	static void sleep(double seconds);

public:
	/**
	 * 計測を始める
	 */
	static void startMeasure(void);
	/**
	 * 計測を終わる
	 */
	static void stopMeasure(void);
	/**
	 * FPSを更新する
	 * 毎フレーム呼び出す
	 */
	static void update(void);
	static void sleep(void);
	/**
	 * FPSを取得する
	 *
	 * @return FPS
	 */
	static double getFPS(void);
	/**
	 * 負荷率を取得する
	 *
	 * @return 負荷率
	 */
	static double getUtilization(void);
};

#endif

