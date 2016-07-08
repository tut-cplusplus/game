#include <sstream>
#include <string>

#include "ComponentFPS.hpp"

#include <GL/glut.h>

#ifndef __GNUG__
  #include <windows.h>
#else
  #include <time.h>
  #include <sys/time.h>
  #include <unistd.h>
#endif

void DrawString(std::string str, int w, int h);

double ComponentFPS::getTime(void) const
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

void ComponentFPS::sleep(double seconds) const
{
#ifndef __GNUG__
	Sleep((int)(seconds * 1000));
#else
	usleep((unsigned)(seconds * 1000000));
#endif
}

ComponentFPS::ComponentFPS()
{
  return ;
}

ComponentFPS::ComponentFPS(int width, int height) : Component(width, height)
{
  count = 0;
  now_fps = 0;
  number_of_sample = 60;
  set_fps = 60.0;

  return ;
}

ComponentFPS::~ComponentFPS()
{
  return ;
}

void ComponentFPS::draw()
{
    if (count == 0) {
		start = getTime();
		waitTimeSum = 0.0;
    }

    if (count == number_of_sample) {
		end = getTime();

      now_fps = 1.0 / (end - start) * (double)number_of_sample;
	  utilization = (1 - waitTimeSum) * 100;
	  waitTimeSum = 0.0;
      count = 0;
	  start = getTime();
    }

    count ++;

    std::ostringstream oss;
    oss << "fps : " << (int)now_fps << " (utilization : " << (int)utilization << "%)";

    DrawString(oss.str(), width, height);

	double tmp = getTime();
	double took_time = tmp - start;
    double wait_time = (double)count / set_fps - took_time;

    if (wait_time > 0) {
		waitTimeSum += wait_time;
		sleep(wait_time);
    }

  return ;
}

void DrawString(std::string str, int w, int h)
{
  glColor3d(1.0, 1.0, 1.0);
  glRasterPos2f(w, h);
  int size = (int)str.size();
  for(int i = 0; i < size; ++i){
      char ic = str[i];
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ic);
  }

  return ;
}
