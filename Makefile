CXX		  := g++
MAIN_FILE:= ./main.cpp
SRC_FILES := $(wildcard src/lycoris/*.cpp src/lycoris/*/*.cpp sample/sphere_scene.cpp)
SAMPLE_FILES := $(wildcard samples/*.cpp)
OBJ_FILES := $(SRC_FILES:.cpp=.o)
CXX_FLAGS := -std=gnu++1z -Iinclude -Iextern -O3
MAKE      := make

all: lycoris 
lycoris: $(OBJ_FILES)
	$(CXX) $(CXX_FLAGS) -o lycoris $(OBJ_FILES) $(MAIN_FILE)
%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c -g -o $@ $<
sphere_scene: $(OBJ_FILES)
	$(CXX) $(CXX_FLAGS) -o sphere_scene.out $(OBJ_FILES) samples/sphere_scene.cpp

clean:
	rm -f lycoris
	rm -f *.out
	rm -f *.o */*.o src/lycoris/*/*.o src/lycoris/*.o  
	rm -f render.bmp
