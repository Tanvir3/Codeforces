#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test, tickets, maxDay, Needed;

    cin >> test;

    while(test--)
    {
        cin >> tickets >> maxDay >> Needed;

        ll arr[tickets + 1], cost = 0, extra = 0;
        for(ll i=0; i<tickets; i++) cin >> arr[i];

        sort(arr, arr + tickets);

        for(ll i=0; i<tickets && Needed >= 1; i++)
        {
            ll available = min(maxDay, Needed);
            cost += (available * (arr[i] + extra));
            extra += available;
            Needed -= available;
        }

        cout << cost << endl;
    }

    return 0;
}
