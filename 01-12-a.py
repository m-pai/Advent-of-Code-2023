# advent of code 2023 day 1 question 1

def strnum(i):
    a = ''.join(c for c in i if c.isdigit())
    return a

def strtonum(a):
    c = a[0] + a[-1]
    return int(c)

sum = 0
with open("input-01-12.txt") as file:
    for line in file:
        sum = sum + (strtonum(strnum(line.rstrip())))

print(sum)