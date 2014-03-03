#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key;
    string text;
    int letter;
    
    // checking if there's more than 1 command lines and defining the key
    if (argc != 2 || atoi(argv[1])< 0)
    {
       printf("Please provide a non-negative key\n");
       return 1;
    }
    else
    {
       key = atoi(argv[1]);   
    }
    
    // requesting the plaintext
    text = GetString();
    
    // encrypting the plaintext
    for (int i = 0, n = strlen(text); i < n; i++)
    {
       if (isalpha(text[i]))
       {
           if (islower(text[i]))
           {
               int converter = 'a';
               letter = (text[i] - converter + key)%26 + converter;
               printf("%c", (char) letter);
                   
           }
           else
           {
               int converter = 'A';
               letter = (text[i] - converter + key)%26 + converter;
               printf("%c", (char) letter);
           }
       }
       else
       {
           printf("%c", (char) text[i]);
       }
    }
    printf("\n");
}    


