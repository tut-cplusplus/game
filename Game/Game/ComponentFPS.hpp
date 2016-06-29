#ifndef _ComponentFPS
#define _ComponentFPS

#include "Component.hpp"
#ifndef __GNUG__
  #include <windows.h>
#else
  #include <time.h>
  #include <sys/time.h>
  #include <unistd.h>
#endif

// TODO: width, heightの解決
// TODO: コメントを書く
// TODO: setFPS()などの機能拡張

class ComponentFPS : public Component{
public:
  ComponentFPS();
  ComponentFPS(int width, int height);
  ~ComponentFPS();

  void draw();

private:
  #ifndef __GNUG__
    SYSTEMTIME start;
    SYSTEMTIME end;
  #else
    timeval start;
    timeval end;
  #endif

  int count;
  double now_fps;
  int number_of_sample;
  double set_fps;

};

#endif
