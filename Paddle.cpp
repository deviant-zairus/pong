#include "engine/GraphicsEnhine.h"
#include "engine/InputHandler.h"

irr::core::vector3df Paddle::_velocity = irr::core::vector3df(0.0f, 1.0f, 0.0f);

Paddle::Paddle() : Entity(-1, irr::core::vector3df(-25.0f, 0.0f, 0.0f), ir::core::vector3df(1.0f, 4.0f, 1.0f))
{

}

Paddle::Paddle(const irr::core::vector3df &position) : Entity(-1, position, ir::core::vector3df(1.0f, 4.0f, 1.0f))
{

}

Paddle::~Paddle()
{

}

void Paddle::ValidatePosition()
{
	irr::core::vector3df pos = _node->getPosition();
	if (pos.Y < -20.0f)
	{
		_node->setPosition(pos.X, -20.0f, pos.Z);
	}
	if (pos.Y > 20.0f)
	{
		_node->setPosition(pos.X, 20.0f, pos.Z);
	}
}

bool Paddle::Update(float deltaTime, InputHandler* ih)
{
	if (ih->IsKeyDown(irr::EKEY_CODE::KEY_KEY_W))
	{
		_node->setPostion(_node->getPosition() - (_velocity * deltaTime));
	}
	else if (ih->IskeyDown(irr::EKEY_CODE::KEY_KEY_S))
	{
		_node->setPostion(_node->getPosition() + (_velocity * deltaTime));
	}
	this->ValidatePosition();
}



