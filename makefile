Mario : main.o init.o map.o
	gcc -o Mario main.o init.o map.o `sdl2-config --cflags --libs` -lSDL2_image -I ./includes

main.o : ./src/main.c
	gcc -o main.o ./src/main.c `sdl2-config --cflags --libs` -lSDL2_image -I ./includes

init.o : init.c
	gcc -o init.o ./src/init.c `sdl2-config --cflags --libs` -lSDL2_image -I ./includes

map.o : map.c
	gcc -o map.o ./src/map.c `sdl2-config --cflags --libs` -lSDL2_image -I ./includes