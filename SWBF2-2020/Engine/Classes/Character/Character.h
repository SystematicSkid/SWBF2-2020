#pragma once
#include "../../Engine.h"

namespace Engine
{
	class Character
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::Character::Offsets
		union
		{
			DEFINE_MEMBER_B_ARRAY(CHAR, Name, 64);
			DEFINE_MEMBER_B(INT, TeamId);
			DEFINE_MEMBER_B(Engine::Team*, Team);
			DEFINE_MEMBER_B(Engine::EntitySoldierClass*, CharacterClass);
			DEFINE_MEMBER_B(Engine::EntitySoldier*, Entity);
			DEFINE_MEMBER_B(INT, Pad);

		};
#undef DEFINE_MEMBER_CLASS
	public:
	}; // Size: 0x1AC
}