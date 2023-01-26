#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findP(double x, long long n)
    {

        if (n == 0)
        {
            return 1;
        }

        if (n == 1)
        {
            return x;
        }

        // recursive step

        // double answer = x * findP(x, n-1);

        double answer = findP(x, n / 2);
        answer = answer * answer; // power became n here

        if (n % 2 == 1)
        {
            answer = answer * x;
        }

        return answer;
    }
    double myPow(double x, int n)
    {

        if (n >= 0)
            return findP(x, n);

        return (double)1 / findP(x, abs(n));
    }
};

int main()
{
}