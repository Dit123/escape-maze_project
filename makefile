CC = gcc
CFLAGS = -Wall -O2

all: main game_story

main: main.c
	gcc	main.c	-o	main

game_story: game_story.c
	gcc	game_story.c	-o	game_story

clean:
	rm	-f	main	game_story

