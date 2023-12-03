#advent of code 2023 day 1 question 2

import re

dict = {
    "one":1,
    "two":2,
    "three": 3,
    "four": 4,
    "five":5,
    "six": 6,
    "seven": 7,
    "eight": 8,
    "nine": 9
}

def strung(k):
    new = []
    for i in re.findall("(?=(one|two|three|four|five|six|seven|eight|nine|\d))", k):
        if i.isdigit():
            new.append(int(i))
        else:
            new.append(dict[i])
    if len(new) != 0: return 10 * new[0]+ new[-1] 

sum = 0
with open("python_pip/input-01-12.txt") as file:
    for line in file:
        sum += strung(line.rstrip())

print(sum)