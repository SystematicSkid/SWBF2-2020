#pragma once
#include <Windows.h>

namespace Engine
{
	// Main module start address
	DWORD_PTR ModuleGame = reinterpret_cast<DWORD_PTR>(GetModuleHandleA(NULL));

	namespace Addresses
	{
		namespace Globals
		{
			namespace Instances
			{

			}
		}

		namespace DirectX
		{
			DWORD CONST Instance = *(DWORD*)(Memory::SigScan("A1 ? ? ? ? 8D 55 D8 56") + 1); // This is the ONLY address that changes on patch 1.3 -> WTF??

			namespace Offsets
			{
				DWORD CONST Device = 0x0000;
			}
		}

		namespace CameraManager
		{
			DWORD CONST Instance = ModuleGame + 0x1A30324;

			namespace Offsets
			{
				DWORD CONST GameCamera	= 0x0024;
				DWORD CONST Position	= 0x003C;
			}
		}

		namespace Camera
		{
			namespace Offsets
			{
				DWORD CONST MatView			= 0x70;
				DWORD CONST MatProjection	= 0xB0;
			}

			namespace Functions
			{
				DWORD CONST WorldToScreen = ModuleGame + 0x2B41D0;
			}
		}

		namespace Team
		{
			namespace Offsets
			{
				DWORD CONST Id					= 0x0008;
				DWORD CONST Name				= 0x000C;
				DWORD CONST NumReinforcements	= 0x0028;
				DWORD CONST NumCharacters		= 0x0038;
				DWORD CONST Characters			= 0x0040;
				DWORD CONST NumClasses			= 0x0048;
				DWORD CONST Classes				= 0x0050;
				DWORD CONST TeamId				= 0x64;
				DWORD CONST Relationship		= 0x0088;
			}

			namespace VMTable
			{
				DWORD CONST GetCharacterByEntity = 4;
			}
		}

		namespace Character
		{
			namespace Offsets
			{
				DWORD CONST Name			= 0x0030;
				DWORD CONST TeamId			= 0x0134;
				DWORD CONST Team			= 0x0138;
				DWORD CONST CharacterClass	= 0x0140;
				DWORD CONST Entity			= 0x0148;
				DWORD CONST Pad				= 0x1AC;
			}
		}

		namespace CharacterManager
		{
			DWORD CONST Instance = ModuleGame + 0x1A30330;
			namespace Offsets
			{
				DWORD CONST NumCharacters	= 0x0000;
				DWORD CONST CharacterArray	= 0x0004;
			}
		}

		namespace EntityClass
		{
			namespace Offsets
			{
				DWORD CONST NextClass		= 0x0008;
				DWORD CONST PreviousClass	= 0x000C;
				DWORD CONST ClassId			= 0x001C;
				DWORD CONST Name			= 0x0020;
				DWORD CONST Hitboxes		= 0x0ABC;
				DWORD CONST MaxHealth		= 0x02E0;
				DWORD CONST CollsionBodies	= 0x0AC4;
			}
		}

		namespace EntitySoldier
		{
			namespace Offsets
			{
				DWORD CONST PlayerController	= 0x00C8;
				DWORD CONST Character			= 0x00CC;
				DWORD CONST HeadPosition		= 0x00DC;
				DWORD CONST EntityClass			= 0x0200;
				DWORD CONST Weapons				= 0x04E0;
				DWORD CONST SelectedWeapon		= 0x0500;
				DWORD CONST SelectedEquipment	= 0x0501;
				DWORD CONST FootPosition		= 0x0524;
			}
		}

		namespace CommandPost
		{
			namespace Offsets
			{
				DWORD CONST IdentityName	= 0x0020;
				DWORD CONST LocationName	= 0x0028;
				DWORD CONST EntityBuilding	= 0x002C;
				DWORD CONST Position		= 0x0034;
			}
		}

		namespace EntityBuilding
		{
			namespace Offsets
			{
				DWORD CONST EntityClass		= 0x0008;
				DWORD CONST Position		= 0x0018;
				DWORD CONST CollisionModel	= 0x0054;
			}
		}

		namespace CollisionBody
		{
			namespace Offsets
			{
				DWORD CONST PositionOffset	= 0x0044;
				DWORD CONST Name			= 0x0050; // Hashed via FNVA1
			}
		}

		namespace WeaponClass
		{
			namespace Offsets
			{
				DWORD CONST ClassId	= 0x001C;
				DWORD CONST Name	= 0x0050;
			}
		}

		namespace Weapon
		{
			namespace Offsets
			{
				DWORD CONST WeaponClass	= 0x0060;
				DWORD CONST OwnerEntity = 0x006C;
				DWORD CONST TimeSinceLastFire = 0x00B4;
				DWORD CONST FireCooldown = 0x00B8;
				DWORD CONST LastFireTime = 0x00F8;
			}
		}

		namespace WeaponAmmo
		{
			namespace Offstes
			{
				DWORD CONST TotalAmmo = 0x000C;
				DWORD CONST CurrentAmmoInClip = 0x0010;
			}
		}
	}
}