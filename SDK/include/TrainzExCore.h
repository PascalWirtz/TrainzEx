#ifndef __TRAINZEX__CORE__H
#define __TRAINZEX__CORE__H

#ifndef _WIN64
	#error Trainz is x64 only!
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _STL_WARNINGS_LEVEL
	#define _STL_WARNINGS_LEVEL			3
#endif

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif

#pragma comment						(lib,  "TrainzExCore.lib")
#define TrainzExCoreAPI				__declspec(dllimport)

#include <Windows.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "TrainzExTypes.h"
#include "TrainzExVersion.h"
#include "TrainzExMemory.h"
#include "TrainzExTrainzMessage.h"
#include "TrainzExPlugin.h"
#include "TrainzExContext.h"

#endif