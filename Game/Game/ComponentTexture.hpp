#ifndef ___Class_ComponentTexture
#define ___Class_ComponentTexture

#include "Component.hpp"
#include "TextureManager.hpp"

/**
 * テクスチャコンポーネントクラス
 * テクスチャのサンプルとして使ってください
 */
class ComponentTexture : public Component {
private:
	GLuint ID;

public:
	ComponentTexture();
	/**
	 * コンストラクタ
	 *
	 * @param width コンポーネントの幅
	 * @param height コンポーネントの高さ
	 * @param path 画像ファイルのパス
	 * @throws TextureManager::registerTexture()を参照
	 */
	ComponentTexture(int width, int height, const std::string& path);

	virtual void draw(void);
};

#endif

