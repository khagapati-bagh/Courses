#include <stdio.h>
#include <cs50.h>
#include <string.h>
//function declaration
bool is_valid(char *card);
bool card_valid(char *card);

int main(void)
{
    char card[12];
    int flag = 0;
    do{
        printf("Number: ");
        scanf("%s",card);
        flag = is_valid(card);
        //printf("%s\n",card);
    }while(flag);
    //printf("%s\n",card);
    int len = strlen(card);
    if(len < 13 || len > 16 || card_valid(card) == 0)
        printf("INVALID\n");
    else
    {
        if(card[0] == '4')
            printf("VISA\n");
        else if(len == 15 && card[0] == '3' && (card[1] == '4' || card[1] == '7'))
            printf("AMEX\n");
        else if(card[0] == '5' && (card[1] == '1' || card[1] == '2' || card[1] == '3' || card[1] == '4' || card[1] == '5'))
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
    }
    return  0;
}

bool is_valid(char *card){
    int len = strlen(card);
    //printf("%d\n",len);
    /*if(len > 16 || len < 13)
        return 1;*/
    for(int i = 0; i < len; i++)
        if(card[i] > '9' || card[i] < '0')
            return 1;
    return 0;
}

bool card_valid(char *card)
{
    int len = strlen(card);
    int num, sum = 0;
    for(int i = len-2; i >= 0; i -=2)
    {
        num = (card[i]-'0') * 2;
        while(num)
        {
            sum +=(num % 10);
            num /=10;
        }
    }
    //printf("%d\n", sum);
    for(int i = len - 1; i >= 0; i -=2)
    {
        sum +=(card[i] - '0');
    }
    //printf("%d\n",sum);
    if(sum % 10 == 0)
        return 1;
    return 0;
}
