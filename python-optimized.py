import random
import math
import time
import sys

startTime = 0
endTime = 0
items = [1,2,3,4]
rolls = 0
maxOnes = 0
ones = 0
maxRolls = int(sys.argv[1])
print("Running for ",maxRolls," rolls")
rounds = 231

startTime = math.floor(time.time())
while ones < 177 and rolls < maxRolls:
    ones = 0
    choices = random.choices(items, k=rounds)
    for roll in choices:
        if roll == 1:
            ones = ones + 1
    rolls = rolls + 1
    if ones > maxOnes:
        print("Rolls: ",rolls," Ones: ",ones)
        maxOnes = ones
endTime = math.floor(time.time())

print("Highest Ones Roll:",maxOnes)
print("Number of Roll Sessions: ",rolls)
print("Time Elapsed: ",endTime-startTime," seconds")