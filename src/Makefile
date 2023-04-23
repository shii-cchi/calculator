CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
GCOV_FLAG = -fprofile-arcs -ftest-coverage -fPIC -O0
GCOV_FLAG_TEST = --coverage
TEST_FLAG = -lcheck
LINUX_FLAG = -lm -lsubunit -lrt -lpthread

ifeq ($(shell uname), Linux)
	TEST_FLAG += $(LINUX_FLAG)
endif

SOURCES_1 = calc.c pars.c stack.c credit_calc.c
OBJECTS_1 = calc.o pars.o stack.o credit_calc.o
SOURCES_2 = test/test.c
OBJECTS_2 = test.o

all: clean

install: clean
	rm -rf calculator
	mkdir calculator
	cd calculator; cmake ../
	cd calculator; make

uninstall: 
	rm -R calculator

# dvi:

dist: calc.a
	tar -czvf calc.tar.gz calc.a

calc.a: clean
	$(CC) $(CFLAGS) -c $(SOURCES_1)
	ar rc calc.a $(OBJECTS_1)
	ranlib calc.a
	-rm -rf *.o

test_calc.a: clean
	$(CC) $(CFLAGS) $(GCOV_FLAG) -c $(SOURCES_1)
	ar rc calc.a $(OBJECTS_1)
	ranlib calc.a
	-rm -rf *.o

tests: clean test_calc.a
	$(CC) $(CFLAGS) -c $(SOURCES_2)
	$(CC) $(CFLAGS) $(GCOV_FLAG_TEST) -o tests $(OBJECTS_2) calc.a $(TEST_FLAG)
	-rm -rf *.o
	./tests

gcov_report: clean tests
	gcovr -r . --html-details -o report_calc.html

# lcov: clean tests

clean:
	-rm -rf *.o *.a *.out *.gcda *.gcno *.html *.css *.tar.gz
	-rm -f tests
