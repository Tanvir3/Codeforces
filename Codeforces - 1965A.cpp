#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<iterator>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test, sz;
    cin >> test;

    while(test--)
    {
        cin >> sz;
        ll arr[sz+3], mex = 1;

        for(int i=1; i<=sz; i++) cin >> arr[i];
        sort(arr+1, arr+1+sz);

        for(int i=1; i<=sz; i++)
            if(arr[i] == mex) mex++;
        ll mx = arr[sz];

        if(min(mx, mex) % 2 == 1) cout << "Alice\n";
        else cout << "Bob\n";

    }
    return 0;
}
