CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

s21_cat:
	$(CC) $(CFLAGS) main_1_3.c parser_arguments.c option_func.c -o s21_cat

run:
	$(shell ./bash_cat_test.sh)

clean:
	rm -rf *.o

style:
	clang-format -i --style=Google *.c *.h

rebuild:
	$(MAKE) clean
	$(MAKE) s21_cat


.PHONY: s21_cat run clean rebuild
