#pragma once
#include "../../Engine.h"

namespace Engine
{
	class CommandPost
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::CommandPost::Offsets
		union
		{
			DEFINE_MEMBER_B(PCHAR, IdentityName);
			DEFINE_MEMBER_B(wchar_t*, LocationName);
			DEFINE_MEMBER_B(Engine::EntityBuilding*, EntityBuilding);
			DEFINE_MEMBER_B(D3DXVECTOR3, Position);
		};
#undef DEFINE_MEMBER_CLASS
	public:
	};
}