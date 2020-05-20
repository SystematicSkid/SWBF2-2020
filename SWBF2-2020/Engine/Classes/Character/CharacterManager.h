#pragma once
#include "../../Engine.h"

namespace Engine
{
	class CharacterManager
	{
	public:
		/* Singleton Instance */
		static CharacterManager* Instance;
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::CharacterManager::Offsets
		union
		{
			DEFINE_MEMBER(INT, NumCharacters);
			DEFINE_MEMBER_B(Engine::Character*, CharacterArray);
		};
#undef DEFINE_MEMBER_CLASS
	public:

		Engine::Character* GetCharacter(INT idx)
		{
			if (idx > NumCharacters)
				return nullptr;
			DWORD size_of_class = sizeof(Engine::Character);
			return &CharacterArray[idx];
		}
	};

	/* Set instance of Engine::CharacterManager */
	Engine::CharacterManager* Engine::CharacterManager::Instance = reinterpret_cast<Engine::CharacterManager*>(Engine::Addresses::CharacterManager::Instance);
}