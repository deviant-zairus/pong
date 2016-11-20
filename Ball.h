#ifndef BALL_H
#define BALL_H

#pragma once

#include "Entity.h"

class Ball : public Entity
{
private:
	static irr::core::vector3df _velocity;
	irr::core::vector3df _currentVelocity;
public:
	Ball();
	~Ball();
	bool Update(float deltaTime, InputHandler* ih);
	void ValidatePosition();
	const irr::core::vector3df & getPosition () const{
		return _node->getPosition();
	}
};
#endif