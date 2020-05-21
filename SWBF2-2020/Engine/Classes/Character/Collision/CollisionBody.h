#pragma once
#include "../../../Engine.h"

namespace Engine
{
	class CollisionBody
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::CollisionBody::Offsets
		union
		{
			DEFINE_MEMBER_B(D3DXVECTOR3, PositionOffset);
			DEFINE_MEMBER_B(DWORD, Name);

		};
#undef DEFINE_MEMBER_CLASS
	public:
	};
}