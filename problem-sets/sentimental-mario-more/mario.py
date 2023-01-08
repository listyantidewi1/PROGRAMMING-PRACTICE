# TODO
# recreate mario more

# initial height
height = 0

# ask for height as input
height = input("Height: ")

# keep asking for height if its out of required values
if int(height) < 0 or int(height) > 8:
    height = input("Height: ")

# loop for the rows
for i in range(0, int(height)):
    # loop for the space
    for j in range(int(height), (i + 1), -1):
        print(" ", end="")

    # loop for the #
    for k in range(0, (i+1)):
        print("#", end="")
    print(" ", end="")
    for l in range(0, (i+1)):
        print("#", end="")
    print("\n", end="")