//
// Case.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Mon May 12 16:41:51 2014 jonathan
// Last update Tue May 13 10:33:10 2014 jonathan
//

#ifndef _CASE_H_
# define _CASE_H_

#include "AEntity.hh"

class Case
{
public:
  enum	EntityType
    {
      Box,
      Wall,
      Ennemy,
      Player
    };

private:
  int		_posX;
  int		_posY;
  EntityType	_entityType;
  bool		_isDestructible;
  AEntity	*_entity;

public:
  Case(EntityType, int, int);
  Case(const Case &old);
  Case &operator=(const Case &old);
  virtual ~Case();

  int		getPosX(void) const;
  int		getPosY(void) const;
  EntityType	getEntityType(void) const;
  bool		initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);

  bool	isDestructible();
};


#endif /* _CASE_H_ */
