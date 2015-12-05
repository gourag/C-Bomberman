//
// Character.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 11:35:30 2014 jonathan
// Last update Fri May 23 10:19:00 2014 jonathan
//

#ifndef _CHARACTER_H_
# define _CHARACTER_H_

#include "AEntity.hh"

class ACharacter : public AEntity
{
public:
  enum	Type
    {
      IAType,
      HumanType
    };

protected:
  float		_speed;
  int		_bomb;
  Type		_type;

public:
  ACharacter(float posX = 0, float posY = 0, float posZ = 0, float rotX = 0, float rotY = 0, float rotZ = 0, float scX = 0.1, float scY = 0.1, float scZ = 0.1);
  ACharacter(const ACharacter &old);
  ACharacter &operator=(const ACharacter &old);
  virtual ~ACharacter();

  /* Methodes inheritated from AObject */
  virtual bool	initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);

  /* Methode specific to Character */
  virtual void	setSpeed(float speed);
  virtual void	setLife(bool positive);
  virtual void	setBomb(int num);

  virtual float	getSpeed(void) const;
  virtual int	getBomb(void) const;
  virtual int	getLife() const;

  virtual void	putBomb(void) = 0;

  virtual void	doPrimaryAction();
  virtual void	doSound(const std::string &) const;
};


#endif /* _CHARACTER_H_ */
