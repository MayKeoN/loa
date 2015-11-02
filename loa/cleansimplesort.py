import sys

numfile = open(str(sys.argv[1]), "r")
# firstline = str(open(str(sys.argv[1]), "r").readline)
sort = []
i = 0
n = 0
sort = numfile.readlines()
for line in numfile:
	sort.append(long(line))
	if (i > 1000000):
		n += 1
		i = 0
		print str(n)+" x 1,000,000"
	i += 1
	if (n > 2):
		break
print "Done Appending..."
sort = sorted(sort, reverse=False)
print "Done Sorting..."
with open(sys.argv[2], 'a') as f:
   for s in sort:
	   f.write(str(s))
print "Done Writing Out..."

# for s in sort:
# 	print(s)
print "Done Printing Out..."

print "Exit"