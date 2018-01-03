
has = dict()
n = 50

def calc(q, x, ys, no):
    global has
    if ys < 0 or no < 0:
        return 0
    if x == n:
        # print(q, x, ys, no)
        if ys == 1:
            return (q-x)
        else:
            return x
    if (x,ys,no) in has:
        return has[(x,ys,no)]
    ans = (q-x) * calc(q, x+1, ys-1, no) + x * calc(q, x+1, ys, no-1)
    has[(x,ys,no)] = ans
    return ans

def gao(q, ys = 20, no = 30):
    global has
    has = dict()
    return calc(q, 1, ys, no) / (q**50)

def test():
    q = 51
    step = 1
    end = 60
    while q <= end:
        t = gao(q)
        print("q = {}, p = {:.8f}".format(q, t / (q**50)))
        q += step

def main():
    l = 52; r = 53; cnt = 100
    while cnt >= 0:
        mid = (l + r) / 2
        p = gao(mid)
        # print("q = {:.5f}, p = {:.8f}".format(q, t / (q**50)))
        if p < 0.02:
            r = mid
        else:
            l = mid
        cnt -= 1
    print("p = {:.10f}".format(l));

if __name__=='__main__':
    pass
    # test()
    main()
