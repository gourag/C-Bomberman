//
// Ennemy.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Character
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Fri May  9 13:38:22 2014 jonathan
// Last update Mon May 12 14:48:50 2014 jonathan
//

#ifndef _ENNEMY_H_
# define _ENNEMY_H_

class Ennemy : public AEntity
{
public:
  Ennemy();
  Ennemy(const Ennemy &old);
  Ennemy operator=(const Ennemy &old);
  virtual ~Ennemy();

  virtual void	putBomb();
};


#endif /* _ENNEMY_H_ */
