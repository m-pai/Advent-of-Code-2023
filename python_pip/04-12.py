file = open('python_pip/input-04-12.txt').readlines()

total = 0
cards = [1 for _ in file]

for i, line in enumerate(file):
    line = line.split(":")[1]
    win, elf = line.split("|")
    win, elf = set(win.split()), set(elf.split())
    n = len(win.intersection(elf))
    if n>0:
        total += 2**(n-1)
    for j in range(n):
        cards[i + j + 1] += cards[i]

print(total, sum(cards))