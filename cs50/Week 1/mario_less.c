#include <cs50.h>
#include <stdio.h>

void space(int n);//function declaration
void bricks(int n);//function declaration
int main(void)
{
    int n;
    do //loop continue until entered valid input
    {
        n = get_int("Height: ");
    }
    while(n < 1 || n > 8);//checking condition
    
    for(int i = 1; i <= n; i++)
    {
        //space(n-i);//call space function
        //bricks(i); // call bricks funtion
        for(int j = 0; j < n-i; j++)//print space
        {
            printf(" ");
        }
        
        for(int j = 0; j < i; j++)//print bricks
        {
            printf("#");
        }
        printf("\n");//print new line
    }
    return 0;
}
