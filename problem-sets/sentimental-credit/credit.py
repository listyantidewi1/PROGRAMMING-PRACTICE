# TODO

import math

# ask for credit card number

number = input("Number: ")
n = int(number)
n_checktype = int(number)

# count number of digits
length = 0

for i in range(0, len(number)):
    if number[i].isdigit() == True:
        length += 1
    else:
        number = input("Number: ")

# print(length)

if length < 13 or length > 16:
    print("INVALID")
else:
    sum = 0
    sum = int(number) % 10 # getting the last digit
    number = int(number) / 10 # chopping the last digit away
    number = math.trunc(number)
    # print(number)

    while(number):
        temp = (number % 10) * 2 # get rightmost digit and double the val
        if temp > 9:
            temp = temp - 9
        sum = sum + temp # add current digit to sum
        number = math.trunc(number / 10) # throw rightmost digit away
        temp = number % 10 # get another rightmost figit
        sum = sum + temp # add current digit to sum
        number = math.trunc(number / 10) # throw right digit away

    while(n > 10):
        n = n / 10

    n = math.trunc(n)

    print("sum: ", sum," leftmost: ",n)

    if sum % 10:
        print("INVALID")
    else:
        print("Valid")
        number1 = n_checktype
        number2 = n_checktype
        while(n_checktype):
            number2 = number1
            number1 = n_checktype
            n_checktype /= 10
        print("number2", number2)
        if number2 == 34 or number2 == 37:
            print("AMEX")
        elif (number2 >= 51 and number2 <=55) or number2 == 22:
            print("MASTERCARD")
        elif number2 >= 40 and number2 <= 49:
            print("VISA")
        else:
            print("INVALID")