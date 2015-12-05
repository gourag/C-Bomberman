//
// MapEditor.hh for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Tue May 13 16:20:00 2014 Lacazedieu
// Last update Mon May 19 10:46:36 2014 jonathan
//

#ifndef			_MAPEDITOR_HH_
#define			_MAPEDITOR__

#include <Game.hh>
#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "OpenGL.hh"
#include "BasicShader.hh"
#include "Map.hh"

// enum	e_EType
//   {
//     None = 0,
//     CubeType,
//     PlayerType,
//   };

class			MapEditor
{
private:
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  e_EType		_type;
  int			_X;
  int			_Y;
  int			_Z;
  int			_w;
  int			_h;
  Map			*_map;
  bool			_changed;
  // std::vector<AEntity*>	_entities;
  // std::map<int, std::map<int, enum e_EType> > _map;
  AEntity		*_preview;
  Loader		_loader;

public:
  MapEditor();
  ~MapEditor();

public:
  bool	initialize(const int width = 5, const int height = 5);
  bool	update();
  void	draw();

public:
  void	addEntity();
  void	removeEntity();
  void  changePreview();

public:
  void	moveLeft();
  void	moveRight();
  void	moveUp();
  void	moveDown();
  void	raise();
  void	lower();

  bool	loadMap();
  void	newMap();
  void	randomize();
  bool	saveMap();
};

#endif
