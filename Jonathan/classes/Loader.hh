//
// Loader.hh for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Wed May 14 12:32:09 2014 Lacazedieu
// Last update Thu May 22 13:09:59 2014 jonathan
//

#ifndef _LOADER_HH_
#define _LOADER_HH_

#include "AEntity.hh"

enum	e_EType
  {
    None = 0,
    ButtonType,
    CubeType,
    GroundType,
    WallType,
    PlayerType,
  };

class						Loader
{
private:
  std::map<enum e_EType, gdl::Geometry*>	_geometry;
  std::map<enum e_EType, gdl::Model*>		_models;
  std::map<enum e_EType, gdl::Texture*>		_textures;
  gdl::Texture					_tex;
  gdl::Model					_mod;
  gdl::Geometry					_geo;
public:
  Loader();
  ~Loader();

public:
  bool	loadTextures();
  bool	loadModels();
  bool	loadGeometry();
  bool	load();
  void  setObject(AEntity & object, const enum e_EType type);
  void  setObject(AEntity * object, const enum e_EType type);
};

#endif
