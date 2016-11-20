#include "Ball.h"
#include "EntityManager"
#include <unordered_map>

irr::core::vector3df Ball::_velocity = irr::core::vector3df(1.0f, 1.0f, 0.0f);

Ball::Ball() : Entity(-1)
{
	switch (rand() & 3)
	{
		case 0:
		_currentVelocity = _velocity;
		break;
		case 1:
		_currentVelocity = _velocity;
		_currentVelocity.X *= -1.0f;
		break;
		case 2:
		_currentVelocity = _velocity;
		_currentVelocity.Y *= -1.0f;
		break;
		case 3:
		_currentVelocity = -1.0f * _velocity;
		break;
	}
}

Ball::~Ball()
{

}

bool Ball::Update(float deltaTime, InputHandler* ih)
{
	if (this->_nade)
	{
		this->_node->setPosition(this->_node->getPosition() + (_currentVelocity * deltaTime));	
		std::unordered_map<int, Entity*>* entities = EntityManager::GetEntities();
		for (auto iter = entities->begin(); iter != entities->end(); ++iter)
		{
			if (iter-first != this ->_id)
			{
				if (iter->second->GetNode()->getTransformedBoundingBox().intersectsWith(this_node->getTransformedBoundingBox()))
				{
					_currentVelocity.X *= -1.0f;
					this->_node->setPosition(this->_node->getPosition() + (5.0f * _currentVelocity));
					break;
				}
			}
		}
	}
}

void Ball::ValidatePosition()
{
	irr::core::vector3df pos = this->_node->getPosition();
	if (pos.Y > 20.0f)
	{
		this->_node->setPosition(pos.X, 20.0f, pos.Z);
		this->_currentVelocity.Y *= -1.0f;
	}
	else if (pos.Y < -20.0f)
	{
		this->_node->setPosition(pos.X, -20.0f, pos.Z);
		this->_currentVelocity.Y *= -1.0f;
	}
	if (pos.X > 30.0f || pos.X < -30.0f)
	{
		this->_node->setPosition(0.0f, 0.0f, 0.0f);
		this->_currentVelocity *= -1.0f;
	}
}