CFLAGS=-Wall -Wextra -Werror -std=c11

all: clean house travel

house: house.c
	gcc $(CFLAGS) house.c -o ../bin/house

travel: travel.c
	gcc $(CFLAGS) travel.c -o ../bin/travel

clean:
	rm -rf *.o *.a  ../bin/*

check:
	clang-format -n *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c 
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes -s ../bin/travel
# test:
# 	pytest --color=yes -v --tb=short tests 
