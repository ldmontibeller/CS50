#include <stdio.h>

int main(void)
{
    int product = 12;
    if((product % 10) >= 0)
        {
            int sum_of_product_digits = 0;
            sum_of_product_digits = product % 10;
            product /= 10;
            sum_of_product_digits += (product % 10);
            product = sum_of_product_digits;
        }
    printf("%d\n", product);
}