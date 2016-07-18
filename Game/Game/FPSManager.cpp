#include <iostream>

#include "FPSManager.hpp"

#ifndef __GNUG__
	#include <windows.h>
#else
	#include <time.h>
	#include <sys/time.h>
	#include <unistd.h>
#endif

using namespace std;

double FPSManager::start;
double FPSManager::startTmp;
double FPSManager::end;

int FPSManager::count = 0;
double FPSManager::nowFps = 60;
int FPSManager::numberOfSample = 60;
double FPSManager::setFps = 60;
double FPSManager::processTime;
double FPSManager::processTimeSum = 0.0;
double FPSManager::utilization = 0.0;

double FPSManager::getTime(void)
{
	double time;
#ifndef __GNUG__
	SYSTEMTIME stime;
	GetSystemTime(&stime);
	time = (stime.wHour * 60.0 + stime.wMinute) * 60.0 + stime.wSecond + stime.wMilliseconds / 1000.0;
#else
	timeval tval;
	gettimeofday(&tval, NULL);
	time = tval.tv_sec + tval.tv_usec / 1000000.0;
#endif
	return time;
}

void FPSManager::sleep(double seconds)
{
#ifndef __GNUG__
	Sleep((DWORD)(seconds * 1000));
#else
	usleep(seconds * 1000000);
#endif
}

void FPSManager::startMeasure(void)
{
	startTmp = getTime();
}

void FPSManager::stopMeasure(void)
{
	end = getTime();
	processTime = end - startTmp;
	processTimeSum += processTime;
}

void FPSManager::update(void)
{
	if (count == 0) {
		start = getTime();
		processTimeSum = 0.0;
	}
	if (count == numberOfSample) {
		end = getTime();
		double time = end - start;
		nowFps = 1.0 / time * numberOfSample;
		utilization = processTimeSum / time * 100;
		start = getTime();
		processTimeSum = 0.0;
		count = 0;
	}
	count++;
}

void FPSManager::sleep(void)
{
	double waitTime = 1.0 / setFps - processTime;
	if (waitTime > 0.0)
		sleep(waitTime);
}

double FPSManager::getFPS(void)
{
	return nowFps;
}

double FPSManager::getUtilization(void)
{
	return utilization;
}

