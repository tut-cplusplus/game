#ifndef _ComponentFPS
#define _ComponentFPS

#include "Component.hpp"

// TODO: width, heightの解決
// TODO: コメントを書く
// TODO: setFPS()などの機能拡張

class ComponentFPS : public Component{
private:
	double getTime(void) const;
	void sleep(double seconds) const;

public:
  ComponentFPS();
  ComponentFPS(int width, int height);
  ~ComponentFPS();

  void draw();

private:
  double start;
  double end;

  int count;
  double now_fps;
  int number_of_sample;
  double set_fps;

};

#endif
