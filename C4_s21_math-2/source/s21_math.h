#ifndef _SRC_S_21_MATH_H
#define _SRC_S_21_MATH_H

// https://runebook.dev/ru/docs/gcc/other-builtins

#define s21_NAN __builtin_nanf("")
#define S21_NAN __builtin_nanf("")

#define s21_isnan(x) __builtin_isnan(x)   // isnan(x)
#define S21_IS_NAN(x) __builtin_isnan(x)  // isnan(x)
// #define INFINITY __builtin_huge_valf()
#define s21_INFINITY __builtin_huge_valf()

#define S21_IS_INF(x) __builtin_isinf_sign(x)  // isinf_sign(x)
#define S21_nINF -__builtin_huge_valf()
#define S21_pINF __builtin_huge_valf()

#define S21_EPS6 0.000001
#define S21_EPS10 0.0000000001
#define S21_EPS15 0.000000000000001

#define s21_M_PI 3.14159265358
#define s21_M_E 2.71828182846
#define S21_MAX_LONG_DOUBLE 1.79769313486231571e+308
#define S21_M_LN10 2.30258509299404568402
#define S21_M_LN2 0.69314718055994528623

#define S21_PI 3.14159265358
#define S21_M_E 2.71828182846
#define S21_nNULL __builtin_nanf("")

int s21_abs(int);
double s21_fac(int i);
long double s21_acos(double);
long double s21_asin(double);
long double s21_atan(double);
long double s21_ceil(double);
long double s21_cos(double);
long double s21_exp(double);
long double s21_fabs(double);
long double s21_floor(double);
long double s21_fmod(double, double);
long double s21_log(double);
long double s21_pow(double, double);
long double s21_sin(double);
long double s21_sqrt(double);
long double s21_tan(double);

#endif  // _SRC_S_21_MATH_H