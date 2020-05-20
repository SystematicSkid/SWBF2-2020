#pragma once

namespace Core::Hooks::DirectX
{
	/* Our Callback */
	std::function<VOID(LPDIRECT3DDEVICE9 Device)> OnEndScene = nullptr;

	/* Address of original functions */
	DWORD_PTR OriginalFunction = NULL;

	/* Raw callback of `DirectX->EndScene` */
	HRESULT __stdcall NewEndScene(LPDIRECT3DDEVICE9 device)
	{
		//printf("Hook...\n");
		// Call event `Hooks::DirectX->OnEndScene`
		if (Hooks::DirectX::OnEndScene)
		{
			Hooks::DirectX::OnEndScene(device);
		}
		// Return original function
		return static_cast<HRESULT(__stdcall*)(LPDIRECT3DDEVICE9)>((void*)OriginalFunction)(device);
	}

	void Initialize()
	{
		auto pSwapChain = Engine::DirectX::Instance->Device;

		DWORD myFunc = (DWORD)NewEndScene;
		DWORD* engineInterface = (DWORD*)*(DWORD*)pSwapChain;

		if (engineInterface[42] != myFunc)
		{
			//Allocate some memory for our copy of the interface (vtable)
			static DWORD myEngineInterface[208 + 150];

			DWORD* engineInterface = (DWORD*)*(DWORD*)pSwapChain;

			//Copy from the original to ours...
			memcpy(&myEngineInterface, engineInterface, sizeof(myEngineInterface));
			*(DWORD*)pSwapChain = (DWORD)&myEngineInterface;
			//Now apply the hook to our interface.
			OriginalFunction = (DWORD_PTR)myEngineInterface[42];
			myEngineInterface[42] = (DWORD)myFunc;
		}

	}
}