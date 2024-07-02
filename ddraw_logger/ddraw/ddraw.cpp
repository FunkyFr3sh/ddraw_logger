// Copyright (c) 2014 Jérémy Ansel
// Licensed under the MIT license. See LICENSE.txt

#include "common.h"
#include "LibraryLoader.h"
#include "DirectDraw.h"
#include "DirectDrawClipper.h"


static LibraryLoader ddraw("ddraw.dll");

extern "C" HRESULT WINAPI DirectDrawCreate(
	_In_   GUID FAR *lpGUID,
	_Out_  LPDIRECTDRAW FAR *lplpDD,
	_In_   IUnknown FAR *pUnkOuter
	)
{
	static auto ddraw_proc = (decltype(DirectDrawCreate)*)ddraw.GetAddress("DirectDrawCreate");

	std::ostringstream str;
	str << __FUNCTION__;
	str << tostr_GUID(lpGUID);

	HRESULT hr = ddraw_proc(lpGUID, lplpDD, pUnkOuter);

	if (SUCCEEDED(hr))
	{
		*lplpDD = CreateWrapperT(DirectDraw, *lplpDD);
	}

	str << std::endl;
	str << tostr_HR(hr);

	if (lplpDD)
	{
		str << " " << *lplpDD;
	}

	LogText(str.str());
	return hr;
}

extern "C" HRESULT WINAPI DirectDrawCreateClipper(
	_In_   DWORD dwFlags,
	_Out_  LPDIRECTDRAWCLIPPER FAR *lplpDDClipper,
	_In_   IUnknown FAR *pUnkOuter
	)
{
	static auto ddraw_proc = (decltype(DirectDrawCreateClipper)*)ddraw.GetAddress("DirectDrawCreateClipper");

	std::ostringstream str;
	str << __FUNCTION__;

	HRESULT hr = ddraw_proc(dwFlags, lplpDDClipper, pUnkOuter);

	if (SUCCEEDED(hr))
	{
		*lplpDDClipper = CreateWrapperT(DirectDrawClipper, *lplpDDClipper);
	}

	str << std::endl;
	str << tostr_HR(hr);

	if (lplpDDClipper)
	{
		str << " " << *lplpDDClipper;
	}

	LogText(str.str());
	return hr;
}

extern "C" HRESULT WINAPI DirectDrawCreateEx(
	_In_   GUID FAR *lpGUID,
	_Out_  LPVOID *lplpDD,
	_In_   REFIID iid,
	_In_   IUnknown FAR *pUnkOuter
	)
{
	static auto ddraw_proc = (decltype(DirectDrawCreateEx)*)ddraw.GetAddress("DirectDrawCreateEx");

	std::ostringstream str;
	str << __FUNCTION__;
	str << tostr_GUID(&iid);

	str << std::endl;
	str << "\tNOT WRAPPED";

	HRESULT hr = ddraw_proc(lpGUID, lplpDD, iid, pUnkOuter);

	str << std::endl;
	str << tostr_HR(hr);

	LogText(str.str());
	return hr;
}

static LPDDENUMCALLBACKA s_lpEnumerateACallback;

static BOOL CALLBACK EnumerateACallback(GUID* lpGUID, LPSTR lpDriverDescription, LPSTR lpDriverName, LPVOID lpContext)
{
	std::ostringstream str;
	str << "\t" << lpDriverName << "\t" << lpDriverDescription;
	str << "\t" << tostr_GUID(lpGUID);
	str << " " << lpContext;

	LogText(str.str());

	return s_lpEnumerateACallback(lpGUID, lpDriverDescription, lpDriverName, lpContext);
}

extern "C" HRESULT WINAPI DirectDrawEnumerateA(
	_In_  LPDDENUMCALLBACKA lpCallback,
	_In_  LPVOID lpContext
	)
{
	static auto ddraw_proc = (decltype(DirectDrawEnumerateA)*)ddraw.GetAddress("DirectDrawEnumerateA");

	std::ostringstream str;
	str << __FUNCTION__;

	LogText(str.str());

	s_lpEnumerateACallback = lpCallback;

	HRESULT hr = ddraw_proc(EnumerateACallback, lpContext);

	LogText(tostr_HR(hr));

	return hr;
}

static LPDDENUMCALLBACKEXA s_lpEnumerateExACallback;

static BOOL CALLBACK EnumerateExACallback(GUID* lpGUID, LPSTR lpDriverDescription, LPSTR lpDriverName, LPVOID lpContext, HMONITOR hm)
{
	std::ostringstream str;
	str << "\t" << lpDriverName << "\t" << lpDriverDescription;
	str << "\t" << tostr_GUID(lpGUID);
	str << " " << lpContext;
	str << " " << hm;

	LogText(str.str());

	return s_lpEnumerateExACallback(lpGUID, lpDriverDescription, lpDriverName, lpContext, hm);
}

extern "C" HRESULT WINAPI DirectDrawEnumerateExA(
	_In_  LPDDENUMCALLBACKEXA lpCallback,
	_In_  LPVOID lpContext,
	_In_  DWORD dwFlags
	)
{
	static auto ddraw_proc = (decltype(DirectDrawEnumerateExA)*)ddraw.GetAddress("DirectDrawEnumerateExA");

	std::ostringstream str;
	str << __FUNCTION__;
	str << " " << lpContext;

	STR_ENUM(dwFlags, DDENUM, ATTACHEDSECONDARYDEVICES);
	STR_ENUM(dwFlags, DDENUM, DETACHEDSECONDARYDEVICES);
	STR_ENUM(dwFlags, DDENUM, NONDISPLAYDEVICES);

	LogText(str.str());

	s_lpEnumerateExACallback = lpCallback;

	HRESULT hr = ddraw_proc(EnumerateExACallback, lpContext, dwFlags);

	LogText(tostr_HR(hr));

	return hr;
}

extern "C" HRESULT WINAPI DirectDrawEnumerateExW(
	_In_  LPDDENUMCALLBACKEXW lpCallback,
	_In_  LPVOID lpContext,
	_In_  DWORD dwFlags
	)
{
	static auto ddraw_proc = (decltype(DirectDrawEnumerateExW)*)ddraw.GetAddress("DirectDrawEnumerateExW");

	std::ostringstream str;
	str << __FUNCTION__;
	str << " " << lpContext;

	STR_ENUM(dwFlags, DDENUM, ATTACHEDSECONDARYDEVICES);
	STR_ENUM(dwFlags, DDENUM, DETACHEDSECONDARYDEVICES);
	STR_ENUM(dwFlags, DDENUM, NONDISPLAYDEVICES);

	str << std::endl;
	str << "\tNOT WRAPPED";

	HRESULT hr = ddraw_proc(lpCallback, lpContext, dwFlags);

	str << std::endl;
	str << tostr_HR(hr);

	LogText(str.str());
	return hr;
}

extern "C" HRESULT WINAPI DirectDrawEnumerateW(
	_In_  LPDDENUMCALLBACKW lpCallback,
	_In_  LPVOID lpContext
	)
{
	static auto ddraw_proc = (decltype(DirectDrawEnumerateW)*)ddraw.GetAddress("DirectDrawEnumerateW");

	std::ostringstream str;
	str << __FUNCTION__;
	str << " " << lpContext;

	str << std::endl;
	str << "\tNOT WRAPPED";

	HRESULT hr = ddraw_proc(lpCallback, lpContext);

	str << std::endl;
	str << tostr_HR(hr);

	LogText(str.str());
	return hr;
}

