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

