CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
GCOV_FLAG = -fprofile-arcs -ftest-coverage -fPIC -O0
GCOV_FLAG_TEST = --coverage
TEST_FLAG = -lcheck
LINUX_FLAG = -lm -lsubunit -lrt -lpthread
OPEN = open

ifeq ($(shell uname), Linux)
	TEST_FLAG += $(LINUX_FLAG)
endif

ifeq ($(shell uname), Linux)
	OPEN = firefox
endif

SOURCES_1 = calc.c pars.c stack.c credit_calc.c
OBJECTS_1 = calc.o pars.o stack.o credit_calc.o
SOURCES_2 = test/test.c
OBJECTS_2 = test.o

.PHONY: all
all: clean

.PHONY: install
install: clean
	mkdir calculator
	cd calculator; cmake ../
	cd calculator; make
	cd ..
	mv calculator/Calculator .
	rm -R calculator
	./Calculator

.PHONY: uninstall
uninstall: 
	-rm -rf Calculator

dvi:
	$(OPEN) docs.html

.PHONY: dist
dist: 
	-rm -rf *.tar.gz
	tar -czvf Calculator.tar.gz Calculator

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

.PHONY: tests
tests: clean test_calc.a
	$(CC) $(CFLAGS) -c $(SOURCES_2)
	$(CC) $(CFLAGS) $(GCOV_FLAG_TEST) -o tests $(OBJECTS_2) calc.a $(TEST_FLAG)
	-rm -rf *.o
	./tests

.PHONY: gcov_report
gcov_report: clean tests
	gcovr -r . --html-details -o report_calc.html

.PHONY: clean
clean:
	-rm -rf *.o *.a *.out *.gcda *.gcno *.html *.css *.tar.gz
	-rm -rf tests Calculator
