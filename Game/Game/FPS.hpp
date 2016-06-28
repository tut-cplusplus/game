#ifndef _FPS
#define _FPS

#include "Component.hpp"
#include <time.h>
#include <sys/time.h>

// TODO: width, heightの解決
// TODO: コメントを書く
// TODO: setFPS()などの機能拡張

class FPS : public Component{
public:
  FPS();
  FPS(int width, int height);
  ~FPS();

  void draw();

private:
  timeval start;
  timeval end;
  int count;
  double now_fps;
  int number_of_sample;
  double set_fps;

};

#endif
