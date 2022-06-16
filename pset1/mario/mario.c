#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size = 0;
    while (true)
    {
        size = get_int("Tamanho: \n");
        if (size > 8 || size < 1)
        {
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i + j < size - 1)
                        printf(" ");
                    else
                        printf("#");
                }
                printf("  ");
                for (int j = 0; j < size; j++)
                {
                    if (i + j > size - 2)
                        printf("#");
                }
                printf("\n");
            }
            break;
        }
    }
    return 0;
}