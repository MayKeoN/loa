list = [9118,9879,9545,9401,9581,1387,2059,1891,2419,2279]

mods = [[2,97,47],[3,89,37],[5,83,23],[7,79,17],[11,13,67],[19,73],[29,71],[31,61],[41,59],[43,53]]

pri = []

su = 0
for i in list:
    pri.append(10001%i)
    su += int(10001/i)
    print(pri)
print(su)
sum = 0
su = 0
for i in range(len(pri)):
    for j in range(len(mods[i])):
        sum += 10001/mods[i][j]
        su += pri[i] / mods[i][j]
        mods[i][j] = pri[i] % mods[i][j]
        if (mods[i][j] == 0):
            print("Operations Needed: ", su)
    #print(mods[i])
print(mods)

print(int(sum))
print(int(su))
