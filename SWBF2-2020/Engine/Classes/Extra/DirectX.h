#pragma once
#include "../../Engine.h"

namespace Engine
{
	class DirectX
	{
	public:
		/* Singleton Instance */
		static DirectX* Instance;
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::DirectX::Offsets
		union
		{
			DEFINE_MEMBER(LPDIRECT3DDEVICE9, Device);
		};
#undef DEFINE_MEMBER_CLASS
	};

	/* Set instance of Engine::ChatManager */
	Engine::DirectX* Engine::DirectX::Instance = reinterpret_cast<Engine::DirectX*>(Engine::Addresses::DirectX::Instance);
}