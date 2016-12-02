#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <ctime>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int x1, x2, x3, y1, y2, y3;
    while (scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3), x1 || x2 || x3 || y1 || y2 || y3) {
        double ans = abs((x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1)) / 2.0 + 1;
        ans -= gcd(abs(x1-x2), abs(y1-y2)) / 2.0;
        ans -= gcd(abs(x1-x3), abs(y1-y3)) / 2.0;
        ans -= gcd(abs(x3-x2), abs(y3-y2)) / 2.0;
        printf("%d\n", (int)(ans));
    }
    return 0;
}

