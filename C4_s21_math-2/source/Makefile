GCCFLAGS = -Wall -Werror -Wextra -std=c11
UNAME = $(shell uname -s)
FLAGS =

ifeq ($(UNAME), Linux)
	FLAGS += -lcheck -lm -lsubunit -lrt -lpthread
else
	FLAGS += -lcheck
endif

GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: s21_math.a test

s21_math.a: clean
	gcc $(GCCFLAGS) -c s21_*.c
	ar rc s21_math.a *.o
	mkdir binary_files
	mv *.o binary_files

gcov_report: s21_math.a 
	gcc $(GCCFLAGS) $(FLAGS) $(GCOVFLAGS) *.c -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	rm -rf gcovreport* *.gcda *.gcno
	open report/index.html

test: s21_math.a
	gcc $(GCCFLAGS) $(FLAGS) main.c s21_math.a -o test
	./test

style:
	clang-format -i --style=Google *.c *.h

clean:
	rm -rf *.o binary_files report test gcovreport* *.gcda *.gcno *.a s21_math.a
