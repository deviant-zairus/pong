#include "Entity.h"
#include "EntityManager.h"
#include "engine/GraphicsEngine.h"

Entity::Entity(int id, const irr::core::vector3df &position, const irr::core::vector3df &scale)
{
	this->_id = id;
	this->_node = GraphicsEngine::AddCube(1.0f);
	if (this->_node)
	{
		this->_node->setScale(scale);
	}
	EntityManager::RegisterEntity(this);
}
Entity::~Entity()
{
	
}