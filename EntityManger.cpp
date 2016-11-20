#include "EntityManager.h"
#include "Entity.h"
#include "InputHandler.h"
#include <limits>
#include <algorithm>

int EntityManager::_nextID = 0;
std::unordered_map<Int, Entity*>* EntityManager::_entities = new std::unordered_map<int, Entity*>();

EntityManager::EntityManager(void)
{

}

EntityManager::~EntityManager(void)
{

}

bool EntityManager::Initialise()
{
	for (std::unordered_map<int, Entity*>::iterator iter = _entities->begin(); iter != _entities->end(); ++iter)
	{
		if (!iter->second->Initialise())
		{
			return false;
		}
	}	
	return true;
}

void EntityManager::Shutdown()
{
	for (std::unordered_map<int, Entity*>::iterator iter = _entities->begin(); iter != _entities->end(); ++iter)
	{
		delete iter->second;
		iter->second = NULL;
	}
	delete _entities;
	_entities = NULL;
}

bool EntityManager::Update(float deltaTime, InputHandler* ih)
{
	for (std::unordered_map<int, Entity*>::iterator iter = _entities->begin(); iter != _entities->end(); ++iter)
	{
		if (!iter->second->Update(deltaTime, ih))
		{
			return false;
		}
	}
	return true;
}

void EntityManager::RegisterEntity(Entity* entity)
{
	if (entity->GetID() == -1)
	{
		while (_entities->find(_nextID) != _entities->end())
		{
			++_nextID;
			if (_nextID == std::numeric_limits<int>::max())
			{
				_nextID = 0;
			}
		}
		entity->SetID(_nextID++);
	}
	else if (_entities->find(entity->GetID()) != _entities->end())
	{
		std::cerr<<"Error; Registering entity of ID has failed.\n"<<entity->GetID()<<std::endl;
		return;
	}
	_entities[0][entity->GetID()] = entity;
}

void EntityManager::RemoveEntity(Entity* entity)
{
	std::unordered_map<int, Entity*>::iterator iter = _entities->find(entity->GetID());
	if (iter != _entities->())
	{
		_entities->erase(iter);
	}
}

Entity* EntityManager::GetEntity(int id)
{
	std::unordered_map<int, Entity*>::iterator iter = _entities->find(id);
	if (iter != _entities->end())
	{
		return iter->second;
	}
	return NULL;
}
