#ifndef AIPADDLE_H
#define AIPADDLE_H

#pragma once
#include "Paddle.h"

class Ball;
class AIPaddle : public Paddle
{
private:
	Ball* _ball;
public:
	AIPaddle(Ball* ball);
	~AIPaddle();
	bool Update(float deltaTime, InputHandler* ih);
};
#endif