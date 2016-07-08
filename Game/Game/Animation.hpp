#ifndef ___Class_Animation
#define ___Class_Animation

#include <string>

#include "Rectangle.hpp"

#include "GL/glut.h"

class Animation : public Rectangle {
public:
	class FileCannotOpenException {};

private:
	bool isPlaying;
	bool isLoop;
	int rows;
	int cols;
	int fps;
	int cnt;
	GLuint ID;

public:
	Animation(const std::string& fpath, const Size<double>& size = Size<double>(0.0, 0.0));

	void draw(void);
	void update(void);
	void start(void);
	void stop(void);
	void setLoop(bool isLoop);

	bool getIsPlaying(void) const;
	bool getIsLoop(void) const;
};

inline void Animation::start(void)
{
	isPlaying = true;
}

inline void Animation::stop(void)
{
	isPlaying = false;
}

inline void Animation::setLoop(bool isLoop)
{
	this->isLoop = isLoop;
}

inline bool Animation::getIsPlaying(void) const
{
	return isPlaying;
}

inline bool Animation::getIsLoop(void) const
{
	return isLoop;
}

#endif

