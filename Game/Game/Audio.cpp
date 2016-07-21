#include "Audio.hpp"
#include <AL/alut.h>


Audio::Audio()
{
}

Audio::Audio(string const &file_path):buffer(alutCreateBufferHelloWorld()), source(0) {
	alGenSources(1, &source);
	alSourcei(source, AL_BUFFER, buffer);
}


Audio::~Audio() {
}

void Audio::play()
{
	alSourcePlay(source);
}

void Audio::pause()
{
}

void Audio::stop()
{
	alSourceStop(source);
}

const bool Audio::isPlaying()
{
	return getOffset() != 0;
}

const float Audio::getDuration()
{
	ALint size, frequency, channels, bits;

	alGetBufferi(buffer, AL_SIZE, &size);
	alGetBufferi(buffer, AL_FREQUENCY, &frequency);
	alGetBufferi(buffer, AL_CHANNELS, &channels);
	alGetBufferi(buffer, AL_BITS, &bits);

	return static_cast<float>(size)/static_cast<float>(frequency*channels*(bits/8));
}

const float Audio::getOffset()
{
	float offset;
	alGetSourcef(source, AL_SEC_OFFSET, &offset);
	return offset;
}
