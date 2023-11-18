## s21_C_prog
Образовательный проект от Сбербанка "Школа 21"

### Разработка библиотек на С: cat, grep, math, string, decimal, matrix
### Разработка программ на С: калькулятор, 3Dviewer;

	## - SimpleBashUtils. Разработка программ на языке Си, собственная библиотека cat (флаги -b -e -n -s -t -v) и grep (флаги -e -i -v -c -l -n -h -s -f(file) -o)

	## - Math.h. Разработка программ на языке Си, функции библиотеки math.h
            - int abs(int x)
            - long double acos(double x)
            - long double asin(double x)
            - long double atan(double x)
            - long double ceil(double x)
            - long double cos(double x)
            - long double exp(double x)
            - long double fabs(double x)
            - long double floor(double x)
            - long double fmod(double x, double y)
            - long double log(double x)
            - long double pow(double base, double exp)
            - long double sin(double x)
            - long double sqrt(double x)
            - long double tan(double x)

	## - String.h. Разработка программы на языке Си, функции библиотеки string.h
           - void *memchr(const void *str, int c, size_t n)
           - int memcmp(const void *str1, const void *str2, size_t n)
           - void *memcpy(void *dest, const void *src, size_t n)
           - void *memset(void *str, int c, size_t n)
           - char *strncat(char *dest, const char *src, size_t n)
           - char *strchr(const char *str, int c)
           - int strncmp(const char *str1, const char *str2, size_t n)
           - char *strncpy(char *dest, const char *src, size_t n)
           - size_t strcspn(const char *str1, const char *str2)
           - char *strerror(int errnum)
           - size_t strlen(const char *str)
           - char *strpbrk(const char *str1, const char *str2)
           - char *strrchr(const char *str, int c)
           - char *strstr(const char *haystack, const char *needle)
           - char *strtok(char *str, const char *delim)
           - int sscanf(const char *str, const char *format, ...)
           - int sprintf(char *str, const char *format, ...) 

	## - Decimal.h. Разработка программы на языке Си, функции библиотеки Decimal.h
           - Арифметические операторы (+, -, *, /)
           - Операторы сравнение (<, >, <=, >=, ==, !=)
           - Преобразователи (из int, из float, в int, в float)
           - Другие функции (floor, round, truncate, negate)


## Реализация функций библиотеки
Необходимо реализовать функции библиотек (только те, что непосредственно описаны выше):

    - Библиотека должна быть разработана на языке Си стандарта C11 с использованием компиятора gcc
    - Код библиотеки должен находиться в папке src в ветке develop
    - При написании кода необходимо придерживаться Google Style
    - Оформить решение как статическую библиотеку (с заголовочным файлом s21_)
    - Библиотека должна быть разработана в соответствии с принципами структурного программирования, должно быть исключено дублирование кода
    - Перед каждой функцией использовать префикс s21_
    - Подготовить полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check
    - Unit-тесты должны проверять результаты работы вашей реализации путём сравнения ее с реализацией стандартной библиотеки
    - Unit-тесты должны покрывать не менее 80% каждой функции
    - В цели gcov_report должен формироваться отчёт gcov в виде html страницы. Для этого unit-тесты должны запускаться с флагами gcov
    - Предусмотреть Makefile для сборки библиотеки и тестов (с целями all, clean, test, s21_lib.a, gcov_report)
    - Запрещено копирование реализации и использование стандартной библиотеки .h везде, кроме unit-тестов
    - Необходимо соблюсти логику работы стандартной библиотеки (в части проверок, работы с памятью и поведения в нештатных ситуациях - здесь помогут тесты)
