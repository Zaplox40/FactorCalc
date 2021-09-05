all:fourth

first: fourth.o
	gcc -Wall -Werror -fsanitize=address -std=c11 -g -o fourth fourth.o

clean:
	rm -rf fourth.o fourth
	
