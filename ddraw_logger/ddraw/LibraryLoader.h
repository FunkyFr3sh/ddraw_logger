// Copyright (c) 2014 Jérémy Ansel
// Licensed under the MIT license. See LICENSE.txt

#pragma once

#include "common.h"

class LibraryLoader
{
public:
	LibraryLoader(LPCSTR lpLibFileName)
	{
		this->_module = LoadLibraryA("ddrawx.dll");

		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat(path, "\\");
		strcat(path, lpLibFileName);

		this->_module = this->_module ? this->_module : LoadLibraryA(path);
	}

	~LibraryLoader()
	{
		if (this->_module)
		{
			FreeLibrary(this->_module);
		}
	}

	FARPROC GetAddress(LPCSTR lpProcName) const throw ()
	{
		return GetProcAddress(this->_module, lpProcName);
	}

private:
	HMODULE _module;
};


#pragma comment(linker, "/export:AcquireDDThreadLock=C:\\Windows\\System32\\ddraw.AcquireDDThreadLock,@1")
#pragma comment(linker, "/export:CompleteCreateSysmemSurface=C:\\Windows\\System32\\ddraw.CompleteCreateSysmemSurface,@2")
#pragma comment(linker, "/export:D3DParseUnknownCommand=C:\\Windows\\System32\\ddraw.D3DParseUnknownCommand,@3")
#pragma comment(linker, "/export:DDGetAttachedSurfaceLcl=C:\\Windows\\System32\\ddraw.DDGetAttachedSurfaceLcl,@4")
#pragma comment(linker, "/export:DDInternalLock=C:\\Windows\\System32\\ddraw.DDInternalLock,@5")
#pragma comment(linker, "/export:DDInternalUnlock=C:\\Windows\\System32\\ddraw.DDInternalUnlock,@6")
#pragma comment(linker, "/export:DSoundHelp=C:\\Windows\\System32\\ddraw.DSoundHelp,@7")

#pragma comment(linker, "/export:DirectDrawCreate=C:\\Windows\\System32\\ddraw.DirectDrawCreate,@8")
#pragma comment(linker, "/export:DirectDrawCreateClipper=C:\\Windows\\System32\\ddraw.DirectDrawCreateClipper,@9")
#pragma comment(linker, "/export:DirectDrawCreateEx=C:\\Windows\\System32\\ddraw.DirectDrawCreateEx,@10")
#pragma comment(linker, "/export:DirectDrawEnumerateA=C:\\Windows\\System32\\ddraw.DirectDrawEnumerateA,@11")
#pragma comment(linker, "/export:DirectDrawEnumerateExA=C:\\Windows\\System32\\ddraw.DirectDrawEnumerateExA,@12")
#pragma comment(linker, "/export:DirectDrawEnumerateExW=C:\\Windows\\System32\\ddraw.DirectDrawEnumerateExW,@13")
#pragma comment(linker, "/export:DirectDrawEnumerateW=C:\\Windows\\System32\\ddraw.DirectDrawEnumerateW,@14")

#pragma comment(linker, "/export:GetDDSurfaceLocal=C:\\Windows\\System32\\ddraw.GetDDSurfaceLocal,@17")
#pragma comment(linker, "/export:GetOLEThunkData=C:\\Windows\\System32\\ddraw.GetOLEThunkData,@18")
#pragma comment(linker, "/export:GetSurfaceFromDC=C:\\Windows\\System32\\ddraw.GetSurfaceFromDC,@19")
#pragma comment(linker, "/export:RegisterSpecialCase=C:\\Windows\\System32\\ddraw.RegisterSpecialCase,@20")
#pragma comment(linker, "/export:ReleaseDDThreadLock=C:\\Windows\\System32\\ddraw.ReleaseDDThreadLock,@21")
#pragma comment(linker, "/export:SetAppCompatData=C:\\Windows\\System32\\ddraw.SetAppCompatData,@22")
