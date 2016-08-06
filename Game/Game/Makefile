OBJS=Main.o Image.o Character.o Player.o Enemy.o Decoy.o NormalEnemy.o Component.o ComponentTeapot.o ComponentTexture.o ComponentFPS.o ComponentGame.o Layout.o RelativeLayout.o SplitLayout.o VerticalSplitLayout.o HorizontalSplitLayout.o Block.o BlockAir.o BlockNormalWall.o BlockWall.o BlockUnbreakableWall.o BlockTrap.o BlockBrokenTrap.o TextureManager.o LayoutManager.o FPSManager.o FontManager.o Key.o SpecialKey.o Keypad.o CircularSector.o Information.o Rectangle.o Animation.o ItemBlock.o Audio.o Global.o
OBJPATHS=$(addprefix $(BUILDPATH)/, $(OBJS))
CPPFLAGS=$(INCLUDE) -Wall -std=c++14 -MMD
LDFLAGS=-lglut -lGLU -lGL -lopenal -lalut
BUILDPATH=./build

all : makefolder $(OBJPATHS)
	$(CXX) -o Main $(LDFLAGS) $(OBJPATHS)

$(BUILDPATH)/%.o : %.cpp
	@mkdir -p $(dir $@)
	ccache $(CXX) $(CPPFLAGS) -o $@ -c $<

makefolder:
	@mkdir -p $(BUILDPATH)

clean :
	$(RM) *.o
	$(RM) Main
	$(RM) -r -f $(BUILDPATH)

-include $(BUILDPATH)/*.d

