import random
import sys

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print "usage: python genrand.py n k\n for n random numbers from 1..k"
        sys.exit(1)
    else:
        n = int(sys.argv[1])
        k = int(sys.argv[2])
        for i in xrange(n):
            print str(random.randint(1,k))
        
