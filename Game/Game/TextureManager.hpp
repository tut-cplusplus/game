#ifndef ___Class_TextureManager
#define ___Class_TextureManager

#include <vector>
#include <string>

#include "GL/glut.h"

#include "Image.hpp"

/**
 * テクスチャマネージャクラス
 * テクスチャの管理をする
 */
class TextureManager {
public:
	class CannotRegisterException{};	/* テクスチャを登録できなかった */
	class NotEnoughIDsException{};	/* ID空間が足りない */

private:
	static const int MAX_TEXTURE;
	static GLuint IDs[];
	static unsigned num;
	static std::vector<std::string> paths;
	static std::vector<Image> images;

public:
	/**
	 * テクスチャマネージャの初期化を行う
	 * glutMainLoop()の直前に必ず呼び出す
	 */
	static void init(void);	
	/**
	 * テクスチャを登録する
	 *
	 * @param path 画像ファイルのパス
	 * @return テクスチャID
	 * @throws NotEnoughIDsException テクスチャIDが枯渇している場合
	 * @throws CannotRegisterException 画像の読み込みができなかった場合
	 */
	static GLuint registerTexture(const std::string& path);
};

#endif

