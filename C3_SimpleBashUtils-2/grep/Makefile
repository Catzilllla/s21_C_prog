CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

s21_grep:
	$(CC) $(CFLAGS) main_grep_1_2.c parser_arguments.c option_grep_func.c -o s21_grep

run:
	$(shell ./bash_2v_grep_test.sh)

style:
	clang-format -i --style=Google *.c *.h

clean:
	rm -rf *.o

rebuild:
	$(MAKE) clean
	$(MAKE) s21_grep


.PHONY: s21_grep run clean rebuild
