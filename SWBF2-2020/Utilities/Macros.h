#pragma once

namespace Engine
{
	// Classes
#define STR_MERGE_IMPL(X, Y)					X##Y
#define STR_MERGE(X, Y)							STR_MERGE_IMPL(X, Y)
#define MAKE_PAD(Size)							BYTE STR_MERGE(pad_, __COUNTER__) [ Size ]
//#define DEFINE_MEMBER_CLASS
//#define DEFINE_MEMBER_CLASS_INHERITANCE
#define DEFINE_MEMBER(Type, Name)				Type Name
#define DEFINE_MEMBER_0(Offset, X)				X
#define DEFINE_MEMBER_N(Offset, X)				struct { MAKE_PAD(Offset); X; }
#define DEFINE_MEMBER_B(Type, Name)				DEFINE_MEMBER_N(DEFINE_MEMBER_CLASS::Name, Type Name)
#define DEFINE_MEMBER_B_ARRAY(Type, Name, Count)DEFINE_MEMBER_N(DEFINE_MEMBER_CLASS::Name, Type Name[Count])
// Operators
#define DEFINE_OPERATOR_ARROW(Retn, Code)		inline Retn operator-> Code
#define DEFINE_OPERATOR_ARRAY(Retn, Code)		inline Retn operator[] Code
// Propertys
#define FUNCTION_PROPERTY(Type, Name)			inline Type Property_Get_##Name()
#define READONLY_PROPERTY(Type, Name)			__declspec(property(get = Property_Get_##Name)) Type Name; FUNCTION_PROPERTY(Type, Name)
// Functions Call
#define CALL_THISCALL(Address, Retn, ...)		((Retn(__thiscall*)(__VA_ARGS__))Address)
#define CALL_FASTCALL(Address, Retn, ...)		((Retn(__fastcall*)(__VA_ARGS__))Address)
#define CALL_STDCALL(Address, Retn, ...)		((Retn(__stdcall*)(__VA_ARGS__))Address)
#define CALL_CDECL(Address, Retn, ...)			((Retn(__cdecl*)(__VA_ARGS__))Address)
};