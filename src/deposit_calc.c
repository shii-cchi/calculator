#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#define LEN 255

typedef struct credit_data {
    double sum;
    double percent;
    int term;
    double tax_rate;
    int period;
    int capitalization;

    char type;
    double max_payment;
    double min_payment;
    double overpayment;
    double total_sum;
} credit_t;