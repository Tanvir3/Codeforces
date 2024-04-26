#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

int main()
{
    ll arr[4];

    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr+3);

    if((arr[0] + arr[1]) % 2 == 0) cout << arr[1] << endl;
    else cout << arr[2] << endl;

    return 0;
}
