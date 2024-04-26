#include<iostream>
#include<cmath>
#include<queue>
#include<iterator>
using namespace std;

#define ll long long

int main()
{
    ll A, B, n;

    cin >> A >> B >> n;

    if(A == 0 && B == 0) printf("5\n");
    else if(A == 0 && B != 0) printf("No solution\n");
    else if(A != 0 && B == 0) printf("0\n");
    else
    {
        ll div = B / A, negative = 1;
        double X;

        if(div < 0) div *= (-1), negative = -1;

        if(B % A == 0)
        {
            for(int i = 1; ; i++)
            {
                ll sum = 1, temp = n;
                while(temp--) sum *= i;

                if(sum >= div)
                {
                    if(sum == div) printf("%d\n", i*negative);
                    else printf("No solution\n");
                    break;
                }
            }
        }
        else printf("No solution\n");
    }

    return 0;
}
