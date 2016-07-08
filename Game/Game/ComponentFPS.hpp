#ifndef _ComponentFPS
#define _ComponentFPS

#include "Component.hpp"

// TODO: width, heightの解決
// TODO: コメントを書く
// TODO: setFPS()などの機能拡張

class ComponentFPS : public Component{
public:
  ComponentFPS();
  ComponentFPS(int width, int height);
  ~ComponentFPS();

  void draw();
};

#endif
