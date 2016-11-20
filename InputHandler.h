#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#pragma once

#include "irrlicht/include/irrlicht.h"

class InputHandler : public irr::IEventReceiver
{
private:
	bool keyDown[irr::KEY_KEY_CODES_COUNT];
	bool keyWasDown[irr::KEY_KEY_CODES_COUNT];
public:
	InputHandler();
	bool OnEvent(const irr::SEvent &incomingEvent);
	bool IsKeyDown(irr::EKEY_CODE key) const;
	bool WasKeyDown(irr::EKEY_CODE key) const;
	bool IsKeyDownButNotHeld(irr::EKEY_CODE key) const;
	bool Update();
};
#endif