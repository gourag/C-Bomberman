//
// Loader.cpp for  in /home/lacaze_p/rendu/cpp_bomberman/Paul/classes
// 
// Made by Lacazedieu
// Login   <lacaze_p@epitech.net>
// 
// Started on  Wed May 14 12:32:12 2014 Lacazedieu
// Last update Thu May 22 10:02:39 2014 jonathan
//

#include "Loader.hh"

Loader::Loader()
{
  _models[CubeType] = new gdl::Model();
  _models[PlayerType] = new gdl::Model();
  _models[GroundType] = new gdl::Model();
  _models[ButtonType] = new gdl::Model();
  _textures[CubeType] = new gdl::Texture();
  _textures[PlayerType] = new gdl::Texture();
  _textures[GroundType] = new gdl::Texture();
  _textures[ButtonType] = new gdl::Texture();
}

Loader::~Loader()
{
}

bool	Loader::load()
{
  std::cout << "Chargement des textures";
  if (!loadTextures())
    return false;
  std::cout << "Done." << std::endl;
  std::cout << "Chargement des modèles";
  if (!loadModels())
    return false;
  std::cout << "Done." << std::endl;
  std::cout << "Chargement des geometry";
  if (!loadGeometry())
    return false;
  std::cout << "Done." << std::endl;
  return true;
}

bool	Loader::loadTextures()
{
  if (_textures[CubeType]->load("./assets/box/woodBox.tga") == false)
    {
      std::cerr << "Cannot load the Cube texture" << std::endl;
      return (false);
    }
  std::cout << ".";
  if (_textures[PlayerType]->load("./assets/marvin.fbm/Main_texture_diffuse2.tga") == false)
    {
      std::cerr << "Cannot load the Player texture" << std::endl;
      return (false);
    }
  std::cout << ".";
  if (_textures[GroundType]->load("./assets/box/metalBox.tga") == false)
    {
      std::cerr << "Cannot load the Ground texture" << std::endl;
      return (false);
    }
   std::cout << ".";
  if (_textures[ButtonType]->load("./assets/box/metalBox.tga") == false)
    {
      std::cerr << "Cannot load the Button texture" << std::endl;
      return (false);
    }
   std::cout << ".";
  return (true);
}

bool	Loader::loadModels()
{
  if (_models[PlayerType]->load("./assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the Hero model" << std::endl;
      return (false);
    }
  return (true);
}

bool	Loader::loadGeometry()
{
  gdl::Geometry	*tmp = new gdl::Geometry;

  tmp->setColor(glm::vec4(1, 0, 0, 1));
  tmp->pushVertex(glm::vec3(0.5, -0.5, 0.5));
  tmp->pushVertex(glm::vec3(0.5, 0.5, 0.5));
  tmp->pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  tmp->pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  tmp->pushUv(glm::vec2(0.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 1.0f));
  tmp->pushUv(glm::vec2(0.0f, 1.0f));
  tmp->setColor(glm::vec4(1, 1, 0, 1));
  tmp->pushVertex(glm::vec3(0.5, -0.5, -0.5));
  tmp->pushVertex(glm::vec3(0.5, 0.5, -0.5));
  tmp->pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  tmp->pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  tmp->pushUv(glm::vec2(0.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 1.0f));
  tmp->pushUv(glm::vec2(0.0f, 1.0f));
  tmp->setColor(glm::vec4(0, 1, 1, 1));
  tmp->pushVertex(glm::vec3(0.5, -0.5, -0.5));
  tmp->pushVertex(glm::vec3(0.5, 0.5, -0.5));
  tmp->pushVertex(glm::vec3(0.5, 0.5, 0.5));
  tmp->pushVertex(glm::vec3(0.5, -0.5, 0.5));
  tmp->pushUv(glm::vec2(0.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 1.0f));
  tmp->pushUv(glm::vec2(0.0f, 1.0f));
  tmp->setColor(glm::vec4(1, 0, 1, 1));
  tmp->pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  tmp->pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  tmp->pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  tmp->pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  tmp->pushUv(glm::vec2(0.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 1.0f));
  tmp->pushUv(glm::vec2(0.0f, 1.0f));
  tmp->setColor(glm::vec4(0, 1, 0, 1));
  tmp->pushVertex(glm::vec3(0.5, 0.5, 0.5));
  tmp->pushVertex(glm::vec3(0.5, 0.5, -0.5));
  tmp->pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  tmp->pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  tmp->pushUv(glm::vec2(0.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 1.0f));
  tmp->pushUv(glm::vec2(0.0f, 1.0f));
  tmp->setColor(glm::vec4(0, 0, 1, 1));
  tmp->pushVertex(glm::vec3(0.5, -0.5, -0.5));
  tmp->pushVertex(glm::vec3(0.5, -0.5, 0.5));
  tmp->pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  tmp->pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  tmp->pushUv(glm::vec2(0.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 0.0f));
  tmp->pushUv(glm::vec2(1.0f, 1.0f));
  tmp->pushUv(glm::vec2(0.0f, 1.0f));
  tmp->build();
  _geometry[CubeType] = tmp;
  _geometry[GroundType] = tmp;
  _geometry[ButtonType] = tmp;
  return (true);
}

void	Loader::setObject(AEntity & object, const enum e_EType type)
{
  if (type != PlayerType)
    object.setGeometry(_geometry[type]);
  object.setModel(_models[type]);
  object.setTexture(_textures[type]);
}

void	Loader::setObject(AEntity * object, const enum e_EType type)
{
  if (type != PlayerType)
    object->setGeometry(_geometry[type]);
  object->setModel(_models[type]);
  object->setTexture(_textures[type]);
}
