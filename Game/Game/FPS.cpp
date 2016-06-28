#include "FPS.hpp"
#include <unistd.h>
#include <GL/glut.h>
#include <sstream>
#include <string>

void DrawString(std::string str, int w, int h);

FPS::FPS()
{
  return ;
}

FPS::FPS(int width, int height) : Component(width, height)
{
  count = 0;
  now_fps = 0;
  number_of_sample = 60;
  set_fps = 60.0;

  return ;
}

FPS::~FPS()
{
  return ;
}

void FPS::draw()
{
  if (count == 0) {
    gettimeofday(&start, NULL);
  }

  if (count == number_of_sample) {
    gettimeofday(&end, NULL);

    now_fps = 1.0 / ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0) * (double)number_of_sample;
    count = 0;
    gettimeofday(&start, NULL);
  }

  count ++;

  std::ostringstream oss;
  oss << "fps : " << (int)now_fps;

  DrawString(oss.str(), width, height);

  timeval tmp;
  gettimeofday(&tmp, NULL);
  double took_time = (tmp.tv_sec - start.tv_sec) + (tmp.tv_usec - start.tv_usec) / 1000000.0;
  double wait_time = (double)count / set_fps - took_time;
  if (wait_time > 0) {
    usleep(wait_time * 1000000);
  }

  return ;
}

void DrawString(std::string str, int w, int h)
{
  glRasterPos2f(w, h);
  int size = (int)str.size();
  for(int i = 0; i < size; ++i){
      char ic = str[i];
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ic);
  }

  return ;
}
