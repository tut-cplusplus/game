OBJS=Main.o
CPPFLAGS=$(INCLUDE) -std=c++14
LDFLAGS=-lglut -lGLU -lGL

all : $(OBJS)
	$(CXX) -o Main $(LDFLAGS) $(OBJS)

clean :
	$(RM) *.o
	$(RM) Main

