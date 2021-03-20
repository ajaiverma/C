/*
* This code uses Luhn’s Algorithm to check if the card is valid or invalid. Here is the formula to check if card is valid or invalid
* 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
* 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
* 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
*/

#include <stdio.h>

int main(void)
{
    long card_number;

    printf("Card Number: ");
    scanf("%ld", &card_number);

    int counter = 1;
    int even_sum = 0, odd_sum = 0, first_digit = 0, first_two_digit = 0;

    while (card_number)
    {
        // take the last digit
        int remainder = card_number % 10;

        if (card_number / 100 == 0 && card_number >= 10)
        {
            first_two_digit = card_number;
        }

        // take the remaining number after removing the last digit
        card_number = card_number / 10;

        // check position even or odd
        if (counter++ % 2 == 0)
        {
            int remainder_sum = 2 * remainder;

            if (remainder_sum >= 10)
            {
                while (remainder_sum)
                {
                    int remainder_sum_remainder = remainder_sum % 10;
                    remainder_sum = remainder_sum / 10;

                    even_sum += remainder_sum_remainder;
                }
            }
            else
            {
                even_sum += remainder_sum;
            }
        }
        else
        {
            odd_sum += remainder;
        }

        first_digit = remainder;
    }

    int sum = even_sum + odd_sum;

    // total count increased to 1, so subtracting 1
    counter--;

    // check if remainder is 0 and based on the count, print the particular card type
    if (sum % 10 == 0)
    {
        if (counter == 15 && (first_two_digit == 34 || first_two_digit == 37))
        {
            printf("AMEX\n");
        }
        else if (counter == 16 && (first_two_digit == 51 || first_two_digit == 52 || first_two_digit == 53 || first_two_digit == 54
                                   || first_two_digit == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((counter == 16 || counter == 13) && first_digit == 4)
        {
            printf("VISA\n");
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
