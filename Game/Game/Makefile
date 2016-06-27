OBJS=Main.o Image.o Character.o Component.o LayoutManager.o Layout.o Block.o BlockAir.o BlockNormalWall.o BlockWall.o RelativeLayout.o
CPPFLAGS=$(INCLUDE) -std=c++14
LDFLAGS=-lglut -lGLU -lGL

all : $(OBJS)
	$(CXX) -o Main $(LDFLAGS) $(OBJS)

clean :
	$(RM) *.o
	$(RM) Main

