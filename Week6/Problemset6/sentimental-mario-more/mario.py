# TODO
from cs50 import get_int

while True:
    height = get_int("Height : ")
    if height >= 1 and height <= 8:
        break

for i in range(height):
    for j in range(height - 1, i, -1):
        print(" ", end = "")
    for k in range(0 , i + 1, 1):
        print("#", end = "")
    for l in range(2):
        print(" ", end = "")
    for m in range(0 , i + 1, 1):
        print("#", end = "")
    print("")