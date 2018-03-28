struct frac{
    // value = x/y
    ll x,y;
    frac():x(0),y(0){ }
    frac(ll _x,ll _y):x(_x),y(_y){ }
    void out(){
        if(y==0) printf("undefined ");
        printf("%f ",(x+0.0)/y);
    }
};
bool operator<(const frac&a,const frac&b){
    return a.x*b.y<a.y*b.x;
}
bool operator==(const frac&a,const frac&b){
    return a.x*b.y==a.y*b.x;
}
