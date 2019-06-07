
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_char(string s);
void encryption(string s, string key);
string change_key(string s);
bool is_char(char c)
{
    return ((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z'));
}
int main(int argc, string argv[])
{
    if(argc != 2 || check_char(argv[1]))
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    string s = get_string("plaintext: ");
    encryption(s, argv[1]);
}

bool check_char(string s)
{
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            continue;
        }
        else
            return 1;
    }
    return 0;   
}

void encryption(string s, string key)
{
    int n = strlen(s), m = strlen(key);
    int j = 0;
    for(int i = 0; i < m; i++)
    {
        if(key[i]>='A' && key[i] <= 'Z')
            key[i]+=32;
    }
    for(int i = 0; i < n; i++)
    {
        if(is_char(s[i]))
        {
            int x = s[i], fast = 0, last = 0;
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                fast = 97, last = 123;
            }
            else 
            {
                fast = 65, last = 91;
            }
            x = x + (key[j++] - 'a');
            j =  j % m;
            while(x > last)
                x = (x % last) + fast;
            s[i] = x;
        }
    }
    printf("ciphertext: %s\n",s);
}
