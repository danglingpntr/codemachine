/* Input Format-> The first line contains an integer π. The second line contains an integer π. The third line
specifies an integer π. Finally, the last line contains integers stop1, stop2, . . . , stopπ.

Output Format-> Assuming that the distance between the cities is π miles, a car can travel at most π miles
on a full tank, and there are gas stations at distances stop1, stop2, . . . , stopπ along the way, output the
minimum number of refills needed. Assume that the car starts with a full tank. If it is not possible to
reach the destination, output β1.

Constraints-> 1 β€ π β€ 105. 1 β€ π β€ 400. 1 β€ π β€ 300. 0 < stop1 < stop2 < Β· Β· Β· < stopπ < π. */

#include <bits/stdc++.h>
#include<unistd.h>
using namespace std;

typedef long long int ll;

ll compute_min_refills(ll n, ll tank, vector<ll> stops)
{
    ll numRefil = 0 , currRefil= 0;
    while(currRefil <= n)
    {
        ll lastRefil = currRefil;
        
        while(currRefil <= n && ((stops[currRefil+1]-stops[lastRefil] ) <= tank ))
        {
            currRefil++;
        }

        if(currRefil == lastRefil)
            return -1;

        if(currRefil <= n)
        {
            numRefil++;
        }
        
    }

    return numRefil;
}

int main()
{
    ll d = 0, m = 0, n = 0, i, x;
    cin >> d >> m >> n;
    vector<ll> stops(n+2);
    stops[0]=0;
    for (i = 1; i < n+1; ++i)
    {
        cin>> x;
        stops[i]=x;
    }
    stops[i]=d;

    if (m >= d )
        cout<< 0;
    else
        cout << compute_min_refills(n, m, stops) << "\n";

    return 0;
}