#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<iterator>
using namespace std;

#define ll long long

ll fx[5] = {0,0,-1,1};
ll fy[5] = {-1,1,0,0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test,sz;

    cin >> test;
    while(test--)
    {
        cin >> sz;
        ll arr[sz];
        ll answer[sz+1];

        for(ll i=0; i<sz-1; i++) cin >> arr[i];

        answer[sz-1] = 2500000;

        for(ll i=sz-2; i>=0; i--) answer[i] = answer[i+1] - arr[i];

        for(int i=0; i<sz; i++) cout << answer[i] << " ";
        cout << endl;
    }

    return 0;
}
