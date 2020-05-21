#pragma once
#include "../../Engine.h"

namespace Engine
{
	namespace Obfuscation
	{
		DWORD HashString(const char* str)
		{
			char c;			// cl
			DWORD result;	// eax
			DWORD mul;		// eax

			c = *str;
			result = 0x811C9DC5; // Based polynomial
			do
			{
				++str;
				mul = (c | 0x20) ^ result;
				c = *str;
				result = 16777619 * mul;
			} while (*str);
			return result;
		}
	}
}