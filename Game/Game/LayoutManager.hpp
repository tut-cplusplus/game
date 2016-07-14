#ifndef ___Class_LayoutManager
#define ___Class_LayoutManager

#include <vector>

#include "Layout.hpp"
#include "Vector.hpp"

/**
 * レイアウトマネージャ
 * ゲーム画面の管理に使用する．
 */
class LayoutManager {
private:
	static Layout* layout;	/* メインレイアウト */
	static std::vector<unsigned char> keys;
	static std::vector<int> specialKeys;
	static std::vector<Vector<int>> keyPositions;
	static std::vector<Vector<int>> specialKeyPositions;

private:
	template <typename T>
	static bool searchKey(const std::vector<T>& keys, T key);
	template <typename T>
	static void deleteKey(std::vector<T>& keys, std::vector<Vector<int>>& keyPositions, T key);
	static void keyEvent(void);
	template <typename T>
	static void keyEvent(const std::vector<T>& keys, const std::vector<Vector<int>>& keyPositions, void (Layout::*func)(T, int, int), void (Layout::*funcup)(T, int, int));

public:
	/**
	 * メインレイアウトを取得する
	 *
	 * @return メインレイアウト
	 */
	static Layout* getLayout(void);
	/**
	 * メインレイアウトを登録する
	 *
	 * @param _layout レイアウト
	 */
	static void registerLayout(Layout* _layout);
	/**
	 * GLUTのイベントに対応する関数
	 */
	static void draw(void);
	static void mouse(int button, int state, int x, int y);
	static void keyboard(unsigned char key, int x, int y);
	static void keyboardup(unsigned char key, int x, int y);
	static void special(int key, int x, int y);
	static void specialup(int key, int x, int y);
};

template <typename T>
bool LayoutManager::searchKey(const std::vector<T>& keys, T key)
{
	for (auto itr = keys.begin(); itr != keys.end(); ++itr) {
		T key1 = *itr;
		if (key1 == key)
			return true;
	}
	return false;
}

template <typename T>
void LayoutManager::deleteKey(std::vector<T>& keys, std::vector<Vector<int>>& keyPositions, T key)
{
	auto itr1 = keyPositions.begin();
	for (auto itr = keys.begin(); itr != keys.end(); ++itr, ++itr1) {
		T key1 = *itr;
		if (key1 == key) {
			itr = keys.erase(itr);
			itr1 = keyPositions.erase(itr1);
			if (itr == keys.end())
				return;
		}
	}
}

template <typename T>
void LayoutManager::keyEvent(const std::vector<T>& keys, const std::vector<Vector<int>>& keyPositions, void (Layout::*func)(T, int, int), void (Layout::*funcup)(T, int, int))
{
	auto itr1 = keyPositions.begin();
	for (auto itr = keys.begin(); itr != keys.end(); ++itr, ++itr1) {
		T key = *itr;
		const Vector<int>& keyPosition = *itr1;
		(layout->*funcup)(key, keyPosition.getX(), keyPosition.getY());
		(layout->*func)(key, keyPosition.getX(), keyPosition.getY());
	}
}

#endif

