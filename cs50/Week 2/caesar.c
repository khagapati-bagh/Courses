#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool is_char(char c)//is it char 
{
    return ((c >= 'a' && c <= 'z') || (c  >= 'A' && c <= 'Z'));
}
void encode(string s, int key)//encoding function
{
    int n = strlen(s);
    
    for(int i = 0; i < n; i++)
    {
        if(is_char(s[i]))
        {
            int x = s[i], fast = 0, last = 0;
            x += key;
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                fast = 96, last = 122;
            }
            else 
            {
                fast = 64, last = 90;
            }
            while(x > last)
                x = (x % last) + fast;
            s[i] = x;
        }
    }
    printf("ciphertext: %s\n",s);
}

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key=0 , n = strlen(argv[1]);
    for(int i = 0; i < n; i++)//convert string to integer
    {
       if(argv[1][i] < '0' || argv[1][i] > '9')
        {    
            printf("Usage: ./caesar key\n");
            return 1;
        }
        key = key * 10 + (argv[1][i] -'0');
    }
    string s = get_string("plaintext: ");
    encode(s, key);
}
