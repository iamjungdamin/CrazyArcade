#include "framework.h"
#include "SoundSystem.h"

SoundSystem::SoundSystem()
{
	Init();
}

SoundSystem::SoundSystem(const string& soundFilePath, bool loop)
	:filePath(soundFilePath), loop(loop)
{
	Init();
}

SoundSystem::~SoundSystem()
{
}

void SoundSystem::Init()
{
	sound = new Sound;
	soundBuffer = new SoundBuffer;

	if (!soundBuffer->loadFromFile(filePath))
	{
		cout << " not load sound - " << filePath << endl;
	}
	sound->setBuffer(*soundBuffer);
	sound->setVolume(this->volume);
	sound->setLoop(this->loop);
}

void SoundSystem::Play()
{
	sound->play();
}

void SoundSystem::Pause()
{
	sound->pause();
}

void SoundSystem::Stop()
{
	sound->stop();
}
