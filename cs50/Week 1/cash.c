#include <cs50.h>
#include <math.h>
#include <stdio.h>

int make_change(int n)
{
    int res = 0;
    if(n >= 25)
    {
        res += n/25;
        n %=25;//remainder
    }
    if(n >= 10){
        res += n/10;
        n %=10;
    }
    if(n >= 5){
        res += n/5;
        n %=5;
    }
    res +=n;
    return res;
}

int main(void)
{
    float dollars;
    do{//until valid input
        dollars = get_float("Change owed: ");
    }while(dollars <= 0);
    
    int cents = round(dollars * 100);//convert to cents
    int result = make_change(cents);//call function
    printf("%d\n", result);
    return 0;
}
