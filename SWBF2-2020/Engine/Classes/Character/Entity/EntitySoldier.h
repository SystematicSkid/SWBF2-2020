#pragma once
#include "../../../Engine.h"

namespace Engine
{
	class EntitySoldier
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::EntitySoldier::Offsets
		union
		{
			DEFINE_MEMBER_B(class PlayerController*, PlayerController);
			DEFINE_MEMBER_B(class Character*, Character);
			DEFINE_MEMBER_B(D3DXVECTOR3, Position);

		};
#undef DEFINE_MEMBER_CLASS
	public:
	};
}