TARGET = main
CFLAGS = -Wall -g
all:
	gcc -c tareaso.c $(CFLAGS)
	gcc tareaso.o -o $(TARGET) $(CFLAGS)
	make clear

run: all
	./$(TARGET)

clear:
	find . -name '*.o' -type f -delete
