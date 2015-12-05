//
// Bomb.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 14:41:14 2014 jonathan
// Last update Thu May 22 13:09:52 2014 blondeel julien
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
  ABomb(float posX = 0, float posY = 0, float posZ = 0, float rotX = 0, float rotY = 0, float rotZ = 0, float scX = 0.5, float scY = 0.5, float scZ = 0.5);
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
