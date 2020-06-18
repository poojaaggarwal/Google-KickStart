#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t;
    cin >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        ll n,p;
        cin >> n >> p;

        vector<ll> v(n);
        for(int i=0;i<n;i++)
            cin >> v[i];

        sort(v.begin(),v.end());

        vector<ll> dp(n,0);
        dp[0] = v[0];
        for(ll i=1;i<n;i++)
            dp[i] = v[i] + dp[i-1];

        ll ans = (v[p-1]*p) - dp[p-1];
        for(ll i=p;i<n;i++)
            ans = min(ans,(v[i]*p) - (dp[i] - dp[i-p]));

        cout << "Case #" << tc << ": " << ans << endl;

    }

    return 0;
}
