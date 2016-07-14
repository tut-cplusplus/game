#ifndef _COMPONENT
#define _COMPONENT

class Component {
protected:
  int width;	//コンポーネントの幅
  int height;	//コンポーネントの高さ

public:
  Component();
  Component(int width, int height);
  virtual ~Component();

  /**
   * アクセッサ
   */
  int getWidth(void) const;
  int getHeight(void) const;
  virtual void setWidth(int width);
  virtual void setHeight(int height);

  /**
   * コンストラクタに共通する処理を書く
   */
  virtual void init(void);
  /**
   * 描画関数
   */
  virtual void draw(void);
  /**
   * GLUTのイベントプロシージャ
   */
  virtual void mouse(int button, int state, int x, int y);
  virtual void keyboard(unsigned char key, int x, int y);
  virtual void keyboardOnce(unsigned char key, int x, int y);
  virtual void keyboardup(unsigned char key, int x, int y);
  virtual void keyboardupOnce(unsigned char key, int x, int y);
  virtual void special(int key, int x, int y);
  virtual void specialOnce(int key, int x, int y);
  virtual void specialup(int key, int x, int y);
  virtual void specialupOnce(int key, int x, int y);
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
