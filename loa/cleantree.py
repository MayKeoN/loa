import sys

numfile = open(str(sys.argv[1]), "r")
limit = pow(2, 63)
gap = []
i = 0
n = 0
for line in numfile:
	mask = line.split(":", 2)[0]
	gap.append(str(long(mask) - limit))
	# print str(long(mask) - limit)
	# print "mask: "+mask.strip("\n")+" - limit: "+str(limit)+" = "+str(long(mask) - limit)
	limit = long(mask)
	i += 1
	if (i > 1000000):
		n += 1
		i = 0
		print ("Num Index: "+str(n)+" * 1,000,000")
	# if (n > 2):
	# 	break
print ("Done GapIng...")
gap = sorted(gap)
print ("Done Sorting...")
with open(sys.argv[2], 'a') as f:
   for g in gap:
	   f.write(g+"\n")
print "Done Writing Out..."

print(pow(2, 64))