#include "test_s21_decimal.h"

//--------------------------s21_add---------------------------------

START_TEST(test_s21_add_1) {
  s21_decimal value_1 = {
      {4294967293, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{1, 0, 0, 0b10000000000000000000000000000000}};

  s21_decimal result = {0};

  int status = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_uint_eq(result.bits[0], 4294967294);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_s21_add_2) {
  s21_decimal value_1 = {
      {0, 4294967295, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{1, 0, 0, 0b10000000000000000000000000000000}};

  s21_decimal result = {0};

  int status = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], 4294967295);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_s21_add_3) {
  s21_decimal value_1 = {
      {0, 4294967294, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{1, 1, 0, 0b00000000000000000000000000000000}};

  s21_decimal result = {0};

  int status = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], 4294967295);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(test_s21_add_4) {
  s21_decimal value1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value2 = {{1, 0, 1, 0}};
  s21_decimal result = {0};
  ck_assert_int_eq(1, s21_add(value1, value2, &result));
}
END_TEST

START_TEST(test_s21_add_5) {
  s21_decimal value_1 = {{2147483646, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};

  s21_decimal result = {0};

  int status = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_uint_eq(result.bits[0], 2147483648);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_add_6) {
  s21_decimal value_1 = {{2147483646, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{2, 0, 0, 0x80000000}};

  s21_decimal result = {0};

  int status = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_uint_eq(result.bits[0], 2147483648);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0x80000000);
}
END_TEST

START_TEST(test_s21_add_7) {
  s21_decimal value_1 = {{2147483646, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};

  s21_decimal result = {0};

  int status = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_uint_eq(result.bits[0], 2147483646);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_add_8) {
  s21_decimal value_1 = {{100, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};

  s21_decimal result = {0};

  int status = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_uint_eq(result.bits[0], 100);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0x80000000);
}
END_TEST

START_TEST(test_s21_add_9) {
  s21_decimal value_1 = {{2147483646, 0, 0, 0}};
  s21_decimal value_2 = {{40, 0, 0, 0x80000000}};

  s21_decimal result = {0};

  int status = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_uint_eq(result.bits[0], 2147483606);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_add_10) {
  s21_decimal value_1 = {
      {2147483646, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};

  s21_decimal result = {0};

  int status = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(status, 0);

  ck_assert_uint_eq(result.bits[0], 2147483676);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0b00000000000000010000000000000000);
}
END_TEST

Suite *s21_add_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_ADD=-\033[0m");
  tc_core = tcase_create("AddCore");

  tcase_add_test(tc_core, test_s21_add_1);
  tcase_add_test(tc_core, test_s21_add_2);
  tcase_add_test(tc_core, test_s21_add_3);
  tcase_add_test(tc_core, test_s21_add_4);
  tcase_add_test(tc_core, test_s21_add_5);
  tcase_add_test(tc_core, test_s21_add_6);
  tcase_add_test(tc_core, test_s21_add_7);
  tcase_add_test(tc_core, test_s21_add_8);
  tcase_add_test(tc_core, test_s21_add_9);
  tcase_add_test(tc_core, test_s21_add_10);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_div---------------------------------

START_TEST(test_s21_div_1) {
  s21_decimal value1 = {{0, 0, 0, 1}};
  s21_decimal value2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};
  ck_assert_int_eq(3, s21_div(value1, value2, &result));  // 3
}
END_TEST

START_TEST(test_s21_div_2) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_div(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
}
END_TEST

START_TEST(test_s21_div_3) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0x80000000}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_div(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0x80000000);
}
END_TEST

START_TEST(test_s21_div_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_div(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_div_5) {
  s21_decimal value_1 = {{1, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_div(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0x80000000);
}
END_TEST

START_TEST(test_s21_div_6) {
  s21_decimal value_1 = {{27, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{3, 0, 0, 0x80000000}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_div(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 9);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_div_7) {
  s21_decimal value1 = {{123, 0, 0, 0}};
  s21_decimal value2 = {{5, 0, 0, 0}};
  s21_decimal result = {0};
  ck_assert_int_eq(0, s21_div(value1, value2, &result));
}
END_TEST

START_TEST(test_s21_div_8) {
  s21_decimal value1 = {{0b10011101010101111010101000110100,
                         0b00101110110000101010010010111100,
                         0b00000000000100110110011000111010, 0}};
  s21_decimal value2 = {{2, 0, 0, 0}};
  s21_decimal result = {0};
  ck_assert_int_eq(0, s21_div(value1, value2, &result));
  ck_assert_int_eq(result.bits[0], 0b01001110101010111101010100011010);
  ck_assert_int_eq(result.bits[1], 0b00010111011000010101001001011110);
  ck_assert_int_eq(result.bits[2], 0b00000000000010011011001100011101);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

Suite *s21_div_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_DIV=-\033[0m");
  tc_core = tcase_create("DivCore");

  tcase_add_test(tc_core, test_s21_div_1);
  tcase_add_test(tc_core, test_s21_div_2);
  tcase_add_test(tc_core, test_s21_div_3);
  tcase_add_test(tc_core, test_s21_div_4);
  tcase_add_test(tc_core, test_s21_div_5);
  tcase_add_test(tc_core, test_s21_div_6);
  tcase_add_test(tc_core, test_s21_div_7);
  tcase_add_test(tc_core, test_s21_div_8);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_mul---------------------------------

START_TEST(test_s21_mul_1) {
  s21_decimal value_1 = {{0, 0, 0, 0b00000000000010100000000000000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_mul_2) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_mul_3) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 50);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_mul_4) {
  s21_decimal value_1 = {{8, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 80);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_mul_5) {
  s21_decimal value_1 = {{10, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{4, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 40);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0x80000000);
}
END_TEST

START_TEST(test_s21_mul_6) {
  s21_decimal value_1 = {{123, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0x80000000}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 123);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0x80000000);
}
END_TEST

START_TEST(test_s21_mul_7) {
  s21_decimal value_1 = {{1, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{1, 0, 0, 0x80000000}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

Suite *s21_mul_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_MUL=-\033[0m");
  tc_core = tcase_create("MulCore");

  tcase_add_test(tc_core, test_s21_mul_1);
  tcase_add_test(tc_core, test_s21_mul_2);
  tcase_add_test(tc_core, test_s21_mul_3);
  tcase_add_test(tc_core, test_s21_mul_4);
  tcase_add_test(tc_core, test_s21_mul_5);
  tcase_add_test(tc_core, test_s21_mul_6);
  tcase_add_test(tc_core, test_s21_mul_7);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_sub---------------------------------

START_TEST(test_s21_sub_1) {
  s21_decimal value_1 = {{10, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_sub(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 15);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0x80000000);
}
END_TEST

START_TEST(test_s21_sub_2) {
  s21_decimal value_1 = {{2, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{1, 0, 0, 0x80000000}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_sub(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0x80000000);
}
END_TEST

START_TEST(test_s21_sub_3) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_sub(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 2);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_sub_4) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0x80000000}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_sub(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 15);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_sub_5) {
  s21_decimal value1 = {{0b10011101010101111010101000110100,
                         0b00101110110000101010010010111100,
                         0b00000000000100110110011000111010, 0}};
  s21_decimal value2 = {{0b00011000010011110110000010001110,
                         0b10001111100100110110100010000110,
                         0b00000000000100110100111110001010, 0}};
  s21_decimal result = {0};
  ck_assert_int_eq(0, s21_sub(value1, value2, &result));
  ck_assert_uint_eq(result.bits[0], 0b10000101000010000100100110100110);
  ck_assert_uint_eq(result.bits[1], 0b10011111001011110011110000110110);
  ck_assert_uint_eq(result.bits[2], 0b00000000000000000001011010101111);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

Suite *s21_sub_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SUB=-\033[0m");
  tc_core = tcase_create("SubCore");

  tcase_add_test(tc_core, test_s21_sub_1);
  tcase_add_test(tc_core, test_s21_sub_2);
  tcase_add_test(tc_core, test_s21_sub_3);
  tcase_add_test(tc_core, test_s21_sub_4);
  tcase_add_test(tc_core, test_s21_sub_5);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_is_less---------------------------------

START_TEST(test_s21_is_less_1) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};  // 0 - FALSE 1 - TRUE
  s21_decimal value_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_2) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_3) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};

  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_4) {
  s21_decimal value_1 = {{0, 1, 0, 0}};
  s21_decimal value_2 = {{0, 1, 0, 0}};

  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_5) {
  s21_decimal value_1 = {{0, 1, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};

  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_6) {
  s21_decimal value_1 = {{0, 1, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_7) {
  s21_decimal value_1 = {
      {50000, 0, 0,
       0b00000000000000010000000000000000}};  //  5'000  (50000 - мантисса и 1 -
                                              //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0,
       0b00000000000000110000000000000000}};  // 50'000  (50000000 - мантисса и
                                              // 2 - scale)
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_8) {
  s21_decimal value_1 = {
      {50000000, 0, 0,
       0b00000000000000110000000000000000}};  //  50'000  (50000000 - мантисса и
                                              //  2 - scale)
  s21_decimal value_2 = {
      {50000, 0, 0,
       0b00000000000000010000000000000000}};  // 5'000  (50000 - мантисса и 1 -
                                              // scale)
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_9) {
  s21_decimal value_1 = {{0, 0, 1, 0x80000000}};
  s21_decimal value_2 = {{0, 1, 0, 0x80000000}};

  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

Suite *s21_is_less_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_IS_LESS=-\033[0m");
  tc_core = tcase_create("IsLessCore");

  tcase_add_test(tc_core, test_s21_is_less_1);
  tcase_add_test(tc_core, test_s21_is_less_2);
  tcase_add_test(tc_core, test_s21_is_less_3);
  tcase_add_test(tc_core, test_s21_is_less_4);
  tcase_add_test(tc_core, test_s21_is_less_5);
  tcase_add_test(tc_core, test_s21_is_less_6);
  tcase_add_test(tc_core, test_s21_is_less_7);
  tcase_add_test(tc_core, test_s21_is_less_8);
  tcase_add_test(tc_core, test_s21_is_less_9);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_is_less_or_equal---------------------------------

START_TEST(test_s21_is_less_or_equal_1) {
  s21_decimal value_1 = {{1, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0x80000000}};

  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_3) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_4) {
  s21_decimal value_1 = {{0, 1, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_5) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0, 1, 0, 0}};

  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_6) {
  s21_decimal value_1 = {{0, 1, 0, 0}};
  s21_decimal value_2 = {{0, 1, 0, 0}};

  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_7) {
  s21_decimal value_1 = {{0, 1, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};

  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_8) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 1, 0, 0}};

  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_9) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_10) {
  s21_decimal value_1 = {
      {50000, 0, 0,
       0b00000000000000010000000000000000}};  //  5'000  (50000 - мантисса и 1 -
                                              //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0,
       0b00000000000000110000000000000000}};  // 50'000  (50000000 - мантисса и
                                              // 2 - scale)
  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_less_or_equal_11) {
  s21_decimal value_1 = {
      {50000000, 0, 0,
       0b00000000000000110000000000000000}};  //  50'000  (50000000 - мантисса и
                                              //  2 - scale)
  s21_decimal value_2 = {
      {50000, 0, 0,
       0b00000000000000010000000000000000}};  // 5'000  (50000 - мантисса и 1 -
                                              // scale)
  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

Suite *s21_is_less_or_equal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_IS_LESS_OR_EQUAL=-\033[0m");
  tc_core = tcase_create("IsLessOrEqualCore");

  tcase_add_test(tc_core, test_s21_is_less_or_equal_1);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_2);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_3);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_4);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_5);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_6);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_7);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_8);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_9);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_10);
  tcase_add_test(tc_core, test_s21_is_less_or_equal_11);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_is_greater---------------------------------

START_TEST(test_s21_is_greater_1) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0x80000000}};
  ck_assert_int_eq(1, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_3) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(0, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_5) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(0, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_6) {
  s21_decimal value_1 = {
      {50000, 0, 0,
       0b00000000000000001000000000000000}};  //  5'000  (50000 - мантисса и 1 -
                                              //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0,
       0b000000000000010000000000000000}};  // 50'000  (50000000 - мантисса и 2
                                            // - scale)
  ck_assert_int_eq(0, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_7) {
  s21_decimal value_1 = {
      {50000, 0, 0,
       0b00000000000000001000000000000000}};  //  5'000  (50000 - мантисса и 1 -
                                              //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0,
       0b000000000000010000000000000000}};  // 50'000  (50000000 - мантисса и 2
                                            // - scale)
  ck_assert_int_eq(1, s21_is_greater(value_2, value_1));
}
END_TEST

Suite *s21_is_greater_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_IS_GREATER=-\033[0m");
  tc_core = tcase_create("IsGreaterCore");

  tcase_add_test(tc_core, test_s21_is_greater_1);
  tcase_add_test(tc_core, test_s21_is_greater_2);
  tcase_add_test(tc_core, test_s21_is_greater_3);
  tcase_add_test(tc_core, test_s21_is_greater_4);
  tcase_add_test(tc_core, test_s21_is_greater_5);
  tcase_add_test(tc_core, test_s21_is_greater_6);
  tcase_add_test(tc_core, test_s21_is_greater_7);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_is_greater_or_equal---------------------------------
START_TEST(test_s21_is_greater_or_equal_1) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_3) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(0, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_5) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_6) {
  s21_decimal value_1 = {
      {50000, 0, 0,
       0b00000000000000001000000000000000}};  //  5'000  (50000 - мантисса и 1 -
                                              //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0,
       0b000000000000010000000000000000}};  // 50'000  (50000000 - мантисса и 2
                                            // - scale)
  ck_assert_int_eq(0, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_7) {
  s21_decimal value_1 = {
      {50000, 0, 0,
       0b00000000000000001000000000000000}};  //  5'000  (50000 - мантисса и 1 -
                                              //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0,
       0b000000000000010000000000000000}};  // 50'000  (50000000 - мантисса и 2
                                            // - scale)
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_2, value_1));
}
END_TEST

Suite *s21_is_greater_or_equal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_IS_GREATER_OR_EQUAL=-\033[0m");
  tc_core = tcase_create("IsGreaterOrEqualCore");

  tcase_add_test(tc_core, test_s21_is_greater_or_equal_1);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_2);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_3);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_4);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_5);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_6);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal_7);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_is_equal---------------------------------
START_TEST(test_s21_is_equal_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 1}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2),
                   1);  // По логике они одинаковые так что true
}
END_TEST

START_TEST(test_s21_is_equal_3) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_4) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_5) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_6) {
  s21_decimal value_1 = {{50000, 0, 0, 0}};  //  5'000  (50000 - мантисса и 1 -
                                             //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0, 0}};  // 5'000  (50000000 - мантисса и 3
                             // - scale)
  set_scale_my(&(value_1.bits[3]), 1);
  set_scale_my(&(value_2.bits[3]), 4);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_7) {
  s21_decimal value_1 = {
      {50000, 0, 0,
       0b00000000000000001000000000000000}};  //  5'000  (50000 - мантисса и 1 -
                                              //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0,
       0b000000000000010000000000000000}};  // 50'000  (50000000 - мантисса и 2
                                            // - scale)
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
}
END_TEST

Suite *s21_is_equal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_IS_EQUAL=-\033[0m");
  tc_core = tcase_create("IsEqualCore");

  tcase_add_test(tc_core, test_s21_is_equal_1);
  tcase_add_test(tc_core, test_s21_is_equal_2);
  tcase_add_test(tc_core, test_s21_is_equal_3);
  tcase_add_test(tc_core, test_s21_is_equal_4);
  tcase_add_test(tc_core, test_s21_is_equal_5);
  tcase_add_test(tc_core, test_s21_is_equal_6);
  tcase_add_test(tc_core, test_s21_is_equal_7);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_is_not_equal---------------------------------
START_TEST(test_s21_is_not_equal_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 1}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2),
                   0);  // По логике они одинаковые так что false
}
END_TEST

START_TEST(test_s21_is_not_equal_3) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_4) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_5) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_6) {
  s21_decimal value_1 = {{0, 0, 1, 1}};
  s21_decimal value_2 = {{0, 0, 1, 1}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_7) {
  s21_decimal value_1 = {{0, 0, 1, 1}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  ck_assert_int_eq(
      s21_is_not_equal(value_1, value_2),
      0);  // false, т.к. 1 в bits[3] не может быть и соответственно у чисел
           // одинаковая мантисса, знак и scale
}
END_TEST

START_TEST(test_s21_is_not_equal_8) {
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal value_2 = {{0, 0, 1, 1}};
  ck_assert_int_eq(
      s21_is_not_equal(value_1, value_2),
      0);  // false, т.к. 1 в bits[3] не может быть и соответственно у чисел
           // одинаковая мантисса, знак и scale
}
END_TEST

START_TEST(test_s21_is_not_equal_9) {
  s21_decimal value_1 = {{0, 0, 1, 1}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_10) {
  s21_decimal value_1 = {
      {50000, 0, 0,
       0b00000000000000001000000000000000}};  //  5'000  (50000 - мантисса и 1 -
                                              //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0,
       0b000000000000011000000000000000}};  // 5'000  (50000000 - мантисса и 3
                                            // - scale)
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_11) {
  s21_decimal value_1 = {{50000, 0, 0, 0}};  //  5'000  (50000 - мантисса и 1 -
                                             //  scale)
  s21_decimal value_2 = {
      {50000000, 0, 0, 0}};  // 50'000  (50000000 - мантисса и 2
                             // - scale)
  set_scale_my(&(value_1.bits[3]), 1);
  set_scale_my(&(value_2.bits[3]), 4);
  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

Suite *s21_is_not_equal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_IS_NOT_EQUAL=-\033[0m");
  tc_core = tcase_create("IsNotEqualCore");

  tcase_add_test(tc_core, test_s21_is_not_equal_1);
  tcase_add_test(tc_core, test_s21_is_not_equal_2);
  tcase_add_test(tc_core, test_s21_is_not_equal_3);
  tcase_add_test(tc_core, test_s21_is_not_equal_4);
  tcase_add_test(tc_core, test_s21_is_not_equal_5);
  tcase_add_test(tc_core, test_s21_is_not_equal_6);
  tcase_add_test(tc_core, test_s21_is_not_equal_7);
  tcase_add_test(tc_core, test_s21_is_not_equal_8);
  tcase_add_test(tc_core, test_s21_is_not_equal_9);
  tcase_add_test(tc_core, test_s21_is_not_equal_10);
  tcase_add_test(tc_core, test_s21_is_not_equal_11);
  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_negate---------------------------------
START_TEST(test_s21_negate_1) {
  s21_decimal value_1 = {{256, 1, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(value_1, &result);

  ck_assert_uint_eq(result.bits[0], 256);
  ck_assert_uint_eq(result.bits[1], 1);
  ck_assert_uint_eq(result.bits[2], 1);
  ck_assert_uint_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_negate_2) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(value_1, &result);
  ck_assert_uint_eq(result.bits[0], 1);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_negate_3) {
  s21_decimal value_1 = {{256, 1, 1, 2147483648}};
  s21_decimal result = {{0, 0, 0, 0}};

  s21_negate(value_1, &result);

  ck_assert_uint_eq(result.bits[0], 256);
  ck_assert_uint_eq(result.bits[1], 1);
  ck_assert_uint_eq(result.bits[2], 1);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

Suite *s21_negate_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_NEGATE=-\033[0m");
  tc_core = tcase_create("NegateCore");

  tcase_add_test(tc_core, test_s21_negate_1);
  tcase_add_test(tc_core, test_s21_negate_2);
  tcase_add_test(tc_core, test_s21_negate_3);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_truncate---------------------------------

START_TEST(test_s21_truncate_1) {
  s21_decimal val = {{2347, 3457, 3457, 0}};
  s21_decimal result = {0};
  ck_assert_int_eq(0, s21_truncate(val, &result));
  ck_assert_int_eq(result.bits[0], 2347);
  ck_assert_int_eq(result.bits[1], 3457);
  ck_assert_int_eq(result.bits[2], 3457);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_truncate_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(123456789, &value_1);
  s21_truncate(value_1, &result);
  ck_assert_int_eq(result.bits[0], 123456789);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_truncate_3) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(15008, &value_1);
  s21_truncate(value_1, &result);
  ck_assert_int_eq(result.bits[0], 15008);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_truncate_4) {
  s21_decimal value_1 = {{50000, 0, 0, 0b00000000000000010000000000000000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(value_1, &result);
  ck_assert_int_eq(result.bits[0], 5000);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

Suite *s21_truncate_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_TRUNCATE=-\033[0m");
  tc_core = tcase_create("TruncateCore");

  tcase_add_test(tc_core, test_s21_truncate_1);
  tcase_add_test(tc_core, test_s21_truncate_2);
  tcase_add_test(tc_core, test_s21_truncate_3);
  tcase_add_test(tc_core, test_s21_truncate_4);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_round---------------------------------

START_TEST(test_s21_round_1) {
  s21_decimal value_1 = {{12345678, 0, 0, 0b00000000000000100000000000000000}};
  //        set_scale(value_1.bits, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value_1, &result);
  ck_assert_int_eq(result.bits[0], 123457);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_round_2) {
  s21_decimal value_1 = {{555555, 0, 0, 0}};
  //    set_scale(value_1.bits, 4);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value_1, &result);
  ck_assert_int_eq(result.bits[0], 555555);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_round_3) {
  s21_decimal value_1 = {{12345678, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value_1, &result);
  ck_assert_int_eq(result.bits[0], 12345678);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_round_4) {
  s21_decimal value_1 = {{5000000, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(value_1, &result);
  ck_assert_int_eq(result.bits[0], 5000000);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

Suite *s21_round_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_ROUND=-\033[0m");
  tc_core = tcase_create("RoundCore");

  tcase_add_test(tc_core, test_s21_round_1);
  tcase_add_test(tc_core, test_s21_round_2);
  tcase_add_test(tc_core, test_s21_round_3);
  tcase_add_test(tc_core, test_s21_round_4);
  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_floor---------------------------------

START_TEST(test_s21_floor_1) {
  s21_decimal value = {{10, 0, 0, MaxINT}};
  s21_decimal result = {0};
  ck_assert_int_eq(0, s21_floor(value, &result));
}
END_TEST

START_TEST(test_s21_floor_2) {
  s21_decimal value = {{256, 0, 0, 0}};
  s21_decimal result = {0};
  set_scale_my(&(value.bits[3]), 2);
  ck_assert_int_eq(0, s21_floor(value, &result));
}
END_TEST

START_TEST(test_s21_floor_3) {
  s21_decimal value = {{28, 0, 0, 0}};
  s21_decimal result = {0};
  ck_assert_int_eq(0, s21_floor(value, &result));
}
END_TEST

START_TEST(test_s21_floor_4) {
  s21_decimal value = {
      {10, 0, 0,
       0x80000000}};  // округляет когда нечего округлять и меняет знак
  s21_decimal result = {0};
  ck_assert_int_eq(0, s21_floor(value, &result));
}
END_TEST

START_TEST(test_s21_floor_5) {
  s21_decimal value = {{256, 0, 0, 0b10000000000000010000000000000000}};
  value.bits[3] |= 1 << 31;
  s21_decimal result = {0};
  ck_assert_int_eq(0, s21_floor(value, &result));
  ck_assert_int_eq(result.bits[0], 26);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

Suite *s21_floor_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_FLOOR=-\033[0m");
  tc_core = tcase_create("FloorCore");

  tcase_add_test(tc_core, test_s21_floor_1);
  tcase_add_test(tc_core, test_s21_floor_2);
  tcase_add_test(tc_core, test_s21_floor_3);
  tcase_add_test(tc_core, test_s21_floor_4);
  tcase_add_test(tc_core, test_s21_floor_5);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_from_int_to_decimal---------------------------------
START_TEST(test_s21_from_int_to_decimal_1) {
  s21_decimal result;
  s21_from_int_to_decimal(123456, &result);
  ck_assert_int_eq(result.bits[0], 123456);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_2) {
  s21_decimal result;
  s21_from_int_to_decimal(-1234567, &result);
  ck_assert_int_eq(result.bits[0], 1234567);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_3) {
  s21_decimal result;
  s21_from_int_to_decimal(3425456, &result);
  ck_assert_int_eq(result.bits[0], 3425456);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_4) {
  s21_decimal result;
  s21_from_int_to_decimal(-42949675, &result);
  ck_assert_int_eq(result.bits[0], 42949675);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_5) {
  s21_decimal result;
  s21_from_int_to_decimal(MaxINT, &result);
  ck_assert_int_eq(result.bits[0], MaxINT);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_6) {
  s21_decimal result;
  s21_from_int_to_decimal(45637492, &result);
  ck_assert_int_eq(result.bits[0], 45637492);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST
Suite *s21_from_int_to_decimal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_FROM_INT_TO_DECIMAL=-\033[0m");
  tc_core = tcase_create("FromIntToDecimalCore");

  tcase_add_test(tc_core, test_s21_from_int_to_decimal_1);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal_2);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal_3);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal_4);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal_5);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal_6);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_from_decimal_to_int---------------------------------

START_TEST(test_s21_from_decimal_to_int_1) {
  s21_decimal value = {{123456789, 123456789, 123456789, 0}};
  int result = 0;
  int status = s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_2) {
  s21_decimal value = {{123, 0, 0, 0}};
  int result = 0;
  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(result, 123);
}
END_TEST

Suite *s21_from_decimal_to_int_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_FROM_DECIMAL_TO_INT=-\033[0m");
  tc_core = tcase_create("FromDecimalToIntCore");

  tcase_add_test(tc_core, test_s21_from_decimal_to_int_1);
  tcase_add_test(tc_core, test_s21_from_decimal_to_int_2);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_from_float_to_decimal---------------------------------

START_TEST(test_s21_from_float_to_decimal_1) {
  s21_decimal result;
  s21_from_float_to_decimal(1234567.0, &result);
  ck_assert_int_eq(result.bits[0], 1234567);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_2) {
  s21_decimal result;
  s21_from_float_to_decimal(1.234567, &result);
  ck_assert_int_eq(result.bits[0], 1234567);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 6 << 16);
}
END_TEST

Suite *s21_from_float_to_decimal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_FROM_FLOAT_TO_DECIMAL=-\033[0m");
  tc_core = tcase_create("FromFloatToDecimalCore");

  tcase_add_test(tc_core, test_s21_from_float_to_decimal_1);
  tcase_add_test(tc_core, test_s21_from_float_to_decimal_2);

  suite_add_tcase(s, tc_core);

  return s;
}
//--------------------------s21_from_decimal_to_float---------------------------------

START_TEST(test_s21_from_decimal_to_float_1) {
  s21_decimal src = {{100000, 0, 0, 0}};
  float dst = 0.0;

  int res = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(dst, 100000.0);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_2) {
  s21_decimal src = {{42967295, 0, 0, 0}};
  float dst = 0.0;

  int res = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(dst, 42967295.0);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_3) {
  s21_decimal src = {{123456789, 0, 0, 0}};
  float dst = 0.0;

  int res = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(dst, 123456789.0);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_4) {
  s21_decimal src = {{1000000000, 0, 0, 0x80000000}};
  float dst = 0.0;

  int res = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(dst, -1000000000.0);
}
END_TEST

Suite *s21_from_decimal_to_float_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_FROM_DECIMAL_TO_FLOAT=-\033[0m");
  tc_core = tcase_create("FromDecimalToFloatCore");

  tcase_add_test(tc_core, test_s21_from_decimal_to_float_1);
  tcase_add_test(tc_core, test_s21_from_decimal_to_float_2);
  tcase_add_test(tc_core, test_s21_from_decimal_to_float_3);
  tcase_add_test(tc_core, test_s21_from_decimal_to_float_4);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int failed = 0;
  Suite *decimal_tests[] = {s21_add_suite(),
                            s21_div_suite(),
                            s21_mul_suite(),
                            s21_sub_suite(),
                            s21_is_less_suite(),
                            s21_is_less_or_equal_suite(),
                            s21_is_greater_suite(),
                            s21_is_greater_or_equal_suite(),
                            s21_is_equal_suite(),
                            s21_is_not_equal_suite(),
                            s21_negate_suite(),
                            s21_truncate_suite(),
                            s21_round_suite(),
                            s21_floor_suite(),
                            s21_from_int_to_decimal_suite(),
                            s21_from_decimal_to_int_suite(),
                            s21_from_float_to_decimal_suite(),
                            s21_from_decimal_to_float_suite(),
                            NULL};

  for (int i = 0; decimal_tests[i] != NULL; i++) {
    SRunner *runner;
    runner = srunner_create(decimal_tests[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
