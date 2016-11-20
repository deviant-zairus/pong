#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#pragma once

#include <unordered_map>
#include "engine/irrlicht/include/irrlicht.h"

class Entity;
class InputHandler;

class EntityManager
{
private:
	static int _nextID;
	static std::unordered_map<int, Entity*>* _entities;
	EntityManager(void);
	~EntityManager(void);
public:
	static bool Initialise();
	static bool Update(float deltaTime, InputHandler* ih);
	static void Shutdown();
	static void RegisterEntity(Entity* entity);
	static void RemoveEntity(Entity* entity);
	static Entity* GetEntity(int id);
	static std::unordered_map<int, Entity*>* GetEntities() {
		return _entities;
	}
};
#endif