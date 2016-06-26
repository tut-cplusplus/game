#ifndef ___Class_Image
#define ___Class_Image

#include <string>

/**
 * $B2hA|%/%i%9(B
 */
class Image {
public:
	class FileCannotOpenException{};	//$B%U%!%$%k$r3+$1$J$+$C$?(B
	class InvalidFileException{};		//$BL$BP1~$N%U%!%$%k$r3+$$$?(B
	class CannotAllocateException{};	//$B%a%b%j3NJ]$,$G$-$J$+$C$?(B

private:
	//$BFI$_9~$_%P%C%U%!%5%$%:(B
	const int BUF_SIZE = 256;

private:
	//$B2hA|$NI}!$9b$5(B
	int width;
	int height;
	//$B2hA|%G!<%?(B
	unsigned char* data;

private:
	/**
	 * width,height$B$NCM$K4p$E$$$F!$2hA|%G!<%?NN0h$r3NJ]$9$k(B
	 *
	 * @throws CannotAllocateException $BNN0h$N3NJ]$K<:GT$7$?>l9g(B
	 */
	void allocate(void);

public:
	/**
	 * $B%G%U%)%k%H%3%s%9%H%i%/%?(B
	 * data$B$,(Bnullptr$B$G$"$k$3$H$N$_$rJ]>Z$9$k(B
	 */
	Image();
	/**
	 * $B%3%s%9%H%i%/%?(B
	 *
	 * @param fpath $B2hA|%U%!%$%k$N%Q%9(B
	 * @throws FileCannotOpenException $B%U%!%$%k$,3+$1$J$+$C$?>l9g(B
	 * @throws InvalidFileException $B2hA|$N%U%)!<%^%C%H$,BP1~$7$F$$$J$+$C$?>l9g(B
	 * @throws CannotAllocateException $B%a%b%j3NJ]$,$G$-$J$+$C$?>l9g(B
	 */
	Image(const std::string& fpath);
	/**
	 * $B%3%s%9%H%i%/%?(B
	 *
	 * @param image $B2hA|(B
	 * @throws CannotAllocateException $B%a%b%j3NJ]$,$G$-$J$+$C$?>l9g(B
	 */
	Image(const Image& image);
	/**
	 * $B%G%9%H%i%/%?(B
	 */
	~Image();
	/**
	 * $B%P%$%J%j(BPPM$B%U%!%$%k$rFI$_9~$`(B
	 *
	 * @param fpath $B2hA|%U%!%$%k$N%Q%9(B
	 * @throws FileCannotOpenException $B%U%!%$%k$,3+$1$J$+$C$?>l9g(B
	 * @throws InvalidFileException $B2hA|$N%U%)!<%^%C%H$,BP1~$7$F$$$J$+$C$?>l9g(B
	 * @throws CannotAllocateException $B%a%b%j3NJ]$,$G$-$J$+$C$?>l9g(B
	 */
	void readPPM(const std::string& fpath);
	/**
	 * $B%P%$%J%j(BPPM$B%U%!%$%k$r=q$-9~$`(B
	 *
	 * @param fpath $B2hA|%U%!%$%k$N%Q%9(B
	 * @throws FileCannotOpenException $B%U%!%$%k$,3+$1$J$+$C$?>l9g(B
	 */
	void writePPM(const std::string& fpath);
	/**
	 * $B%2%C%?!<5Z$S%;%C%?!<(B
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

