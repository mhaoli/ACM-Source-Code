import time

def main():
    N = 100*101*201//6 - 50*51*101//6
    print(N)
    dp=[]
    ticks = time.time()
    dp = [[[0] * (N+1) for j in range(51)] for i in range(2)]

    print("time = {}".format(time.time()-ticks))
    ticks = time.time()

    dp[0][0][0] = 1
    dp[0][1][1] = 1
    now = 0
    nxt = 1
    t = 0
    mx = 1
    for i in range(2,101):
        print("i = {}".format(i))
        mx = min(N, i*(i+1)*(2*i+1)//6)
        for j in range(51):
            for k in range(mx+1):
                t = dp[now][j][k]
                if j >= 1 and k >= i*i:
                    t += dp[now][j-1][k-i*i]
                dp[nxt][j][k] = min(2, t)
        now, nxt = nxt, now

    s=0
    for i in range(N+1):
        if dp[now][50][i]==1:
            s+=i
    print(s)
    print("time = {}".format(time.time()-ticks))
    
if __name__=='__main__':
    main()
    # test()
