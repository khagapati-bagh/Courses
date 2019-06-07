#include <cs50.h>
#include <stdio.h>

void space(int n);//function declaration
void bricks(int n);
int main(void)
{
    int n;
    do//until valid input
    {
        n = get_int("Height: ");
    }while(n < 1 || n > 8);
    
    for(int i = 1; i <= n; i++)
    {
        space(n-i);//print space
        bricks(i);//print bricks
        space(2);//single space
        bricks(i);//bricks
        printf("\n");
    }
    return 0;
}

void space(int n)//function definition
{
    for(int i = 0; i < n; i++)
        printf(" ");
}
void bricks(int n)//function definition
{
    for(int i = 0; i < n; i++)
        printf("#");
}

