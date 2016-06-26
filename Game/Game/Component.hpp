#ifndef _COMPONENT
#define _COMPONENT

class Component {
private:
  int width;
  int height;

public:
  Component();
  Component(int width, int height);
  ~Component();

  virtual void init(void);
  virtual void display(void);
  virtual void keyboard(unsigned char key, int x, int y);
  virtual void resize(int w, int h);
  virtual void mouse(int button, int state, int x, int y);
  virtual void keyboard(unsigned char key, int x, int y);
  virtual void keyboardup(unsigned char key, int x, int y);
  virtual void special(int key, int x, int y);
  virtual void specialup(int key, int x, int y);
  virtual void idle(void);
};

#endif
