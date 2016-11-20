#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#pragma once

#include "irrlicht/include/irrlicht.h"
class InputHandler;
class GraphicsEngine
{
private:
	GraphicsEngine(void);
	~GraphicsEngine(void);
	static irr::IrrlichtDevice* _device;

public:
	static bool Initialise(InputHandler* inputHandler);
	static bool Run();
	static bool Update (float deltaTime);
	static bool Render();
	static void Shutdown();
	static irr::u32 GetTime() {
		if (_device){
			return _device->getTimer()->getRealTime();
		}
		return 0;
	}
	static irr::scene::ISceneNode* AddCube(float size) {
		if (_device){
			return _device->getSceneManager()->addCubeSceneNode(size);
		}
		return NULL;
	}
	static irr::scene::ISceneNode* AddSphere(float radius, int polyCount = 16) {
		if (_device){
			return _device->getSceneManager()->addSphereSceneNode(radius, polyCount);
		}
		return NULL;
	}
	static irr::scene::ISceneNode* AddNodeFromMesh(irr::scene::IMesh* mesh){
		if (_device){
			return _device->getSceneManager()->addMeshSceneNode(mesh);
		}
		return NULL;
	}
	static irr::scene::ICameraSceneNode* AddCamera(const irr::core::vector3df &position = irr::core::vector3df(), const irr::core::vector3df &target = irr::core::vector3df()) {
		if (_device) {
			irr::scene::ICameraSceneNode* camera = _device->getSceneManager()->addCameraSceneNode();
			camera->setTarget(target); 
			return camera;
		}
		return NULL;
	}
};
#endif