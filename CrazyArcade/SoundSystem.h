#pragma once
class SoundSystem final
{
public:
	SoundSystem();
	SoundSystem(const string& soundFilePath, bool loop = false);
	SoundSystem(const SoundSystem&) = delete;
	SoundSystem& operator=(const SoundSystem&) = delete;
	~SoundSystem();

private:
	string filePath{};

	Sound* sound = nullptr;
	SoundBuffer* soundBuffer = nullptr;

	map<string, Sound*> bgmusic;
	map<string, SoundBuffer*> bgmusicBuffer;

	float volume = 20.f;
	bool loop = false;

	map<string, Sound*> soundEffect;
	map<string, SoundBuffer*> soundEffectBuffer;

	float effectVolume = 20.f;
	const float volumeDistance = 5.f;

private:
	void Init();

public:
	void Destroy();

	void AddMusic(const string& musicFilePath, const string& musicName, bool loop = false);
	void MusicPlay(const string& musicName);
	void MusicStop(const string& musicName);

	void AddSoundEffect(const string& soundFilePath, const string& effectName);
	void EffectPlay(const string& effectName);

	void volDown();
	void volUp();

	void effectVolDown();
	void effectVolUp();

	void Play();
	void Pause();
	void Stop();
};

