#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGN_MASK 0x80000000
#define SCALE_MASK 0xFF0000

#define OverflowException 1
#define MaxUint 4294967295
#define MaxINT 2147483647

typedef struct {
  char buf[10][37];
  int pointer;
} insert_strings;

#define SIZE_STRUCT 4
#define SIZE_BIG_STRUCT 6
#define BITS_SIZE 32
#define MANTISSA_BITS_SIZE 96
#define MANTISSA_BIG_BITS_SIZE 192
#define MAX_DEGREE 28

#define NUMB_TOO_SMALL (fabs(src) > 0.0 && fabs(src) < 1e-28)
#define NUMB_TOO_BIG (fabs(src) > 7.9228162514264337593543950335e28)

enum { OK, TOO_LARGE_OR_INF, TOO_SMALL_OR_NEG_INF, DIV_BY_ZERO };
enum { FALSE, TRUE };
enum { EQUAL_SIGN, VALUES_ZERO, GREATER_SIGN, LESS_SIGN };
enum { CONVERSION_OK, CONVERSION_ERROR };
enum { CALCULATION_OK, CALCULATION_ERROR };
enum { FUNCTION_ADD, FUNCTION_SUB };

// Definition of the s21_decimal structure
typedef struct {
  unsigned int bits[SIZE_STRUCT];
} s21_decimal;

// Definition of the s21_big_decimal structure
typedef struct {
  unsigned int bits[SIZE_BIG_STRUCT];
  int scale;
  unsigned int sign;
} s21_big_decimal;

// Arithmetic Operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparison Operators
void zero_check_my(s21_decimal *decimal);
int get_bit_my(unsigned long value, int num);
void set_0_bit(unsigned int *value, int num);
int get_scale_my(s21_decimal value);
void set_scale_my(unsigned int *value, unsigned int num);
int check_sign_my(s21_decimal value);
void correction_decimal(s21_decimal *dst);
int s21_bits_is_greater(const s21_decimal dst, const s21_decimal src,
                        int num_bit);
int Multiply_by_ten(s21_decimal *value, unsigned int scale);
int equalize_scale(s21_decimal *value_1, s21_decimal *value_2);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// Convertors and parsers
void *decimal_to_str(s21_decimal src);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Decimal bitwise functions
void left_shift(s21_decimal *dcml);
void set_bit(s21_decimal *dcml, unsigned int bit, unsigned int order);
int get_bit(s21_decimal dcml, unsigned int order);
unsigned int get_sign(s21_decimal dcml);
void set_sign(s21_decimal *dcml, unsigned int sign);
int get_scale(s21_decimal dcml);
void set_scale(s21_decimal *dcml, int scale);

// Bitwise mantissa arithmetic
int mult_ten(s21_decimal *dcml);
int div_ten(s21_decimal *dcml);
int add_mantissa(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Other
int seven_signific(float src, int *scale);
void alignment_scale(s21_decimal *value_1, s21_decimal *value_2);
void round_overflow(s21_decimal *tmp_value, int *sum_owerflow,
                    int *final_owerflow);
void reset_decimal(s21_decimal *dcml);

/// Big decimal bitwise functions
void left_shift_big_decimal(s21_big_decimal *big_dcml);
int get_bit_big_decimal(s21_big_decimal big_dcml, unsigned int order);
void set_bit_big_decimal(s21_big_decimal *big_dcml, unsigned int bit,
                         unsigned int order);
void reset_big_decimal(s21_big_decimal *big_dcml);
int is_decimal_zero(s21_decimal *dcml);
int is_big_decimal_zero(s21_big_decimal *dcml);

// Big decimal bitwise mantissa arithmetic
int is_less_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2);
int initial_comparison_check(s21_decimal value_1, s21_decimal value_2);
int initial_comparison_check_big_decimal(s21_big_decimal value_1,
                                         s21_big_decimal value_2);
void modulo_values_big_decimal(s21_big_decimal *value_1,
                               s21_big_decimal *value_2);
int subtracted_less(s21_big_decimal *value_1, s21_big_decimal *value_2);
int sub_mantissa_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                             s21_big_decimal *result);
int add_mantissa_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                             s21_big_decimal *result);
void mult_ten_big_decimal(s21_big_decimal *big_dcml);
int div_ten_big_decimal(s21_big_decimal *big_dcml);
int div_ten_without_remainder_and_sub_scale(s21_decimal *dcml);
int decimal_owerflow_error(s21_big_decimal dcml);
int bank_round(s21_big_decimal value, s21_decimal *result);
int add_sub_big_decimal(s21_decimal value_1, s21_decimal value_2,
                        int *sign_operations, s21_decimal *result);
int sign_for_mult_and_div(s21_big_decimal value_1, s21_big_decimal value_2);
void mult_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal *result);
int num_of_bits_in_the_decimal_value(s21_big_decimal big_dcml);
int div_mantissa_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2,
                             s21_big_decimal *result);

// Big decimal other
int input_errors_float(float src, s21_decimal *dst);
void convert_to_big_decimal(s21_decimal value, s21_big_decimal *result);
void copy_scale_and_sign_value(s21_big_decimal from_value,
                               s21_big_decimal *to_result);
int equal(s21_decimal *value_1, s21_decimal *value_2, int *mismatch);
int equal_big_decimal(s21_big_decimal *value_1, s21_big_decimal *value_2,
                      int *mismatch);
int operations_sign(s21_big_decimal *value_1, s21_big_decimal *value_2,
                    int *sign_operations);
void alignment_scale_big_decimal(s21_big_decimal *value_1,
                                 s21_big_decimal *value_2);
int convert_big_decimal_to_decimal(s21_big_decimal value, s21_decimal *result);

#endif /* S21_DECIMAL_H */
