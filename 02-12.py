import re

limit = {'red':12, 'blue':14, 'green':13}

part1 = 0
part2 = 0

for i, line in enumerate(open("input-02-12.txt")):
    res = re.findall(r'(\d+) (red|blue|green)', line)
    if not any(int(j[0])>limit[j[1]] for j in res):
        part1 += i+1

for line in open("input-02-12.txt"):
    res = re.findall(r'(\d+) (red|blue|green)', line)
    init = {'red':0, 'blue':0, 'green':0}
    for num, colour in res:
        init[colour] = max(init[colour], int(num))
    part2 += init['red'] * init['blue'] * init['green']

print(part1, part2)