# TODO

height = 0

height = input("Height: ")

if int(height) < 0 or int(height) > 8:
    height = input("Height: ")

for i in range(0, int(height)):
    for j in range(int(height), (i + 1)):
        print(" ", end=" ")
    for k in range(0,(i+1)):
        print("#", end=" ")
    print(" ")
    for l in range(0, (i+1)):
        print("#", end=" ")
    print("\n")