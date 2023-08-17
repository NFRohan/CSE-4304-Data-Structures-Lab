#include <iostream>
#include <math.h>
using namespace std;
// optimization using the concept of finding the minima of a function
int minCost(int N, int A, int B, int &x, int &y)
{
    double d = static_cast<double>(B * N) / (A + B);
    x = round(d);
    y = N - x;
    int cost = A * x * x + B * y * y;
    return cost;
}

int main()
{
    int a, b, x, y, n, caseCount;

    cin >> caseCount;

    while (caseCount != 0)
    {
        cin >> n >> a >> b;
        cout << minCost(n, a, b, x, y) << " " << x << " " << y << endl;
        caseCount--;
    }

    return 0;
}