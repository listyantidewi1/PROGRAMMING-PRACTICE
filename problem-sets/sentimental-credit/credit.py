# TODO

import math

# ask for credit card number

number = input("Number: ")

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
