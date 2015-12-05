//
// AEntityFactory.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Mon May 19 14:33:03 2014 jonathan
// Last update Mon May 19 14:45:07 2014 jonathan
//

#ifndef _AENTITYFACTORY_H_
# define _AENTITYFACTORY_H_

#include <string>
#include "AEntity.hh"
#include "Player.hh"
#include "Cube.hh"

class AEntityFactory
{
private:
  AEntityFactory(const AEntityFactory &old);
  AEntityFactory operator=(const AEntityFactory &old);

public:
  AEntityFactory();
  virtual ~AEntityFactory();

  Cube		*generateCube(int x, int y, int z);
  Player	*generatePlayer(int x, int y, int z);
  AEntity	*generateObject(const std::string &type, int x, int y,int z);
};


#endif /* _AENTITYFACTORY_H_ */
