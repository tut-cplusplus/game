#pragma once
#include <string>
#include <AL/al.h>
using std::string;
class Audio
{
public:
	Audio();
	Audio(string const &file_path);
	~Audio();
	void play();
	void pause();
	void stop();
	const bool isPlaying();
	const float getDuration();
	const float getOffset();
private:
	ALuint buffer;
	ALuint source;
};

