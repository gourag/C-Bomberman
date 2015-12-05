//
// AEntityFactory.cpp for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Mon May 19 14:39:30 2014 jonathan
// Last update Tue May 20 10:32:14 2014 jonathan
//

#include "AEntityFactory.hh"
#include "MyException.hh"

AEntityFactory::AEntityFactory()
{
  // ptr["Player"] = &AEntityFactory::generatePlayer;
  // ptr["Cube"] = &AEntityFactory::generateCube;
  // ptr["Floor"] = &AEntityFactory::generateCube;
}

// AEntityFactory::AEntityFactory(const AEntityFactory &old)
// {
// }

// AEntityFactory &AEntityFactory::operator=(const AEntityFactory &old)
// {
//   return (*this);
// }

AEntityFactory::~AEntityFactory()
{
}

Cube	*AEntityFactory::generateCube(int x, int y, int z)
{
  return new Cube((float)x, (float)y, (float)z);
}
Player	*AEntityFactory::generatePlayer(int x, int y, int z)
{
  return new Player((float)x, (float)y, (float)z);
}
AEntity	*AEntityFactory::generateObject(const std::string &type, int x, int y, int z)
{
  if (type == "Cube" || type == "Floor")
    return generateCube(x, y, z);
  else if (type == "Player")
    return generatePlayer(x, y, z);
  else
    throw MyException("Unknown object type");
}
