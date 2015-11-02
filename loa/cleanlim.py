import sys

numfile = open(str(sys.argv[1]), "r")
gap = []
i = 0
n = 0
limit = pow(2, int(sys.argv[3]))
for line in numfile:
	if (long(line) > limit):
		break
	gap.append(long(line))
	i += 1
	if (i > 1000000):
		n += 1
		i = 0
		print ("Num Index: "+str(n)+" * 1,000,000")
	# if (n > 2):
	# 	break
print ("Done GapIng...")
# gap = sorted(gap)
print ("Done Sorting...")
with open(sys.argv[2], 'a') as f:
   for g in gap:
	   f.write(str(g)+"\n")
print "Done Writing Out..."
