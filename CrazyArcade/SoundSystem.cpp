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
	//sound->play();
}

void SoundSystem::Destroy()
{
	DELETE(soundBuffer);
	DELETE(sound);

	for (auto& b : bgmusic)
	{
		DELETE(b.second);
	}
	bgmusic.clear();

	for (auto& bb : bgmusicBuffer)
	{
		DELETE(bb.second);
	}
	bgmusicBuffer.clear();

	for (auto& s : soundEffect)
	{
		DELETE(s.second);
	}
	soundEffect.clear();

	for (auto& sb : soundEffectBuffer)
	{
		DELETE(sb.second);
	}
	soundEffectBuffer.clear();
}

void SoundSystem::AddMusic(const string& musicFilePath, const string& musicName, bool loop)
{
	bgmusic[musicName] = new Sound;
	bgmusicBuffer[musicName] = new SoundBuffer;

	if (!bgmusicBuffer[musicName]->loadFromFile(musicFilePath))
	{
		cout << " not load sound - " << musicFilePath << endl;
	}
	bgmusic[musicName]->setBuffer(*bgmusicBuffer[musicName]);
	bgmusic[musicName]->setVolume(volume);
	bgmusic[musicName]->setLoop(loop);
}

void SoundSystem::MusicPlay(const string& musicName)
{
	bgmusic[musicName]->play();
}

void SoundSystem::MusicStop(const string& musicName)
{
	bgmusic[musicName]->stop();
}

void SoundSystem::AddSoundEffect(const string& soundFilePath, const string& effectName)
{
	soundEffect[effectName] = new Sound;
	soundEffectBuffer[effectName] = new SoundBuffer;

	if (!soundEffectBuffer[effectName]->loadFromFile(soundFilePath))
	{
		cout << " not load sound - " << soundFilePath << endl;
	}
	soundEffect[effectName]->setBuffer(*soundEffectBuffer[effectName]);
	soundEffect[effectName]->setVolume(effectVolume);
	soundEffect[effectName]->setLoop(false);
}

void SoundSystem::EffectPlay(const string& effectName)
{
	soundEffect[effectName]->play();
}

void SoundSystem::volDown()
{
	if (volume > 5.f)
	{
		volume -= this->volumeDistance;
		sound->setVolume(volume);
		cout << "volume: " << volume << endl;
	}
}

void SoundSystem::volUp()
{
	if (volume < 100.f)
	{
		volume += this->volumeDistance;
		sound->setVolume(volume);
		cout << "volume: " << volume << endl;
	}
}

void SoundSystem::effectVolDown()
{
	if (effectVolume < 5.f)
	{
		for (auto& s : soundEffect)
		{
			effectVolume -= volumeDistance;
			s.second->setVolume(effectVolume);
		}
	}
}

void SoundSystem::effectVolUp()
{
	if (effectVolume < 100.f)
	{
		for (auto& s : soundEffect)
		{
			effectVolume += volumeDistance;
			s.second->setVolume(effectVolume);
		}
	}
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
