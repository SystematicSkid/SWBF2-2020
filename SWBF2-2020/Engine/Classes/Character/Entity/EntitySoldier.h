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
			DEFINE_MEMBER_B(D3DXVECTOR3, HeadPosition);
			DEFINE_MEMBER_B(Engine::EntityClass*, EntityClass);
			DEFINE_MEMBER_B_ARRAY(Engine::Weapon*, Weapons, 8);
			DEFINE_MEMBER_B(BYTE, SelectedWeapon);
			DEFINE_MEMBER_B(D3DXVECTOR3, FootPosition);

		};
#undef DEFINE_MEMBER_CLASS
	public:
		Engine::Weapon* GetSelectedWeapon()
		{
			return this->Weapons[this->SelectedWeapon];
		}
	};
}