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
	 * @param size コンポーネントの大きさ
	 * @param path 画像ファイルのパス
	 * @throws TextureManager::registerTexture()を参照
	 */
	ComponentTexture(const Size<double>& size, const std::string& path);

	virtual void draw(void);
};

#endif

