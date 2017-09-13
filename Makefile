all: main
main:
	gcc -std=c99 -Wall -pedantic main.c P11.c P12.c P21.c P22.c -o main
