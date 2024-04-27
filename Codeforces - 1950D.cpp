#include<iostream>
#include<set>
#include<iterator>
using namespace std;

#define ll long long

bool check(ll number)
{
    while(number != 0)
    {
        if(number % 10 == 0 || number % 10 == 1) number /= 10;
        else
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test, number;

    cin >> test;

    while(test--)
    {
        cin >> number;

        if(check(number)) cout << "YES" << endl;
        else
        {
            ll two = 0, five = 0;

            while(number % 2 == 0) number /= 2, two++;
            while(number % 5 == 0) number /= 5, five++;

            for(ll i=11; i*i <= number; i+=2)
            {
                if(number % i == 0 && check(i))
                {
                    while(number % i == 0) number /= i;
                }
            }

            if(check(number) && five == two) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
