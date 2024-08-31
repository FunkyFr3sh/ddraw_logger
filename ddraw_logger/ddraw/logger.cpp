// Copyright (c) 2014 Jérémy Ansel
// Licensed under the MIT license. See LICENSE.txt

#include "logger.h"

#include <windows.h>
#include <fstream>
#include <sstream>
#include <ctime>

clock_t g_startTime = clock();

std::ofstream g_file;

void InitLogFile()
{
	if (g_file.is_open())
	{
		return;
	}

	std::ofstream file;
	file.open("ddraw_log.txt");

	if (file.is_open())
	{
		file.close();
	}

	g_file.open("ddraw_log.txt", std::ios::app);
}

void LogText(std::string text)
{
	InitLogFile();

	int currentTime = clock() - g_startTime;

	std::ostringstream str;
	//str << currentTime << '\t' << text.c_str() << std::endl;

	SYSTEMTIME st;
	GetLocalTime(&st);
	char datetime[64];
	sprintf(
		datetime,
		"[%lu] %02d:%02d:%02d.%03d ",
		GetCurrentThreadId(),
		st.wHour,
		st.wMinute,
		st.wSecond,
		st.wMilliseconds);

	str << datetime << '\t' << text.c_str() << std::endl;

	g_file << str.str();
	g_file.flush();
}
