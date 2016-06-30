#ifndef _COMPONENT
#define _COMPONENT

class Component {
protected:
  int width;
  int height;

public:
  Component();
  Component(int width, int height);
  virtual ~Component();

  int getWidth(void) const;
  int getHeight(void) const;
  virtual void setWidth(int width);
  virtual void setHeight(int height);

  virtual void init(void);
  virtual void draw(void);
  virtual void mouse(int button, int state, int x, int y);
  virtual void keyboard(unsigned char key, int x, int y);
  virtual void keyboardup(unsigned char key, int x, int y);
  virtual void special(int key, int x, int y);
  virtual void specialup(int key, int x, int y);
};

inline int Component::getWidth(void) const
{
	return width;
}

inline int Component::getHeight(void) const
{
	return height;
}

#endif
