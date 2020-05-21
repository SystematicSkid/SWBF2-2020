#pragma once
#include "../../../Engine.h"

namespace Engine
{
	class Weapon
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::Weapon::Offsets
		union
		{
			DEFINE_MEMBER_B(Engine::WeaponClass*, WeaponClass);
			DEFINE_MEMBER_B(class Entity*, OwnerEntity);
			DEFINE_MEMBER_B(FLOAT, TimeSinceLastFire);
			DEFINE_MEMBER_B(FLOAT, FireCooldown);
			DEFINE_MEMBER_B(FLOAT, LastFireTime);
		};
#undef DEFINE_MEMBER_CLASS
	public:

		INT GetAmmo()
		{
			DWORD ammo_info = *(DWORD*)((DWORD)this + 0x88);
			FLOAT ammo_per_shot = *(FLOAT*)(*(DWORD*)(ammo_info)+0x4);
			return (INT)(*(FLOAT*)(ammo_info + 0x10) / ammo_per_shot);
		}

		VOID SetInfiniteAmmo()
		{
			DWORD ammo_info = *(DWORD*)((DWORD)this + 0x88);
			*(FLOAT*)(*(DWORD*)(ammo_info)+0x4) = 0.f;
		}

	}; // Size: 0x1BC
}