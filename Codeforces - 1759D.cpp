#include<iostream>
using namespace std;

#define ll long long

int main()
{
    ll test;
    scanf("%lld", &test);
    while(test--)
    {
        ll n, m;
        scanf("%lld %lld", &n, &m);
        ll temp = n, two = 0, five = 0;

        while(temp % 2 == 0) two++, temp /= 2;
        while(temp % 5 == 0) five++, temp /= 5;

        ll val = 1;
        if(two < five)
        {
            for(int i = 1; i <= (five - two) && (val * 2) <= m; i++)
                val *= 2;
        }
        else
        {
            for(int i = 1; i <= (two - five) && (val * 5) <= m; i++)
                val *= 5;
        }

        while((val * 10) <= m) val *= 10;

        printf("%lld\n", (m / val) * val * n);
    }
}
