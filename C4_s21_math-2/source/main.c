#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_abs) {
  ck_assert_int_eq(abs(-1), s21_abs(-1));
  ck_assert_int_eq(abs(1), s21_abs(1));
  ck_assert_int_eq(abs(0), s21_abs(0));
  ck_assert_int_eq(abs(1672), s21_abs(1672));
  ck_assert_int_eq(abs(-10000001), s21_abs(-10000001));
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_double_eq(fabs(-1.001), s21_fabs(-1.001));
  ck_assert_double_eq(fabs(1.2), s21_fabs(1.2));
  ck_assert_double_eq(fabs(0.99), s21_fabs(0.99));
  ck_assert_double_eq(fabs(1672.019), s21_fabs(1672.019));
  ck_assert_double_eq(fabs(-10000001.0), s21_fabs(-10000001.0));
  ck_assert_double_eq(fabs(S21_pINF), s21_fabs(S21_pINF));
  ck_assert_double_eq(fabs(S21_nINF), s21_fabs(S21_nINF));
  ck_assert_ldouble_nan(fabs(S21_NAN));
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_double_eq(ceil(0.1), s21_ceil(0.1));
  ck_assert_double_eq(ceil(-0.1), s21_ceil(-0.1));
  ck_assert_double_eq(ceil(14567.008), s21_ceil(14567.008));
  ck_assert_double_eq(ceil(-14567.008), s21_ceil(-14567.008));
  ck_assert_double_eq(ceil(0), s21_ceil(0));
  ck_assert_double_eq(ceil(S21_pINF), s21_ceil(S21_pINF));
  ck_assert_double_eq(ceil(S21_nINF), s21_ceil(S21_nINF));
  ck_assert_ldouble_nan(ceil(S21_NAN));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST

START_TEST(test_floor) {
  ck_assert_double_eq(floor(0.1), s21_floor(0.1));
  ck_assert_double_eq(floor(-0.1), s21_floor(-0.1));
  ck_assert_double_eq(floor(14567.008), s21_floor(14567.008));
  ck_assert_double_eq(floor(-14567.008), s21_floor(-14567.008));
  ck_assert_double_eq(floor(0), s21_floor(0));
  ck_assert_double_eq(floor(S21_pINF), s21_floor(S21_pINF));
  ck_assert_double_eq(floor(S21_nINF), s21_floor(S21_nINF));
  ck_assert_ldouble_nan(floor(S21_NAN));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
}
END_TEST

START_TEST(test_exp) {
  ck_assert_double_eq_tol(exp(0), s21_exp(0), S21_EPS6);
  ck_assert_double_eq_tol(exp(1), s21_exp(1), S21_EPS6);
  ck_assert_double_eq_tol(exp(-1.987), s21_exp(-1.987), S21_EPS6);
  ck_assert_double_eq_tol(exp(167), s21_exp(167), S21_EPS6);
  ck_assert_double_eq(exp(710), s21_exp(710));
  ck_assert_double_eq(exp(-710), s21_exp(-710));
  ck_assert_ldouble_nan(exp(S21_NAN));
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_double_eq(exp(S21_pINF), s21_exp(S21_pINF));
  ck_assert_double_eq(exp(S21_nINF), s21_exp(S21_nINF));
}
END_TEST

START_TEST(test_log) {
  ck_assert_double_eq(log(0), s21_log(0));
  ck_assert_double_nan(log(-1));
  ck_assert_double_nan(s21_log(-1));
  ck_assert_double_nan(log(S21_NAN));
  ck_assert_double_nan(s21_log(S21_NAN));
  ck_assert_double_eq(log(S21_pINF), s21_log(S21_pINF));
  ck_assert_double_nan(log(S21_nINF));
  ck_assert_double_nan(s21_log(S21_nINF));
  ck_assert_double_eq_tol(log(1.5), s21_log(1.5), S21_EPS6);
  ck_assert_double_eq_tol(log(1), s21_log(1), S21_EPS6);
  ck_assert_double_eq_tol(log(0.5), s21_log(0.5), S21_EPS6);
  ck_assert_double_eq_tol(log(0.9), s21_log(0.9), S21_EPS6);
  ck_assert_double_eq_tol(log(1000), s21_log(1000), S21_EPS6);
}
END_TEST

START_TEST(test_pow) {
  ck_assert_double_nan(pow(S21_NAN, S21_NAN));
  ck_assert_double_nan(pow(0, S21_NAN));
  ck_assert_double_nan(pow(-1.1, 2.2));
  ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_double_nan(s21_pow(0, S21_NAN));
  ck_assert_double_nan(s21_pow(-1.1, 2.2));
  ck_assert_double_eq(pow(S21_NAN, 0), s21_pow(S21_NAN, 0));
  ck_assert_double_eq(pow(S21_pINF, 0), s21_pow(S21_pINF, 0));
  ck_assert_double_eq(pow(S21_nINF, 0), s21_pow(S21_nINF, 0));
  ck_assert_double_eq(pow(S21_pINF, 1), s21_pow(S21_pINF, 1));
  ck_assert_double_eq(pow(S21_nINF, 1), s21_pow(S21_nINF, 1));
  ck_assert_double_eq(pow(1, S21_nINF), s21_pow(1, S21_nINF));
  ck_assert_double_eq(pow(1, S21_pINF), s21_pow(1, S21_pINF));
  ck_assert_double_eq(pow(0, S21_nINF), s21_pow(0, S21_nINF));
  ck_assert_double_eq(pow(0, S21_pINF), s21_pow(0, S21_pINF));
  ck_assert_double_eq(pow(-9999, 9999), s21_pow(-9999, 9999));
  for (int i = -10; i <= 10; i++) {
    ck_assert_double_eq_tol(pow(123.456 * i, i), s21_pow(123.456 * i, i),
                            S21_EPS6);
  }
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_double_nan(fmod(S21_NAN, S21_NAN));
  ck_assert_double_nan(fmod(1, S21_NAN));
  ck_assert_double_nan(fmod(S21_NAN, 1));
  ck_assert_double_nan(fmod(1, 0));
  ck_assert_double_nan(fmod(S21_pINF, 1));
  ck_assert_double_nan(fmod(S21_nINF, 1));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_double_nan(s21_fmod(1, S21_NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, 1));
  ck_assert_double_nan(s21_fmod(1, 0));
  ck_assert_double_nan(s21_fmod(S21_pINF, 1));
  ck_assert_double_nan(s21_fmod(S21_nINF, 1));
  ck_assert_double_eq(fmod(0, 1), s21_fmod(0, 1));
  ck_assert_double_eq(fmod(1, S21_pINF), s21_fmod(1, S21_pINF));
  ck_assert_double_eq(fmod(1, S21_nINF), s21_fmod(1, S21_nINF));
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      ck_assert_double_eq(fmod(467.294 * i, 74.098 * j),
                          s21_fmod(467.294 * i, 74.098 * j));
      ck_assert_double_eq(fmod(467.294 * i, -74.098 * j),
                          s21_fmod(467.294 * i, -74.098 * j));
      ck_assert_double_eq(fmod(-467.294 * i, 74.098 * j),
                          s21_fmod(-467.294 * i, 74.098 * j));
      ck_assert_double_eq(fmod(-467.294 * i, -74.098 * j),
                          s21_fmod(-467.294 * i, -74.098 * j));
    }
  }
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_double_nan(sqrt(S21_NAN));
  ck_assert_double_nan(sqrt(S21_nINF));
  ck_assert_double_nan(s21_sqrt(S21_NAN));
  ck_assert_double_nan(s21_sqrt(S21_nINF));
  ck_assert_double_eq(sqrt(S21_pINF), s21_sqrt(S21_pINF));
  for (double i = 0; i < 10; i += 0.1) {
    ck_assert_double_eq_tol(sqrt(981.73 * i), s21_sqrt(981.73 * i), S21_EPS6);
  }
}
END_TEST

START_TEST(test_sin) {
  ck_assert_double_nan(sin(S21_NAN));
  ck_assert_double_nan(sin(S21_nINF));
  ck_assert_double_nan(sin(S21_pINF));
  ck_assert_double_nan(s21_sin(S21_NAN));
  ck_assert_double_nan(s21_sin(S21_nINF));
  ck_assert_double_nan(s21_sin(S21_pINF));
  for (double i = -10; i <= 10; i += 0.1) {
    ck_assert_double_eq_tol(sin(S21_PI * i), s21_sin(S21_PI * i), S21_EPS6);
  }
}
END_TEST

START_TEST(test_cos) {
  ck_assert_double_nan(cos(S21_NAN));
  ck_assert_double_nan(cos(S21_nINF));
  ck_assert_double_nan(cos(S21_pINF));
  ck_assert_double_nan(s21_cos(S21_NAN));
  ck_assert_double_nan(s21_cos(S21_nINF));
  ck_assert_double_nan(s21_cos(S21_pINF));
  for (double i = -10; i <= 10; i += 0.1) {
    ck_assert_double_eq_tol(cos(S21_PI * i), s21_cos(S21_PI * i), S21_EPS6);
  }
}
END_TEST

START_TEST(test_tan) {
  ck_assert_double_nan(tan(S21_NAN));
  ck_assert_double_nan(tan(S21_nINF));
  ck_assert_double_nan(tan(S21_pINF));
  ck_assert_double_nan(s21_tan(S21_NAN));
  ck_assert_double_nan(s21_tan(S21_nINF));
  ck_assert_double_nan(s21_tan(S21_pINF));

  for (double i = -0.4; i <= 0.4; i += 0.1) {
    ck_assert_double_eq_tol(tan(S21_PI * i), s21_tan(S21_PI * i), S21_EPS6);
  }
}
END_TEST

START_TEST(test_asin) {
  ck_assert_double_nan(asin(S21_NAN));
  ck_assert_double_nan(asin(S21_pINF));
  ck_assert_double_nan(asin(S21_nINF));
  ck_assert_double_nan(s21_asin(S21_NAN));
  ck_assert_double_nan(s21_asin(S21_pINF));
  ck_assert_double_nan(s21_asin(S21_nINF));
  for (int i = -10; i <= 10; i++) {
    ck_assert_double_eq_tol(asin(0.1 * i), s21_asin(0.1 * i), S21_EPS6);
  }
}
END_TEST

START_TEST(test_acos) {
  ck_assert_double_nan(acos(S21_NAN));
  ck_assert_double_nan(acos(S21_pINF));
  ck_assert_double_nan(acos(S21_nINF));
  ck_assert_double_nan(s21_acos(S21_NAN));
  ck_assert_double_nan(s21_acos(S21_pINF));
  ck_assert_double_nan(s21_acos(S21_nINF));
  ck_assert_double_eq_tol(acos(1), s21_acos(1), S21_EPS6);
  ck_assert_double_eq_tol(acos(-1), s21_acos(-1), S21_EPS6);
  for (int i = -10; i <= 10; i++) {
    ck_assert_double_eq_tol(cos(0.1 * i), s21_cos(0.1 * i), S21_EPS6);
  }
}
END_TEST

START_TEST(test_atan) {
  ck_assert_double_nan(atan(S21_NAN));
  ck_assert_double_eq_tol(atan(S21_pINF), S21_PI / 2, S21_EPS6);
  ck_assert_double_eq_tol(atan(S21_nINF), -S21_PI / 2, S21_EPS6);
  ck_assert_double_nan(s21_atan(S21_NAN));
  ck_assert_double_eq_tol(s21_atan(S21_pINF), S21_PI / 2, S21_EPS6);
  ck_assert_double_eq_tol(s21_atan(S21_nINF), -S21_PI / 2, S21_EPS6);
}
END_TEST

Suite *test_suite(void) {
  Suite *s = suite_create("MATH TEST");

  TCase *abs_tests = tcase_create("ABS");
  tcase_add_test(abs_tests, test_abs);
  suite_add_tcase(s, abs_tests);

  TCase *fabs_tests = tcase_create("FABS");
  tcase_add_test(fabs_tests, test_fabs);
  suite_add_tcase(s, fabs_tests);

  TCase *ceil_tests = tcase_create("CEIL");
  tcase_add_test(ceil_tests, test_ceil);
  suite_add_tcase(s, ceil_tests);

  TCase *floor_tests = tcase_create("FLOOR");
  tcase_add_test(floor_tests, test_floor);
  suite_add_tcase(s, floor_tests);

  TCase *exp_tests = tcase_create("EXP");
  tcase_add_test(exp_tests, test_exp);
  suite_add_tcase(s, exp_tests);

  TCase *log_tests = tcase_create("LOG");
  tcase_add_test(log_tests, test_log);
  suite_add_tcase(s, log_tests);

  TCase *pow_tests = tcase_create("POW");
  tcase_add_test(pow_tests, test_pow);
  suite_add_tcase(s, pow_tests);

  TCase *fmod_tests = tcase_create("POW");
  tcase_add_test(fmod_tests, test_fmod);
  suite_add_tcase(s, fmod_tests);

  TCase *sqrt_tests = tcase_create("SQRT");
  tcase_add_test(sqrt_tests, test_sqrt);
  suite_add_tcase(s, sqrt_tests);

  TCase *sin_tests = tcase_create("SIN");
  tcase_add_test(sin_tests, test_sin);
  suite_add_tcase(s, sin_tests);

  TCase *cos_tests = tcase_create("COS");
  tcase_add_test(cos_tests, test_cos);
  suite_add_tcase(s, cos_tests);

  TCase *tan_tests = tcase_create("COS");
  tcase_add_test(tan_tests, test_tan);
  suite_add_tcase(s, tan_tests);

  TCase *asin_tests = tcase_create("ASIN");
  tcase_add_test(asin_tests, test_asin);
  suite_add_tcase(s, asin_tests);

  TCase *acos_tests = tcase_create("ACOS");
  tcase_add_test(acos_tests, test_acos);
  suite_add_tcase(s, acos_tests);

  TCase *atan_tests = tcase_create("ATAN");
  tcase_add_test(atan_tests, test_atan);
  suite_add_tcase(s, atan_tests);

  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int fail = srunner_ntests_failed(runner);
  srunner_free(runner);
  return fail ? EXIT_FAILURE : EXIT_SUCCESS;
}
