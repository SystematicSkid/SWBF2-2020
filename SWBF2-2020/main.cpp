#include <Windows.h>
/* Engine Library */
#include "Engine/Engine.h"
/* Core Library */
#include "Core/Core.h"

ui::manager ui::g_mgr;
HWND g_hwnd;
font text;

VOID MenuInitialize(VOID)
{
	// Memory to textures of menu
	static texture visuals_txt;
	// Load image OrbWalker
	int x = 0, y = 0, c = 0;
	auto visuals_decoded = stbi_load_from_memory(visuals_raw, sizeof visuals_raw, &x, &y, &c, 4);
	visuals_txt.create(visuals_decoded, x, y);
	free(visuals_decoded);
	// Create menu tabs
	auto ui_mgr = ui::manager::get();
	if (ui_mgr->create())
	{
		ui_mgr->add_tab("VISUALS", &visuals_txt);
	}
}

/* Redirect CRT standard handles to the console window */
FILE* pNewStdout = NULL;
FILE* pNewStderr = NULL;
FILE* pNewStdin = NULL;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpvReserved)
{
	// Initialize once for each new process
	if (dwReason != DLL_PROCESS_ATTACH) return FALSE;
	// Console initialize
	AllocConsole(); 
	SetConsoleTitleA("SWBF2 - 2020");
	// Assign `stdin`, `stout`, `stderr`
	::freopen_s(&pNewStdin, "CONIN$", "r", stdin);
	::freopen_s(&pNewStdout, "CONOUT$", "w", stdout);
	::freopen_s(&pNewStderr, "CONOUT$", "w", stderr);

	// Initialize the core
	if (!Core::Initialize())
	{
		printf("[ Error ] Could not initialize the core.\n");
		return FALSE;
	}

	// Configure window
	g_hwnd = FindWindowA(("Star Wars Battlefront II"), NULL);
	// Initialize our renderer
	renderer_setup(Engine::DirectX::Instance->Device);
	text.create(("Arial"), 10, FONT_DEFAULT);
	// Initialize the menu
	//MenuInitialize();

	printf("[ + ] Core initialized successfully!\n");

	Core::Hooks::DirectX::OnEndScene = [](LPDIRECT3DDEVICE9 Device)
	{
		// Begin our rendering
		renderer_start_drawing();
		geometry g;
		g.push_draw_cmd();

		/* Watermark */
		text.draw_text(&g, { 20, 10 }, ("SWBF2 Hook"), { 255, 255, 255, 127 });

		// TODO: Add an in-game check

		Engine::CharacterManager* character_manager = Engine::CharacterManager::Instance;
		
		for (int i = 0; i < character_manager->NumCharacters; i++)
		{
			Engine::Character* character = character_manager->GetCharacter(i);
			if(!character)
				continue;
			Engine::EntitySoldier* entity = character->Entity;
			if(!entity || !character->CharacterClass)
				continue;
			D3DXVECTOR3 screen = Engine::Camera::WorldToScreen(entity->Position);
			screen.z += 1.f; // Need to add 1 to it for some reason to check if it's in front or behind us!
			std::wstring ws(character->CharacterClass->Name);
			std::string str(ws.begin(), ws.end());
			if (0.00001f < screen.z)
				text.draw_text(&g, { screen.x, screen.y }, str.c_str(), { 255,255,255,255 }, TEXT_CENTERED);
		}

		/* Finish rendering */
		g.render();
		//ui::manager::get()->think();
		renderer_draw();
	};

	return TRUE;
}