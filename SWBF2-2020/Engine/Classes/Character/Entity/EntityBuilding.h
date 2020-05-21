#pragma once
#include "../../../Engine.h"

namespace Engine
{
	class EntityBuilding
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::EntityBuilding::Offsets
		union
		{
			DEFINE_MEMBER_B(Engine::EntityClass*, EntityClass);
			DEFINE_MEMBER_B(D3DXVECTOR3, Position);
			DEFINE_MEMBER_B(class CollisionModel*, CollisionModel);

		};
#undef DEFINE_MEMBER_CLASS
	public:
	};
}