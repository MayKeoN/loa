list65 = []
list18 = []

i = 0
while (i < 1807):
    list65.append(4736 + i)
    i += 1
    list18.append(i)

i = 0
n = 1
k = 1
while (i < 1807):
    n *= list65[i]
    k *= list18[i]
    i += 1

i = 0
j = 0
lvl = 0
ok = 1
while (lvl < 2 * n):
    i += 1
    lvl = pow(2, i)
    if (ok and lvl > k):
        ok = 0
        j = i
        print("KSize:"+str(i))
print("NSize:"+str(i))
print("Diff Order: "+str(i - j))
