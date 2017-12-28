EXEC = main.exe
SOURCES = main.cpp point3D.cpp color.cpp camera.cpp light.cpp pixel.cpp ray.cpp sphere.cpp scene.cpp screen.cpp shape.cpp vector3D.cpp 
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
