# Simple Makefile
# Practical session 01

# Global Compilation Variables

# The compiler
CC=@clang

# Pre-processor flags
CPPFLAGS= `pkg-config --cflags sdl` `pkg-config --cflags gtk+-2.0`


# C compiler flags
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3

# Linker flags
LDFLAGS=

# Linker libs
LDLIBS= `pkg-config --libs sdl` -lSDL_image -lm `pkg-config --libs gtk+-2.0`


# all target just call the production of main
all: main clean

# main target using implicit rules, just express dependencies
main: main.o NeuralSystem/Neuron/Neuron.o NeuralSystem/NeuralSystem.o NeuralSystem/neuralOperations.o NeuralSystem/executeSystem.o  Helper/mathsHelper.o Helper/arrayHelper.o ImageProcessing/imageProcessing.o ImageProcessing/pixelOperations.o ImageProcessing/startProcessing.o ImageProcessing/imageDivision.o ImageProcessing/TextBlock.o Interface/window.o ImageProcessing/learning.o ImageProcessing/recognition.o ImageProcessing/learnAndTry.o
.PHONY: clean

debug:
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDLIBS) */*.c *.c

# clean compilation products
clean:
	@echo "Cleaning up .o files"
	@find . -name "*.o" -type f -delete

# END of File
