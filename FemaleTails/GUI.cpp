#include "pch.h"

Trampoline* LoadRegObjTextures_t = nullptr;
Trampoline* FreeRegObjTexlists_t = nullptr;

static NJS_TEXNAME MILLIEGUI_TEXNAME[2] = {};
static NJS_TEXLIST MILLIEGUI_TEXLIST = { arrayptrandlengthT(MILLIEGUI_TEXNAME, int) };

static void __cdecl LoadRegObjTextures_r(int a1)
{
	LoadPVM("MILLIEGUI", &MILLIEGUI_TEXLIST);
	((decltype(LoadRegObjTextures_r)*)LoadRegObjTextures_t->Target())(a1);
}

static void __cdecl FreeRegObjTexlists_r()
{
	njReleaseTexture(&MILLIEGUI_TEXLIST);
	((decltype(FreeRegObjTexlists_r)*)FreeRegObjTexlists_t->Target())();
}

void Icons_Init()
{
	LoadRegObjTextures_t = new Trampoline(0x4212E0, 0x4212E5, LoadRegObjTextures_r, false);
	FreeRegObjTexlists_t = new Trampoline(0x420F40, 0x420F45, FreeRegObjTexlists_r, false);
}