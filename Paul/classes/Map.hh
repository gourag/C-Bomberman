//
// Map.hh for bomberman in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed May 14 18:10:46 2014 jonathan
// Last update Tue May 20 10:19:58 2014 jonathan
//

#ifndef _MAP_H_
# define _MAP_H_

#include <map>
#include <string>
#include <vector>
#include "BasicShader.hh"
#include "AEntity.hh"
#include "Loader.hh"

// enum	e_EType
//   {
//     None = 0,
//     CubeType,
//     PlayerType,
//   };

class Map
{
private:
  std::vector<AEntity *> _destr;
  std::vector<AEntity *> _indestr;
  std::map<int, std::map<int, std::map<int, enum e_EType> > > _map;
  std::map<enum e_EType, std::string> _litteralType;
  std::map<std::string, enum e_EType> _types;

  int	_width;
  int	_height;
  Loader	_loader;

public:
  Map(int, int, bool);
  Map();
  Map(const Map &old);
  Map &operator=(const Map &old);
  virtual ~Map();

  void	draw(gdl::BasicShader, gdl::Clock);

  bool	addEntity(e_EType, float, float, float);
  bool	addEntity(AEntity *, e_EType);
  bool	removeEntity(float, float, float);

  int	getWidth() const;
  int	getHeight() const;
  const std::map<int, std::map<int, std::map<int, enum e_EType> > >	&getMap() const;
  const std::map<enum e_EType, std::string>			&getTypes() const;
  enum e_EType	getType(const std::string &);
};


#endif /* _MAP_H_ */
