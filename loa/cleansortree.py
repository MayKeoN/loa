import sys

numfile = open(str(sys.argv[1]), "r")
# limit = pow(2, 63)
sort = []
i = 0
n = 0
for line in numfile:
	linarr = line.split(": ", 7)
	sort.append([long(linarr[1].strip(" Num")), long(linarr[3].strip("\n"))])
	if (i > 1000000):
		n += 1
		i = 0
		print str(n)+" x 1,000,000"
	i += 1
	# if (n > 10):
	# 	break
	# print(linarr[1].strip(" Num"))
print "Done Appending..."
# sort.sort()
# print " ".join(sorted(sort))
sort = sorted(sort)
print "Done Sorting..."
with open(sys.argv[2], 'a') as f:
   for s in sort:
	   f.write(str(s[0])+":"+str(s[1])+"\n")
print "Done Writing Out..."
# for s in sort:
	# print str(s[0])+":"+str(s[1])
# print(pow(2, 64))
    # mask = line.split(" ", 2)[1]
    # print "mask: "+mask+"\t - limit: "+str(limit)+" = "+str(long(mask) - limit)
    # limit = long(mask)
