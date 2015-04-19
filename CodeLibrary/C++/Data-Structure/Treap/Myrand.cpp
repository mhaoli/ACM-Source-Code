struct MyRand {
        int a,b,p; long long x;
        MyRand(){a=810;b=1102;p=1992122981;x=617;} 
        int rand(){return x=(a*x+b)%p;} 
}; 
