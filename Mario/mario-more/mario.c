#include <stdio.h>
#include <cs50.h>
int main (void)
{
    int blocks;
    do {
    blocks = get_int("How many blocks do you want? \n"    );
    }
    while (blocks < 0 || blocks > 8);

        int dots = blocks - 1;

    for (int row=0; row < blocks; row++)
    {
        for (int dots=0; dots < blocks - row - 1; n++){
                printf(" ");
            }
             for (int i=0; i <= row; i++)
        {

            printf("#");
        }
    printf("\n");
    }

}