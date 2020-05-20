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
			DWORD CONST Instance = ModuleGame + 0x3F594C;

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

		namespace EntitySoldierClass
		{
			namespace Offsets
			{
				DWORD CONST NextClass		= 0x0008;
				DWORD CONST PreviousClass	= 0x000C;
				DWORD CONST ClassId			= 0x001C;
				DWORD CONST Name			= 0x0020;
				DWORD CONST Hitboxes		= 0x0ABC;
			}
		}

		namespace EntitySoldier
		{
			namespace Offsets
			{
				DWORD CONST PlayerController	= 0x00C8;
				DWORD CONST Character			= 0x00CC;
				DWORD CONST Position			= 0x00DC;
			}
		}
	}
}