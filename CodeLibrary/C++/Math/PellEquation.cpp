bool pell( int D, int& x, int& y ) {
    int sqrtD = sqrt(D + 0.0);
    if( sqrtD * sqrtD == D ) return false;
    int c = sqrtD, q = D - c * c, a = (c + sqrtD) / q;
    int step = 0;
    int X[] = { 1, sqrtD };
    int Y[] = { 0, 1 };
    while( true ) {
        X[step] = a * X[step^1] + X[step];
        Y[step] = a * Y[step^1] + Y[step];
        c = a * q - c;
        q = (D - c * c) / q;
        a = (c + sqrtD) / q;
        step ^= 1;
        if( c == sqrtD && q == 1 && step ) {
            x = X[0], y = Y[0];
            return true;
        }
    }
}
