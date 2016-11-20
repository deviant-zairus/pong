#include "graphicsEngine.h"
#include "inputHandler.h"

irr::IrrlichtDevice* graphicsEngine::_device = NULL;

graphicsEngine::graphicsEngine(void)
{}

graphicsEngine::~graphicsEngine(void)
{}

bool graphicsEngine::Initialise(inputHandler* inputHandler)
{
	irr::core::dimensions2du _dimensions = irr::coredimensions2du(640, 480);
	if (_device)
	{
		_device->drop();
	}
	device = irr::createDevice(irr::video::EDT_DIRECT3D9, _dimensions, 16, false, false, false, inputHandler);
	if (!_device)
	{
		std::cerr<<"FAILED TO CREATE DEVICE USING DIRECTX 9! Attempting Open GL..."<<std::endl;
		_device = irr::createDevice(irr::video::EDT_OPENGL, _dimensions, 16, false, false, false, inputHandler);
		if (!_device)
		{
			std::cerr<<"FAILED TO CREATE DEVICE USING OPEN GL! Attempting BurningsVideo..."<<std::endl;
			_device = irr::createDevice(irr::video::EDT_BURNINGSVIDEO, _dimensions, 16, false, false, false, inputHandler);
			if (!_device)
			{
				std::cerr<<"FAILED TO CREATE DEVICE USING BURNINGSVIDEO! Attempting software based..."<<endl;
				_device = irr::createDevice(irr::video::EDT_SOFTWARE, _dimensions, 16, false, false, false, inputHandler);
				if(!_device)
				{
					std::cerr<<"FAILED TO INITIALZE DEVICE RUNTIME ENVIROMENT! Please verify driver installtion and try again."<<endl;
					return false;
				}
			}
		}
	}
	return true;
}
bool graphicsEngine::Run()
{
	return _device->ren();
}

bool graphicsEngine::Updare(float deltaTime)
{
	return true;
	//custom graphics effects added 
}

bool graphicsEngine::Render()
{
	if(!_device->getVideoDriver()->beginScene())
	{
		return false;
	}
	_device->getSceneManager()->drawAll();
	_device->getGUIEnviroment()->drawAll();
	//custom rendering software goes here such as GUI overlays
	if (!_device->getVideoDriver()->endScene())
	{
		return false;
	}
	return true;
}

void graphicsEngine::Shutdown()
{
	if(_device)
	{
		_device->drop();
		_device=NULL;
	}
}