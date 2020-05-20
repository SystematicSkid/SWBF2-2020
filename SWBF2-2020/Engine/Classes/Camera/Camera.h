#pragma once
#include "../../Engine.h"

namespace Engine
{
	class Camera
	{
	public:
		/* Structure Data */
#define DEFINE_MEMBER_CLASS Engine::Addresses::Camera::Offsets
		union
		{
			DEFINE_MEMBER_B(D3DXMATRIX, MatView);
			DEFINE_MEMBER_B(D3DXMATRIX, MatProjection);

		};
#undef DEFINE_MEMBER_CLASS
	public:
		D3DXMATRIX GetMatViewProjection()
		{
			return this->MatView * this->MatProjection;
		}

		/* Doesn't have to be thiscall because for some reason these functions contain the objects in them */
		static D3DXVECTOR3 WorldToScreen(D3DXVECTOR3 pos)
		{
			D3DXVECTOR3 arg_01;
			FLOAT* v4 = static_cast<FLOAT * (__cdecl*)(D3DXVECTOR3*, D3DXVECTOR3*)>((PVOID)(Engine::ModuleGame + 0x2B42B0))(&arg_01, &pos);
			D3DXVECTOR3 out;
			static_cast<INT(__cdecl*)(D3DXVECTOR3*, FLOAT*)>((PVOID)Engine::Addresses::Camera::Functions::WorldToScreen)(&out, v4);
			return out;
		}
	};
}