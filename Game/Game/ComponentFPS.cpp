#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "ComponentFPS.hpp"
#include "FPSManager.hpp"
#include "FontManager.hpp"

#include <GL/glut.h>

using namespace std;

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

	glColor3d(1.0, 1.0, 1.0);
	FontManager::draw(oss.str(), width, height);
}

