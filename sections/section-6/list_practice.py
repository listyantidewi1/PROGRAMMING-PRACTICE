from random import randint
import sys
MAX_VALUE = 20
LIST_LENGTH = 50


def main():
    # Create a list of LIST_LENGTH random numbers, 0 to MAX_VALUE
    random_nums = [randint(0,MAX_VALUE) for x in range(LIST_LENGTH)]

    # Print the list
    print(random_nums)

    # TODO: Count occurences of '0' in the list
    print(random_nums.count(0))

    # TODO: Print the 15th element of the list
    print(random_nums[14])

    # TODO: Print the length of the list
    print(len(random_nums))


    # Slicing!
    # TODO: Print the first 10 items in the list:
    i = 0
    while i < 10:
        print(random_nums[i])
        i += 1

    # TODO: Print the last 10 items in the list
    i = 39
    while i < 50:
        print(random_nums[i])
        i += i


    # TODO: Print every third item in the list:
    i = 2
    while i < 50:
        print(random_nums[i])
        i += 3


    # Exercise:

    # TODO 1: Print the values in Reverse-order
    random_nums.reverse()
    print(random_nums)

    print(random_nums[len(random_nums):0:-1])
    print(random_nums[::-1])


    # TODO 2: Print the even values of the list
    i = 0
    while i < 50:
        if i % 2 == 0:
            print(random_nums[i])
        i += 1



    # TODO 3: Print the odd-indexed values of the list
    i = 0
    while i < 50:
        if i % 2 == 1:
            print(random_nums[i])
        i += 1



if __name__ == "__main__":
    main()