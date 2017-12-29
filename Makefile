EXEC = main.exe
SOURCES = main.cpp camera.cpp color.cpp light.cpp pixel.cpp point3D.cpp ray.cpp scene.cpp screen.cpp shape.cpp sphere.cpp vector3D.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
CC = g++
CFLAGS = -Wall -g -Wextra -Werror -std=c++11

.PHONY: default clean

default: $(EXEC)

%.o: %.cpp
	$(CC) $< $(CFLAGS) -o $@ -c

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -rf $(EXEC) $(OBJECTS) $(SOURCES:.cpp=.cpp~) $(SOURCES:.cpp=.hpp~) Makefile~
