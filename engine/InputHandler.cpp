#pragma once 

#include "irrlicht/include/irrlicht"
#include "InputHandler.h"

InputHandler::InputHandler()
{
	for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
	{
		keyDown[i] = false;
		keyWasDown[i] = false;
	}
}

bool InputHandler::OnEvent(const irr::SEvent &incomingEvent)
{
	bool retValue = true;
	switch (incomingEvent.EventType)
	{
		case irr::EET_KEY_INPUT_EVENT:
		{
			keyDown[incomingEvent.KeyInput.Key] = incomingEvent.KeyInput.PressedDown;
			retValue = false;
			break;
		}
	}
	return retValue;
}

bool InputHandler::isKeyDown(irr::EKEY_CODE key)const
{
	return keyDown[key];
}

bool InputHandler::WasKeyDown(irr::EKEY_CODE key)const
{
	return keyWasDown[key];
}

bool InputHandler::IsKeyDownButNotHeld(irr::EKEY_CODE key)const
{
	return IsKeyDown(key) && !WasKeyDown(key);
}

bool InputHandler::Update()
{
	for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
	{
		keyWasDown[i] = keyDown[i];
		keyDown[i] = false;
	}
	return true;
}