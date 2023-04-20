#include <check.h>

//#include <stdlib.h>

#include "../calc.h"
#include "../credit_calc.h"

START_TEST(test_1) {
  double result = 0;
  int status = calculate("7 + 2 * (cos(24) + log(10))", &result);
  ck_assert_double_eq_tol(result, 9.84835801, 1e-8);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_2) {
  double result = 0;
  int status = calculate("sin(2) + tan(2) - ln(2) * (54 mod 4)", &result);
  ck_assert_double_eq_tol(result, -2.66203680, 1e-8);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_3) {
  double result = 0;
  int status = calculate("asin(0.1) * acos(0.2)", &result);
  ck_assert_double_eq_tol(result, 0.13717311, 1e-8);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_4) {
  double result = 0;
  int status = calculate("sqrt(+32) + 2^4 + atan(-3 / 4)", &result);
  ck_assert_double_eq_tol(result, 21.01335314, 1e-8);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_5) {
  double result = 0;
  int status = calculate("2 * x + -x", &result);
  ck_assert_double_eq_tol(result, 0, 1e-8);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_6) {
  double result = 0;
  int status = calculate("xx", &result);
  ck_assert_double_eq_tol(result, 0, 1e-8);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_7) {
  double result = 0;
  int status = calculate("0..34 + 2", &result);
  ck_assert_double_eq_tol(result, 0, 1e-8);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_8) {
  double result = 0;
  int status = calculate("0. + 5", &result);
  ck_assert_double_eq_tol(result, 0, 1e-8);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_9) {
  double result = 0;
  int status = calculate("5 + .", &result);
  ck_assert_double_eq_tol(result, 0, 1e-8);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_10) {
  double result = 0;
  int status = calculate("+ - * ", &result);
  ck_assert_double_eq_tol(result, 0, 1e-8);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_11) {
  double result = 0;
  int status = calculate("2 + ", &result);
  ck_assert_double_eq_tol(result, 0, 1e-8);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_12) {
  double result = 0;
  int status = calculate("2 * ((3) + 4()", &result);
  ck_assert_double_eq_tol(result, 0, 1e-8);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_13) {
  char *credit_data = "500000 5 12 a";
  double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
  int status = credit_calculate(credit_data, &max_payment, &min_payment, &overpayment, &total_sum);
  ck_assert_double_eq_tol(max_payment, 11122, 1);
  ck_assert_double_eq_tol(min_payment, 0, 1e-1);
  ck_assert_double_eq_tol(overpayment, 167333, 1);
  ck_assert_double_eq_tol(total_sum, 667333, 1);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_14) {
  char *credit_data = "500000 5 12 d";
  double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
  int status = credit_calculate(credit_data, &max_payment, &min_payment, &overpayment, &total_sum);
  ck_assert_double_eq_tol(max_payment, 13333, 1);
  ck_assert_double_eq_tol(min_payment, 8416, 1);
  ck_assert_double_eq_tol(overpayment, 152500, 1);
  ck_assert_double_eq_tol(total_sum, 652500, 1);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_15) {
  char *credit_data = "500000 5 12a d";
  double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
  int status = credit_calculate(credit_data, &max_payment, &min_payment, &overpayment, &total_sum);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(test_16) {
  char *credit_data = "500000 5 12";
  double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
  int status = credit_calculate(credit_data, &max_payment, &min_payment, &overpayment, &total_sum);
  ck_assert_int_eq(status, 0);
}
END_TEST

Suite *calc_suite(void) {
  Suite *suite = suite_create("calc");
  TCase *tcase_core = tcase_create("calc");
  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);
  tcase_add_test(tcase_core, test_8);
  tcase_add_test(tcase_core, test_9);
  tcase_add_test(tcase_core, test_10);
  tcase_add_test(tcase_core, test_11);
  tcase_add_test(tcase_core, test_12);
  tcase_add_test(tcase_core, test_13);
  tcase_add_test(tcase_core, test_14);
  tcase_add_test(tcase_core, test_15);
  tcase_add_test(tcase_core, test_16);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = calc_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  srunner_free(suite_runner);
  return 0;
}