ANIMATIONGENERATOR_OBJS=AnimationGenerator.o
ANIMATIONGENERATOR_OBJPATHS=$(addprefix $(BUILDPATH)/, $(ANIMATIONGENERATOR_OBJS))
CPPFLAGS=$(INCLUDE) -Wall -std=c++14 -MMD
LDFLAGS=-lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_adas -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_datasets -lopencv_face -lopencv_latentsvm -lopencv_objdetect -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_surface_matching -lopencv_text -lopencv_tracking -lopencv_xfeatures2d -lopencv_calib3d -lopencv_features2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_flann -lopencv_ximgproc -lopencv_xobjdetect -lopencv_xphoto -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_photo -lopencv_imgproc -lopencv_core -lopencv_hal
BUILDPATH=./build

all : makefolder animationgenerator

$(BUILDPATH)/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -o $@ -c $<

animationgenerator : $(ANIMATIONGENERATOR_OBJPATHS) 
	$(CXX) -o AnimationGenerator $(LDFLAGS) $(ANIMATIONGENERATOR_OBJPATHS)

makefolder :
	@mkdir -p $(BUILDPATH)

clean :
	$(RM) AnimationGenerator 
	$(RM) -r -f $(BUILDPATH)

-include $(BUILDPATH)/*.d

