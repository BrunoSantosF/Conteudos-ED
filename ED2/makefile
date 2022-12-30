GCC = gcc
D_OBJ = ./object

O_FILES = *.o
C_FILES = *.c

make:
	@gcc -c ./src/*.c 
	@mkdir ./object
	@mv *.o ./object
	@gcc -o prog ./object/*.o -lm -pedantic -Wall
run :
	@./prog 
clean :
	@rm -rf ./object *.o ./include/*.gch prog
