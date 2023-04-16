#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

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

int credit_calculate(char *credit_data, double *max_payment, double *min_payment, double *overpayment, double *total_sum);
credit_t clear(credit_t *credit);
void calc(credit_t *credit);

