#pragma once
#include "../../Engine.h"

namespace Engine
{
	class Team
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::Team::Offsets
		union
		{
			DEFINE_MEMBER_B(INT, Id);
			DEFINE_MEMBER_B(PCHAR, Name);
			DEFINE_MEMBER_B(INT, NumReinforcements);
			DEFINE_MEMBER_B(INT, NumCharacters);
			DEFINE_MEMBER_B(class Engine::Character**, Characters);
			DEFINE_MEMBER_B(INT, NumClasses);
			DEFINE_MEMBER_B(Engine::EntityClass**, Classes);
			DEFINE_MEMBER_B(Engine::Teams, TeamId);
			DEFINE_MEMBER_B(Engine::Relationship, Relationship);



		};
#undef DEFINE_MEMBER_CLASS
	public:
	}; // Size: 0x840
}