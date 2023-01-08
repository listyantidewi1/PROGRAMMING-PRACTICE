# TODO

# ask for credit card number

number = input("Number: ")

# count number of digits
length = 0

for i in range(0, len(number)):
    if number[i].isdigit() == True:
        length += 1

# print(length)