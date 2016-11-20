#ifndef PADDLE_H
#define PADDLE_H

#include "Entity.h"

class Paddle : public Entity
{
protected:
	static irr::core::vector3df _velocity;
	Paddle(const irr::core::vector3df &position);
public:
	Paddle();
	~Paddle();
	virtual bool Update(float deltaTime);
	void ValidatePosition();
};
#endif