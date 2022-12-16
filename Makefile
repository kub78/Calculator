TARGET = main
.PHONY: all, clear, run
all: $(TARGET)
run: $(TARGET)
	./$(TARGET)
clean:
	rm $(TARGET) *.o
main: main.o funcs.o
	gcc main.o funcs.o -o $(TARGET)
main.o: main.c
	gcc -c main.c
funcs.o: funcs.c
	gcc -c funcs.c
