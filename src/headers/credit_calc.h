#ifndef SRC_HEADERS_CREDIT_CALC_H
#define SRC_HEADERS_CREDIT_CALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 255

typedef struct credit_data {
  double sum;
  double percent;
  int term;
  char type;
  double max_payment;
  double min_payment;
  double overpayment;
  double total_sum;
} credit_t;

int credit_calculate(char *credit_data, double *max_payment,
                     double *min_payment, double *overpayment,
                     double *total_sum);
void clear(credit_t *credit);
void calc(credit_t *credit);

#endif  // SRC_HEADERS_CREDIT_CALC_H
