#include <string>
#include "fmod.hpp"

class Audio
{
public:
  enum	Mode
    {
      Background = 0,
      Effect = 1
    };

private:
  Audio(const Audio &);
  Audio &operator=(const Audio &);

private:
  FMOD::System	*_sys;
  FMOD::Sound	*_sound;
  FMOD::Channel	*_channel;

  std::string		_file;
  std::string		_name;
  std::string		_folder;
  float			_volume;
  bool 			_mute;
  bool			_paused;
  Mode			_mode;

public:
  Audio(const std::string &);
  virtual ~Audio();

  const std::string	&getName() const;
  void			setName(const std::string &);
  bool	play();
  bool	playNextSong();
  bool	playPrevSong();
  bool	mute();
  bool	pause();
  void	setMode(Mode);
  bool	setVolume(float);
  bool	load(const std::string &);
};
