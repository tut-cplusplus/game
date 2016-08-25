#include <AL/alut.h>
#include "AudioManager.hpp"

using namespace std;

const int AudioManager::MAX_AUDIO = 30;
ALuint AudioManager::IDs[MAX_AUDIO];
unsigned AudioManager::num = 0;
std::vector<std::string> AudioManager::paths;
std::vector<ALuint> AudioManager::buffers;

void AudioManager::init(void)
{
	alGenSources(MAX_AUDIO, IDs);
}

ALuint AudioManager::registerAudio(const std::string & path)
{
	for (unsigned i = 0; i < num; i++) {
		if (paths[i] == path)
			return IDs[i];
	}
	if (num == MAX_AUDIO)
		throw NotEnoughIDsException();
	try {
		buffers.push_back(alutCreateBufferFromFile(path.c_str()));
	}
	catch (...) {
		throw CannotRegisterException();
	}
	paths.push_back(path);
	ALuint buffer = buffers[num];
	ALuint ID = IDs[num];
	num++;

	alSourcei(ID, AL_BUFFER, buffer);
	return ID;
}

void AudioManager::play(ALuint id)
{
	alSourcePlay(id);
}

void AudioManager::play(const string& path)
{
	ALuint id = registerAudio(path);
	play(id);
}

void AudioManager::stop(ALuint id)
{
}

void AudioManager::setLoop(ALuint id, ALint is_loop)
{
	alSourcei(id, AL_LOOPING, is_loop);
}
