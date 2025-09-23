CC=gcc
CFLAGS=-O2 -Wall `sdl-config --cflags`
LIBS=`sdl-config --libs` -lm -lSDL_ttf

SRC_PATH=graphics/
GRAPHICS=$(SRC_PATH)graphics.h
POLICE=$(SRC_PATH)police.h

%: $(SRC_PATH)graphics.o %.c
	rm -f $@
	$(CC) $(CFLAGS) $(SRC_PATH)graphics.o $@.c -o $@ $(LIBS)

$(SRC_PATH)graphics.o: $(SRC_PATH)graphics.c $(GRAPHICS)
	rm -f $(POLICE)
	touch $(POLICE)
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > $(POLICE); fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > $(POLICE); fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > $(POLICE); fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > $(POLICE); fi
	$(CC) $(CFLAGS) -c $(SRC_PATH)graphics.c

clean:
	rm -f $(SRC_PATH)*core
	rm -f $(SRC_PATH)*.o
	rm -f $(POLICE)
	rm -f $(SRC_PATH)exemple
	rm -f $(SRC_PATH)*.tar
