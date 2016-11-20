#pragma comment(lib, "Irrlicht")

#include "engine/GraphicsEngine.h"
#include "engine/InputHandler.h"
#include "EntityManager.h"
#include "Paddle.h"
#include "AIPaddle.h"
#include "Ball.h"
#include <iostream>

void CharHold()
{
	char hold;
	std::cin >> hold;
}

int main()
{
	InputHandler* ih = new InputHandler();
	if (!GraphicsEngine::Initialise(ih))
	{
		std::cout << "GraphicsEngine failed to initialise\n";
		CharHold();
		return -1;
	}
	irr::scene::ICameraSceneNode* camera = GraphicsEngine::AddCamera(irr::core::vector3df(0.0f, 0.0f, -30.0f));
	new Paddle();
	new AIPaddle(new Ball());
	irr::u32 prevTime = GraphicsEngine::GetTime();
	irr::u32 currTime;
	float deltaTime;
	while (GraphicsEngine::Run())
	{
		currTime = GraphicsEngine::GetTime();
		deltaTime = (float)(currTime - prevTime) / 1000.0f;
		prevTime = currTime;
		if (!EntityManager::Update(deltaTime, ih))
		{
			break;
		}
		if (!GraphicsEngine::Update(deltaTime))
		{
			break;
		}
		if (ih->IsKeyDown(irr::EKEY_CODE::KEY_ESCAPE))
		{
			break;
		}
		ih->Update();
	}
	EntityManager::Shutdown();
	GraphicsEngine::Shutdown();
	delete ih;
	return 0;
}
