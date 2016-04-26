.PHONY: all hello_triangle clean

all:
	make hello_triangle

hello_triangle:
	gcc hello_triangle/hello_triangle.c -o hello_triangle/hello_triangle -std=c11 -Wall -lglfw3 -lm -lGL -lGLU
