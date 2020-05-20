#pragma once
#include "../../Engine.h"

namespace Engine
{
	class CameraManager
	{
	public:
		/* Singleton Instance */
		static CameraManager*& Instance;
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::CameraManager::Offsets
		union
		{
			DEFINE_MEMBER_B(Engine::Camera*, GameCamera);
			DEFINE_MEMBER_B(D3DXVECTOR3, Position);
		};
#undef DEFINE_MEMBER_CLASS
	};

	/* Set instance of Engine::CameraManager */
	Engine::CameraManager*& Engine::CameraManager::Instance = *reinterpret_cast<Engine::CameraManager**>(Engine::Addresses::CameraManager::Instance);
}