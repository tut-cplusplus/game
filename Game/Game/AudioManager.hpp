#pragma once
#ifndef ___Class_AudioManager
#define ___Class_AudioManager
#include <vector>
#include <string>

#include <AL/al.h>

/**
* オーディオマネージャクラス
* 音声の管理をする
*/
class AudioManager
{
public:
	class CannotRegisterException {};	/* 音声を追加出来なかった */
	class NotEnoughIDsException {};	/* ID空間が足りない */
private:
	static const int MAX_AUDIO;
	static ALuint IDs[];
	static unsigned num;
	static std::vector<std::string> paths;
	static std::vector<ALuint> buffers;

public:
	/**
	* 初期化を行う
	* glutMainLoop()の直前に必ず呼び出す
	*/
	static void init(void);
	/**
	* 音源を登録する
	*
	* @param path 音声ファイルのパス
	* @return 音声ID
	* @throws NotEnoughIDsException：IDが枯渇している場合
	* @throws CannotRegisterException 
	*/
	static ALuint registerAudio(const std::string& path);
	static void play(ALuint id);
	static void play(const std::string& path);
	static void stop(ALuint id);
	static void setLoop(ALuint id, ALint is_loop);
};

#endif
