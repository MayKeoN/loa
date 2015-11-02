import sys

def ackdos(m, n):
	if (m == 0):
		return (n + 1)
	if (m and n == 0):
		return (ackdos(m - 1, 1))
	if (m and n):
		return (ackdos(m - 1, ackdos(m, n - 1)))

def acktres(m, n, p):
	if (p == 0):
		return (m + n)
	if (n == 0):
		if (p == 1):
			return (0)
		if (p == 2):
			return (1)
		if (p > 2):
			return (m)
	return (acktres(m, acktres(m, n - 1, p), p - 1))

m = int(sys.argv[1])
n = int(sys.argv[2])
p = int(sys.argv[3])


# print(ackdos(m, n))
print(acktres(m, n, p))