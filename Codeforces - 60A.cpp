#include<iostream>
#include<queue>
#include<iterator>
using namespace std;

#define ll long long

int main()
{
    ll boxes, hints, boxName;

    cin >> boxes >> hints;

    ll left = 1, right = boxes;

    while(hints--)
    {
        string a, b, side, d;
        cin >> a >> b >> side >> d >> boxName;

        if(side == "left") right = min(right, boxName - 1);
        if(side == "right") left = max(left, boxName + 1);
    }

    if(right - left < 0) printf("-1\n");
    else printf("%lld\n", right - left + 1);
    return 0;
}
