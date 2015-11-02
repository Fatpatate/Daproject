## Simple SDL mini code
CC=clang

CPPFLAGS= `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image

SRC= Database.c
OBJ= ${SRC:.c=.o}

all: Database

Database: ${OBJ}

clean:
	rm -f *~ *.o
	rm -f Database

# END
