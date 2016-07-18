#ifndef ___Class_Image
#define ___Class_Image

#include <vector>
#include <string>

/**
 * 画像クラス
 */
class Image {
public:
	class FileCannotOpenException{};	//ファイルを開けなかった
	class InvalidFileException{};		//未対応のファイルを開いた
	class CannotAllocateException{};	//メモリ確保ができなかった

private:
	//読み込みバッファサイズ
	const int BUF_SIZE = 256;

private:
	//画像の幅，高さ
	int width;
	int height;
	//画像データ
	unsigned char* data;

private:
	/**
	 * width,heightの値に基づいて，画像データ領域を確保する
	 *
	 * @throws CannotAllocateException 領域の確保に失敗した場合
	 */
	void allocate(void);
	/**
	 * 文字列をスペースで区切って返す
	 *
	 * @param str 文字列
	 */
	std::vector<std::string> getTokens(const std::string str) const;

public:
	/**
	 * デフォルトコンストラクタ
	 * dataがnullptrであることのみを保証する
	 */
	Image();
	/**
	 * コンストラクタ
	 *
	 * @param fpath 画像ファイルのパス
	 * @throws FileCannotOpenException ファイルが開けなかった場合
	 * @throws InvalidFileException 画像のフォーマットが対応していなかった場合
	 * @throws CannotAllocateException メモリ確保ができなかった場合
	 */
	Image(const std::string& fpath);
	/**
	 * コンストラクタ
	 *
	 * @param image 画像
	 * @throws CannotAllocateException メモリ確保ができなかった場合
	 */
	Image(const Image& image);
	/**
	 * デストラクタ
	 */
	~Image();
	/**
	 * バイナリPPMファイルを読み込む
	 *
	 * @param fpath 画像ファイルのパス
	 * @throws FileCannotOpenException ファイルが開けなかった場合
	 * @throws InvalidFileException 画像のフォーマットが対応していなかった場合
	 * @throws CannotAllocateException メモリ確保ができなかった場合
	 */
	void readPPM(const std::string& fpath);
	/**
	 * バイナリPPMファイルを書き込む
	 *
	 * @param fpath 画像ファイルのパス
	 * @throws FileCannotOpenException ファイルが開けなかった場合
	 */
	void writePPM(const std::string& fpath);
	/**
	 * ゲッター及びセッター
	 */
	int getWidth(void) const;
	int getHeight(void) const;
	const unsigned char* getData(void) const;
	void setWidth(int width);
	void setHeight(int height);
};

inline int Image::getWidth(void) const 
{
	return width;
}

inline int Image::getHeight(void) const
{
	return height;
}

inline const unsigned char* Image::getData(void) const
{
	return data;
}

inline void Image::setWidth(int width)
{
	this->width = width;
}

inline void Image::setHeight(int height)
{
	this->height = height;
}

#endif

