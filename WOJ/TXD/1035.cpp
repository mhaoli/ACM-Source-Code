/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/2/17 22:46:25
 * File Name: 1035.cpp
 */
#include <iostream>
using namespace std;
int solve(int n) {
        if(n % 2 == 0) return n / 2;
        return (n + 1) / 2;
}
int main() {
        int n;
        while(std::cin>>n && n) std::cout<<solve(n)<<std::endl;
        return 0;
}
