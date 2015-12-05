//
// Player.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 13:00:30 2014 jonathan
// Last update Fri May 23 12:58:23 2014 blondeel julien
//

#ifndef _PLAYER_H_
# define _PLAYER_H_

#include "ACharacter.hh"

class Player : public ACharacter
{
private:
  Player(const Player &old);
  Player &operator=(const Player &old);
  int                   _anim;
  int                   _bomb;
  std::vector<AEntity*> _bombs;

public:
  Player(float posX = 0, float posY = 0, float posZ = 0, float rotX = 0, float rotY = 0, float rotZ = 0, float scX = 0.003, float scY = 0.003, float scZ = 0.003);
  virtual ~Player();

  virtual bool	initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void	putBomb(void);
  void  moveUp();
  void  moveDown();
  void  moveRight();
  void  moveLeft();
  void  player_anim();
  bool  addBombs(AEntity *obj);
  void	setPlayer(bool);
};

#endif /* _PLAYER_H_ */
