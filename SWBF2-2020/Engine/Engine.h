#pragma once
#include <windows.h>
#include <vector>
#include <algorithm>

/* DirectX */
#pragma warning( push )
#pragma warning( disable : 26495 )
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")
#pragma warning( pop ) 

/* Macros */
#include "../Utilities/Macros.h"

/* Addresses */
#include "Addresses.h"

/* Engine -> Enums */
#include "./Enums/Relationship.h"
#include "./Enums/Team.h"

/* Engine -> Extra */
#include "./Classes/Extra/Obfuscation.h"
#include "./Classes/Extra/DirectX.h"

/* Engine -> Camera */
#include "./Classes/Camera/Camera.h"
#include "./Classes/Camera/CameraManager.h"

/* Engine -> Character -> Collision */
#include "./Classes/Character/Collision/CollisionBody.h"

/* Engine -> Character -> Entity */
#include "./Classes/Character/Entity/EntityClass.h"
#include "./Classes/Character/Entity/EntityBuilding.h"
#include "./Classes/Character/Entity/EntitySoldier.h"


/* Engine -> Character */
#include "./Classes/Character/CommandPost.h"
#include "./Classes/Character/Team.h"
#include "./Classes/Character/Character.h"
#include "./Classes/Character/CharacterManager.h"

namespace Engine
{
	/* Global Variables */
	Engine::CommandPost** g_pCommandPosts = (Engine::CommandPost**)(Engine::ModuleGame + 0x3E6314);
}