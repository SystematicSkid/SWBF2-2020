#pragma once
#include "DirectX.h"

namespace Core
{
	namespace Hooks
	{
		BOOL Initialize(VOID)
		{
			Core::Hooks::DirectX::Initialize();

			return TRUE;
		}
	}
}