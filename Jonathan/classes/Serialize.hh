//
// Serialize.hh for  in /home/jonathan/Documents/Work/cpp_bomberman/Jonathan
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed May 14 19:16:31 2014 jonathan
// Last update Tue May 20 10:16:37 2014 jonathan
//

#ifndef _SERIALIZE_H_
# define _SERIALIZE_H_

#include <string>
#include <map>
#include "Map.hh"

class Serialize
{
private:
  Map	*_map;

  std::map<std::string, e_EType> _types;
public:
  Serialize(Map *map);
  Serialize();
  Serialize(const Serialize &old);
  Serialize &operator=(const Serialize &old);
  virtual ~Serialize();

  void	pack(const std::string &);
  Map	*unpack(const std::string &);

  bool	getMapSize(const std::string &, int *, int *);
  bool	getElement(const std::string &, AEntity **, std::string *);
};


#endif /* _SERIALIZE_H_ */
