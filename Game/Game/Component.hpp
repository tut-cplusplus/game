#ifndef _COMPONENT
#define _COMPONENT

class Component {
protected:
  int width;
  int height;

public:
  Component();
  Component(int width, int height);
  ~Component();

  int getWidth(void) const;
  int getHeight(void) const;
  void setWidth(int width);
  void setHeight(int height);

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

inline void Component::setWidth(int width)
{
	this->width = width;
}

inline void Component::setHeight(int height)
{
	this->height = height;
}

#endif
