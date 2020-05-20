#pragma once
#define STB_IMAGE_IMPLEMENTATION

#include <Windows.h>
#include <string>
#include <map>
#include <functional>

/* Engine */
#include "../Engine/Engine.h"

/* Renderer */
#include "./Renderer/Renderer.h"
#include "./Renderer/Cfg.h"
#include "./Renderer/Ui.h"
#include "./Renderer/stb_image.h"

#include "./Renderer/Textures/Visuals.h"

/* Hooks */
#include "./Hooks/Hooks.h"

namespace Core
{
	BOOL Initialize(VOID)
	{
		printf("[ + ] The core is being loaded...\n");

		printf("\t[ + ] Hooking functions...\n");
		if (!Core::Hooks::Initialize()) return FALSE;


		return TRUE;
	}
}