# TODO

import math

# ask for credit card number

number = input("Number: ")

# count number of digits
length = 0

for i in range(0, len(number)):
    if number[i].isdigit() == True:
        length += 1

# print(length)

if length < 13 or length > 16:
    print("INVALID")
else:
    sum = 0
    sum = int(number) % 10 # getting the last digit
    number = int(number) / 10 # chopping the last digit away
    number = math.trunc(number)
    # print(number)

    