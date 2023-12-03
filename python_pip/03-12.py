grid = open('python_pip/input-03-12.txt').read().splitlines()

# Part 1

cs = set()

for i, row in enumerate(grid):
    for j, char in enumerate(row):
        if char.isdigit() or char == '.':
            continue
        for cr in [i-1,i, i+1]:
            for cc in [j-1,j,j+1]:
                if cr<0 or cr >= len(grid) or cc<0 or cc >= len(grid[cr]) or not grid[cr][cc].isdigit():
                    continue
                while cc>0 and grid[cr][cc-1].isdigit():
                    cc -=1
                cs.add((cr,cc))

part1 = []

for x,y in cs:
    s = ''
    while y<len(grid[x]) and grid[x][y].isdigit():
        s += grid[x][y]
        y+=1
    part1.append(int(s))

print(sum(part1))

#Part 2

part2 = 0
for i, row in enumerate(grid):
    for j, char in enumerate(row):
        if char != '*':
            continue

        cs = set()
        for cr in [i-1,i, i+1]:
            for cc in [j-1,j,j+1]:
                if cr<0 or cr >= len(grid) or cc<0 or cc >= len(grid[cr]) or not grid[cr][cc].isdigit():
                    continue
                while cc>0 and grid[cr][cc-1].isdigit():
                    cc -=1
                cs.add((cr,cc))
        if len(cs) != 2:
            continue

        ns=[]
        for x,y in cs:
            s = ''
            while y<len(grid[x]) and grid[x][y].isdigit():
                s += grid[x][y]
                y+=1
            ns.append(int(s))

        part2 += ns[0]*ns[1]

print(part2)