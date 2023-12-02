# advent of code 2023 day 1 question 1

#function to convert a string to a number
def strnum(i):
    a = ''.join(c for c in i if c.isdigit())
    return a

#function to take the first and last numbers of a string and convert it into an integer
def strtonum(a):
    c = a[0] + a[-1]
    return int(c)

sum = 0
with open("input-01-12.txt") as file:
    for line in file:
        sum = sum + (strtonum(strnum(line.rstrip())))

print(sum)