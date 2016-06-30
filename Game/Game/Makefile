OBJS=Main.o Image.o Character.o Component.o LayoutManager.o Layout.o Block.o BlockAir.o BlockNormalWall.o BlockWall.o RelativeLayout.o ComponentTeapot.o Player.o TextureManager.o ComponentTexture.o SplitLayout.o VerticalSplitLayout.o HorizontalSplitLayout.o ComponentFPS.o ComponentGame.o
OBJPATHS=$(addprefix $(BUILDPATH)/, $(OBJS))
CPPFLAGS=$(INCLUDE) -Wall -std=c++14 -MMD
LDFLAGS=-lglut -lGLU -lGL
BUILDPATH=./build

all : makefolder $(OBJPATHS)
	$(CXX) -o Main $(LDFLAGS) $(OBJPATHS)

$(BUILDPATH)/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -o $@ -c $<

makefolder:
	@mkdir -p $(BUILDPATH)

clean :
	$(RM) *.o
	$(RM) Main
	$(RM) -r -f $(BUILDPATH)

-include $(BUILDPATH)/*.d

