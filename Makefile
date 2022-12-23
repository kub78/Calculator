TARGET = main
.PHONY: all
.PHONY: clean
.PHONY: run
all: $(TARGET)
run: $(TARGET)
	./$(TARGET)
clean:
	rm $(TARGET) *.o
main: main.o Bin.o Hex.o Oct.o
	gcc main.o Bin.o Oct.o Hex.o -o $(TARGET)
main.o: main.c
	gcc -c main.c
Bin.o: Bin.c
	gcc -c Bin.c
Oct.o: Oct.c
	gcc -c Oct.c
Hex.o: Hex.c
	gcc -c Hex.c
