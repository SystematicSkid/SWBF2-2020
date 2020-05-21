#pragma once
#include "../../../Engine.h"

namespace Engine
{
	class WeaponClass
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::WeaponClass::Offsets
		union
		{
			DEFINE_MEMBER_B(INT, ClassId);
			DEFINE_MEMBER_B(wchar_t*, Name);
		};
#undef DEFINE_MEMBER_CLASS
	public:
	};
}