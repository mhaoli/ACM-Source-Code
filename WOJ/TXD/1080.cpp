/*
 * Author:  Xiaodong Tang
 * Created Time:  2015/1/29 20:19:57
 * File Name: 1080.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>
#include <queue>
int main() {
        int _, n; scanf("%d", &_);
        for(; _--; ) scanf("%d", &n), puts(n % 14 ? "flymouse wins the game!" : "snoopy wins the game!");
        return 0;
}
