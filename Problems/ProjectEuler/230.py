
an=[0,0]
an[0]='1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679'
an[1]='8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196'

lens=[100,100]
def init(n):
    global lens
    while lens[-1]<n:
        lens.append(lens[-1]+lens[-2])

def rec(p, n):
    if p<2:
        assert n<100
        return an[p][n]
    if n<lens[p-2]:
        return rec(p-2, n)
    return rec(p-1, n-lens[p-2])

def calc(n):
    n-=1
    i=0
    while lens[i]<n:
        i+=1
    return int(rec(i, n))

# test
# an[0]='1415926535'
# an[1]='8979323846'
# lens=[10,10,20,30,50]
# print(calc(35))

if __name__=='__main__':
    N = 17
    def gao(n):
        return (127+19*n) * (7**n)
    init(gao(N))
    s = 0
    for i in range(N+1):
        s += (10**i) * calc(gao(i))
    print(s)
