#include <stdio.h>
#include <cs50.h>
#include <math.h>

//prototypes
long userinput(void);
string cctype(int d1, int d2, int lenght);
int checksum(int x);

int main(void)
{
    //Credit card input
    long cardnumber = userinput();

    //store digits into their own variables, starting from right to left
    int d1 = (cardnumber % 10) / 1;
    int d2 = (cardnumber % 100) / 10;
    int d3 = (cardnumber % 1000) / 100;
    int d4 = (cardnumber % 10000) / 1000;
    int d5 = (cardnumber % 100000) / 10000;
    int d6 = (cardnumber % 1000000) / 100000;
    int d7 = (cardnumber % 10000000) / 1000000;
    int d8 = (cardnumber % 100000000) / 10000000;
    int d9 = (cardnumber % 1000000000) / 100000000;
    int d10 = (cardnumber % 10000000000) / 1000000000;
    int d11 = (cardnumber % 100000000000) / 10000000000;
    int d12 = (cardnumber % 1000000000000) / 100000000000;
    int d13 = (cardnumber % 10000000000000) / 1000000000000;
    int d14 = (cardnumber % 100000000000000) / 10000000000000;
    int d15 = (cardnumber % 1000000000000000) / 100000000000000;
    int d16 = (cardnumber % 10000000000000000) / 1000000000000000;
    int d17 = (cardnumber % 100000000000000000) / 10000000000000000;

    //check if there are more than 16 digits or less than 13
    if (d17 > 0 || cardnumber / 1000000000000 == 0)
    {
        printf("INVALID\n");
    }

    else
    {
        //checksum to determine if the card is legit
        long sumA = checksum(d2) + checksum(d4) + checksum(d6) + checksum(d8) + checksum(d10) + checksum(d12) + checksum(d14) + checksum(d16);
        long sumB = d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15;
        long totalSum = sumA + sumB;
        //Dtermines type if last number of sum is zero
        if (totalSum % 10 == 0)
        {
            //Assign string to variable cartype, to be determined by custom function
            string cardtype;
            if (d16 > 0)
            {
                cardtype = cctype(d16, d15, 16);
                printf("%s\n", cardtype);
            }
            else if (d15 > 0)
            {
                cardtype = cctype(d15, d14, 15);
                printf("%s\n", cardtype);
            }
            else if (d14 > 0)
            {
                cardtype = cctype(d14, d13, 14);
                printf("%s\n", cardtype);
            }
            else if (d13 > 0)
            {
                cardtype = cctype(d13, d12, 13);
                printf("%s\n", cardtype);
            }
            else
            {
                printf("INVALID\n");
            }

        }

        else
        {
            printf("INVALID\n");
        }
    }



}

//Credit card prompt
long userinput(void)
{
    long input = 0;

    do
    {
        input = get_long("Enter Credit Card Number: ");
        if (input <= 0)
        {
            printf("INVALID\n");
        }
    }
    //reject zero and negative numbers
    while (input <= 0);

    return input;
}

//Operation for the sum of every other digit
int checksum(int x)
{
    //Multiply every other digit by 2, starting from the right
    int product = x * 2;
    //The result is placed into two digit format (ie 18 -> 1+8)
    int a = product % 10;
    int b = product / 10;
    //Return the sum of both digits
    return a + b;
}

//Determine card type (VISA, MASTERCARD or AMEX)
string cctype(int d1, int d2, int length)
{
    string type = "INVALID";
    //For VISA, when first digit is 4 and length is 16 digits
    if (d1 == 4 && length == 16)
    {
        type = "VISA";
        return type;
    }
    //For VISA, when first digit is 4 and length is 13 digits
    if (d1 == 4 && length == 13)
    {
        type = "VISA";
        return type;
    }
    //For AMEX, when length is 15 digits, first digit is 3 and second digit is either 4 or 7
    if (length == 15 && (d1 == 3) && ((d2 == 4) || (d2 == 7)))
    {
        type = "AMEX";
        return type;
    }
    //For MASTERCARD, when length is 16 digits, first digit is 5, and second digit is either 1, 2, 3, 4, or 5
    if (length == 16 && (d1 == 5) && ((d2 == 1) || (d2 == 2) || (d2 == 3) || (d2 == 4) || (d2 == 5)))
    {
        type = "MASTERCARD";
        return type;
    }
    //Returns INVALID if no conditions are met
    return type;
}