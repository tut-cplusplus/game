#ifndef _COMPONENT
#define _COMPONENT

class Component {
private:
  int width;
  int height;

public:
  Component();
  ~Component();

  init();

  virtual void keyboard(unsigned char key, int x, int y);
};

#endif
