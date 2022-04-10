#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int LETTER_COUNT = 26;

//prototypes
bool all_letters(string letters);
bool repetition(string abc);
string substitution(string validkey, string plaintext);

int main(int arg, string argv[])
{
    //check command line argument count
    if (arg != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //check key length
    if (strlen(argv[1]) != LETTER_COUNT)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //proceed to validate key if two arguments were entered
    //and key has 26 characters
    else
    {
        //store key
        string key = argv[1];

        //check for alphabetic characters
        bool result = all_letters(key);
        if (result == false)
        {
            printf("Key must contain only alphabetical characters.\n");
            return 1;
        }

        //check for duplicates
        bool repeat = repetition(key);
        if (repeat == false)
        {
            printf("Key must not have any duplicates.\n");
            return 1;
        }

        else
        {
            //prompt for plaintext
            string plaintext = get_string("plaintext: \n");
            //Use key to substitute each character
            string cipher = substitution(key, plaintext);
            printf("ciphertext: %s\n", cipher);


        }
    }
}

bool all_letters(string letters)
{
    //checks for all alphabetical char
    for (int i = 0; letters[i] != '\0'; i++)
    {
        if (!(isalpha(letters[i])))
        {
            return false;
        }
    }

    return true;

}

bool repetition(string abc)
{

    //change each character to lowercase
    for (int i = 0; abc[i] != '\0'; i++)
    {
        abc[i] = tolower(abc[i]);
    }
    //compare each character to each other
    for (int i = 0; abc[i] != '\0'; i++)
    {
        for (int j = i + 1; abc[j] != '\0'; j++)
        {
            if (abc[i] == abc[j])
            {
                return false;
            }
        }
    }

    return true;
}

string substitution(string validkey, string plaintext)
{
    char uppercasekey[26];
    char lowercasekey[26];
    int index;

    //stores the key in both upper and lowercase
    for (int i = 0; validkey[i] != '\0'; i++)
    {
        uppercasekey[i] = toupper(validkey[i]);
        lowercasekey[i] = tolower(validkey[i]);

    }

    //substitution
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        //check for alpha characters and lowercase
        if (isalpha(plaintext[i]) && islower(plaintext[i]))
        {
           index = plaintext[i] - 'a';
           plaintext[i] = lowercasekey[index];
        }
        //check for alpha characters and uppercase
        if (isalpha(plaintext[i]) && isupper(plaintext[i]))
        {
            index = plaintext[i] - 'A';
            plaintext[i] = uppercasekey[index];
        }

    }
    //return cipher
    return plaintext;


}