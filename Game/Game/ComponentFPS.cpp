#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "ComponentFPS.hpp"
#include "FPSManager.hpp"

#include <GL/glut.h>

using namespace std;

void DrawString(std::string str, int w, int h);

ComponentFPS::ComponentFPS()
{
  return ;
}

ComponentFPS::ComponentFPS(int width, int height) : Component(width, height)
{
  return ;
}

ComponentFPS::~ComponentFPS()
{
  return ;
}

void ComponentFPS::draw()
{
	std::ostringstream oss;
	oss << "fps : " << (int)FPSManager::getFPS() << " (utilization : " << fixed << setprecision(1) << FPSManager::getUtilization() << "%)";

	DrawString(oss.str(), width, height);
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
