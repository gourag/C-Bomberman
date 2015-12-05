//
// Bomb.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 14:41:14 2014 jonathan
// Last update Mon May 12 15:15:15 2014 jonathan
//

#ifndef _BOMB_H_
# define _BOMB_H_

#include <vector>
#include "AObject.hh"
#include "Audio.hh"

class ABomb : public AObject
{
protected:
  std::vector<Audio *>	_sounds;

public:
  ABomb();
  // Bomb(const Bomb &old);
  // Bomb operator=(const Bomb &old);
  virtual ~ABomb();

  virtual bool	initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);

  virtual void	doPrimaryAction();
  virtual void	doSound(const std::string &sound) const;
};


#endif /* _BOMB_H_ */
