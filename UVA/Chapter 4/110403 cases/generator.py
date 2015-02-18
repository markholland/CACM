import random

N = 100

print N

for n in xrange(N):
    #P = random.randint(1, 1000)
    P = 1000
    print P
    for p in xrange(P):
        print random.randint(1, 100)
    print " "
