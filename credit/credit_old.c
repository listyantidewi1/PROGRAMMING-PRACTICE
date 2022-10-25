/*

Most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

*/
#include <stdio.h>
#include <cs50.h>

bool checkSum(long int, int);
int checkLength(long int);
string checkCardType(long int);

int main(void)
{
    long int creditCard;

    do
    {
        creditCard = get_long("Number: ");
    }
    while(creditCard < 1);

    int length = checkLength(creditCard);
    if (length == 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int checkSumValue = checkSum(creditCard, length);
    if (checkSumValue != 1)
    {
        printf("INVALID\n");
        return 0;
    }

    string cardType = checkCardType(creditCard);
    printf("%s\n", cardType);

    return 0;
}

bool checkSum(long int creditCard, int length) {
    int i=0;
    int temp=0;
    int first=0;
    int second=0;
    int final=0;

    while(creditCard){
        if (i%2 != 0) {
            first = ((creditCard%10)*2);
            if (first>9){
                while(first){
                    temp += first%10;
                    first /= 10;
                }
            }
            temp += first;
        } else {
            second += creditCard%10;
        }
        creditCard /= 10;
        i++;
    }

    temp += second;

    final = temp%10;

    if (final == 0){
        return 1;
    }

    return 0;
}

int checkLength(long int creditCard) {
  int i=1;
  while(creditCard>9){
      i++;
      creditCard/=10;
  }
  if (i<13 || i>16) {
      return 0;
  }
  return i;
}

string checkCardType(long int creditCard) {
    // number2 will hold the first two digits.
    long int number1 = creditCard, number2 = creditCard;
    while (creditCard){
        number2 = number1;
        number1 = creditCard;
        creditCard /= 10;
    }

    if (number2 == 34 || number2 ==37) {
        return "AMEX";
    }

    if (number2 >= 51 && number2 <= 55) {
        return "MASTERCARD";
    }

    if (number2 >= 40 && number2 <=49) {
        return "VISA";
    }

    return "INVALID";
}