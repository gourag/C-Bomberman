#include <fstream>
#include <iostream>
#include "Audio.hh"

Audio::Audio(const std::string &folder)
{
	FMOD::System_Create(&_sys);
	_sys->init(32, FMOD_INIT_NORMAL, 0);
	_mute = false;
	_volume = 1.0;
	_paused = false;
	_mode = Background;
	_folder = folder;
}
Audio::~Audio()
{
	_sys->close();
}
void	Audio::setName(const std::string &name)
{
  _name = name;
}
const std::string	&Audio::getName() const
{
  return _name;
}
void	Audio::setMode(Audio::Mode mode)
{
	_mode = mode;
}
bool	Audio::pause()
{
	_paused = !_paused;
	_channel->setPaused(_paused);
	return true;
}
bool	Audio::setVolume(float num)
{
	_volume = num;
	_channel->setVolume(num);
	return true;
}
bool	Audio::load(const std::string &file)
{
	std::ifstream	f;
	std::string		str = _folder + file;

	f.open(str.c_str());
	if (f.good())
	{
		_file = file;
		return true;
	}
	else
	{
		f.close();
		return false;
	}
}
bool	Audio::play()
{
	std::string		str = _folder + _file;
	if (_mode == Audio::Background)
	  {
		_sys->createStream(str.c_str(), FMOD_HARDWARE, 0, &_sound);
		_sound->setMode(FMOD_LOOP_NORMAL);
	  }
	else
	  {
		_sys->createSound(str.c_str(), FMOD_HARDWARE, 0, &_sound);
		_sound->setMode(FMOD_LOOP_OFF);
	  }
	_sys->getChannel(1, &_channel);
	_sys->playSound(FMOD_CHANNEL_FREE, _sound, true, &_channel);
	_channel->setVolume(_volume);
	_channel->setPaused(false);
	return true;
}
bool	Audio::mute()
{
	_mute = !_mute;
	_channel->setMute(_mute);
	return true;
}
