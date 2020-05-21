#pragma once
#include "../../../Engine.h"

namespace Engine
{
	class EntityClass
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::EntityClass::Offsets
		union
		{
			DEFINE_MEMBER_B(Engine::EntityClass*, NextClass);
			DEFINE_MEMBER_B(Engine::EntityClass*, PreviousClass);
			DEFINE_MEMBER_B(INT, ClassId);
			DEFINE_MEMBER_B(wchar_t*, Name);
			DEFINE_MEMBER_B(FLOAT, MaxHealth);
			DEFINE_MEMBER_B_ARRAY(Engine::CollisionBody*, CollsionBodies, 64);
		};
#undef DEFINE_MEMBER_CLASS
	public:
		Engine::CollisionBody* GetCollisionBody(const char* name)
		{
			for (int i = 0; i < 32; i++)
			{
				Engine::CollisionBody* col = this->CollsionBodies[i];
				if (!col)
					break;
				if (col->Name == Engine::Obfuscation::HashString(name))
					return col;
			}
			return nullptr;
		}
	};
}