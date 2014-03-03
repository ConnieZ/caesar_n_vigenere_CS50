#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
       
    // checking if there's more than 1 command lines
    if (argc != 2)
    {
        printf("Please provide a keyword\n");
        return 1;
    }
    
    // saving the keyword and its length
    string keyword = argv[1];
    int keylength = strlen(keyword);
       
    // issue detector (in case there's other than alphabetical chars in the keyword
    int problem;
    
    // checking the keyword for alphabetical characters and, at the same time, converting it
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        if (isalpha(keyword[i]))
        {
            if (islower(keyword[i]))
            {
                keyword[i] = keyword[i] - 'a';                
            }
            else
            {
                keyword[i] = keyword[i] - 'A';                
            }
        }
        else
        {
            problem = 1;
        }
        
    }
    
    // making sure the keyword is strictly alphabetical 
    if (problem == 1)
    {    
        printf("Please provide a keyword\n");
        return 1;
    }
        
    // getting the plaintext
    string text = GetString();
    
    // saving the starting point of keyword counting and future individual chars
    int counter = 0;
    int letter;
    
    int textlength = strlen(text);    
    
    // encrypting the message
    for (int i = 0; i < textlength; i++)
    {
       char converter;
       if (isalpha(text[i]))
           if (isupper(text[i]))
           {
               converter = 'A';  
               letter = (text[i] - converter + keyword[counter])%26 + converter;
               printf("%c", (char) letter);
               counter++;
               counter %= keylength;              
           }
           else 
           {
               converter = 'a';
               letter = (text[i] - converter + keyword[counter])%26 + converter;
               printf("%c", (char) letter);
               counter++;
               counter %= keylength; 
           }
       else
       {
           printf("%c", (char) text[i]);
       }
                 
    }
    printf("\n");
    
    
}
    
