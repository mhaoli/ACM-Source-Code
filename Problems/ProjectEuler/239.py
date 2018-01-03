fact = []
has = dict()

def init():
    global fact
    fact = [1]
    for i in range(1,101):
        fact.append(fact[-1]*i)
    print(fact[-5:])

def f(n, m):
    if n == 0:
        return fact[m]
    if n < 0:
        return 0
    if (n,m) in has:
        return has[(n,m)]
    ans = (n-1) * f(n-2, m+1) + m * f(n-1, m)
    has[(n,m)] = ans
    return ans

def main():
    global has
    a = 25*24*23//6 
    has = dict()
    p = a * f(22, 75) / fact[100]
    print("p = {:.12f}".format(p))

if __name__=='__main__':
    init()
    # test()
    main()
