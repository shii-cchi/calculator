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

void credit_calculate(const char *credit_data, char *result);
credit_t clear(credit_t *credit);
void calc(credit_t *credit);

