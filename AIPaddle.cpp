#include "AIPaddle.h"
#include "Ball.h"

AIPaddle::AIPaddle(Ball* ball) : Paddle(irr::core::vector3df(25.0f, 0.0f, 0.0f))
{
	this->_ball = ball;
}

AIPaddle::~AIPaddle()
{

}

bool AIPaddle::Update(float deltaTime, InputHandler* ih)
{
	irr::core::vector3df ballPos = this->_ball->GetPosition();
	irr::core::vector3df myPos = this->_node->GetPosition();
	if (ballPos.Y > myPos.Y)
	{
		this->_node->setPosition(myPos + (_velocity * deltaTime));
	}
	else if (ballPos.Y < myPos.Y)
	{
		this->_nod->setPosition(myPos - (_velocity * deltaTime));
	}
	Paddle::ValidatePosition();
}