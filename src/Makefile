CC = gcc
CFLAGS = -O2 -Wall `sdl-config --cflags`
LIBS = `sdl-config --libs` -lm -lSDL_ttf

SRC_PATH = graphics/
LIB_PATH = lib/

GRAPHICS_H = $(SRC_PATH)graphics.h
POLICE_H = $(SRC_PATH)police.h

GRAPHICS_OBJ = $(SRC_PATH)graphics.o
LINKED_LIST_OBJ = $(LIB_PATH)linked_list.o
MAP_OBJ = $(LIB_PATH)map.o


main: $(GRAPHICS_OBJ) $(LINKED_LIST_OBJ) $(MAP_OBJ) main.c
	$(CC) $(CFLAGS) $(GRAPHICS_OBJ) $(LINKED_LIST_OBJ) $(MAP_OBJ) main.c -o main $(LIBS)

$(GRAPHICS_OBJ): $(SRC_PATH)graphics.c $(GRAPHICS_H)
	rm -f $(POLICE_H)
	touch $(POLICE_H)
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > $(POLICE_H); fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > $(POLICE_H); fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > $(POLICE_H); fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > $(POLICE_H); fi
	$(CC) $(CFLAGS) -c $(SRC_PATH)graphics.c

$(LINKED_LIST_OBJ): $(LIB_PATH)linked_list.c $(LIB_PATH)linked_list.h
	$(CC) $(CFLAGS) -c $(LIB_PATH)linked_list.c -o $(LINKED_LIST_OBJ)

$(MAP_OBJ): $(LIB_PATH)map.c $(LIB_PATH)map.h
	$(CC) $(CFLAGS) -c $(LIB_PATH)map.c -o $(MAP_OBJ)

clean:
	rm -f $(SRC_PATH)*core
	rm -f $(SRC_PATH)*.o
	rm -f $(LIB_PATH)*.o
	rm -f $(POLICE_H)
	rm -f main
	rm -f $(SRC_PATH)*.tar
