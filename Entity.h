#ifndef ENTITY_H
#define ENTITY_H

#include "engine/irrlicht/include/irrlicht.h"

class Entity
{
protected:
	int _id;
	irr::scene::ISceneNode* _node;
public:
	Entity(int id = -1, const irr::core::vector3df &position = irr::core::vector3df(), const irr::core::vector3df &scale = irr::core::vector3df(1.0f, 1.0f, 1.0f));
	~Entity();
	int GetID() const{
		return _id;
	}
	void SetID(int newID) {
		_id = newID;
	}
	irr::scene::ISceneNode* GetNode() const {
		return _node;
	}
	bool Update(float deltaTime, InputHandler* ih);
};
#endif