with open('407.txt','r') as f:
    s=f.readline();
    an=s.split(',')
    an=an[:-1]
    print(sum(map(int,an)))
