#pragma once
#include "../../../Engine.h"

namespace Engine
{
	class EntitySoldierClass
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::EntitySoldierClass::Offsets
		union
		{
			DEFINE_MEMBER_B(Engine::EntitySoldierClass*, NextClass);
			DEFINE_MEMBER_B(Engine::EntitySoldierClass*, PreviousClass);
			DEFINE_MEMBER_B(INT, ClassId);
			DEFINE_MEMBER_B(wchar_t*, Name);
		};
#undef DEFINE_MEMBER_CLASS
	public:
	};
}