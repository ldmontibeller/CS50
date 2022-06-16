#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void){
    float amount = 0.0;
    do
    {
        amount = get_float("Cash amount: ");
    }
    while(amount < 0.0);

    int coins = 0, coins025 = 0, coins010 = 0, coins005 = 0, coins001 = 0;
    double fractional = 0.0;
    double integral = 0.0;


    fractional = modf(amount/0.25, &integral);
    coins025 = (int) integral;
    coins += coins025;
    amount -= (coins025*0.25);
    printf("0.25 coins are: %d\n", coins025);
    printf("Amount after counting the 0.25 coins is: %f\n",amount);

    //COMPUTERS CANT REPRESENT 0.1 IN BINARY CORRECTLY
    float rounded_div = round(amount/0.10);

    fractional = modf(rounded_div, &integral);
    printf("%f\n", fractional);
    coins010 = (int) integral;
    coins += coins010;
    amount -= (coins010*0.10);
    printf("0.10 coins are: %d\n", coins010);
    printf("Amount after counting the 0.10 coins is: %f\n",amount);

    fractional = modf(amount/0.05, &integral);
    coins005 = (int) integral;
    coins += coins005;
    amount -= (coins005*0.05);
    printf("0.05 coins are: %d\n", coins005);
    printf("Amount after counting the 0.05 coins is: %f\n",amount);
    coins001 = (int) round(amount/0.01);
    coins += coins001;
    amount -= (coins001*0.01);
    printf("0.01 coins are: %d\n", coins001);
    printf("Amount after counting the 0.01 coins is: %f\n",amount);

    printf("Considering values of coins being 0.25, 0.10, 0.05 and 0.01\n");
    printf("The total number of coins is:\n");
    printf("%d\n", coins);
    return 0;
}