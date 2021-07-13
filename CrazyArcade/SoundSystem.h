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

	float volume = 10.f;
	bool loop = false;

private:
	void Init();

public:
	void Play();
	void Pause();
	void Stop();
};

