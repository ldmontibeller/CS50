#include <stdio.h>
#include <cs50.h>

//Function prototypes
int numberOfDigits(long n);
int cardValidation(long n);

int main(void)
{
    long card = 0;
    int test = 0;
    int digits = 0;

    do
    {
        card = get_long("Type a credit card number: ");
    }
    while(card < 0);

    //Number of digits verification
    digits = numberOfDigits(card);
    if(digits < 13 || digits > 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //Card validation - Luhn Algorithm
    test = cardValidation(card);
    if(test == 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //Card classfication
    if(digits == 15)
    {
        //Get first two digits
        card /= 10000000000000;
        //printf("%ld\n", card);
        if (card == 34 || card == 37)
        {
            printf("AMEX\n");
            return 0;
        } else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else if (digits == 16)
    {
        //Get first two digits
        card /= 100000000000000;
        if(card > 55)
        {
            printf("INVALID\n");
            return 0;
        }
        if(card < 51) {
            //Chech if it's VISA
            if ((card/10) == 4)
            {
                printf("VISA\n");
                return 0;
            }
            printf("INVALID\n");
            return 0;
        }
        printf("MASTERCARD\n");
        return 0;
    }
    else if (digits < 16)
    {
        if(digits == 15)
        {
            //Get the first digit of 15
            card /= 100000000000000;
            if (card == 4)
            {
                printf("VISA\n");
                return 0;
            }
            printf("INVALID\n");
            return 0;
        }
        if(digits == 14)
        {
            //Get the first digit of 14
            card /= 10000000000000;
            if (card == 4)
            {
                printf("VISA\n");
                return 0;
            }
            printf("INVALID\n");
            return 0;
        }
        //Get the first digit of 13
        card /= 1000000000000;
        if (card == 4)
        {
            printf("VISA\n");
            return 0;
        }
        printf("INVALID\n");
        return 0;
    }
    return 0;
}

int numberOfDigits(long n)
{
    int counter = 0;
    do
    {
        n /= 10;
        counter++;
    }
    while(n != 0);
    return counter;
}

int cardValidation(long card_number)
{
    int product = 0;
    int sum_of_products = 0;
    int sum = 0;
    long n = card_number;

    //First the sum of digits that wont be multiplied
    while(n > 0)
    {
        sum += n % 10;
        n /= 100;
    }
    //printf("Sum of the digits that are not multiplied: %d\n", sum);

    //Now the sum of the digits that will be multiplied by 2
    //Starting from the second-last digit
    n = card_number;
    n /= 10;
    //printf("%ld\n", n);
    while(n > 0)
    {
        //printf("**************\n");
        //printf("%ld\n", n);
        product = (n % 10) * 2;
        //printf("%d\n", product);
        //Check if the product has two digits
        if((product % 10) >= 0)
        {
            int sum_of_product_digits = 0;
            sum_of_product_digits = product % 10;
            product /= 10;
            sum_of_product_digits += (product % 10);
            product = sum_of_product_digits;
        }
        sum_of_products += product;
        //printf("%d\n", sum_of_products);
        n /= 100;
    }

    //Check if card is valid
    sum += sum_of_products;
    //printf("total: %d\n", sum);
    if((sum % 10) == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}
