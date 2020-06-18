#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ifstream in("B-large.in");
    ofstream out("B-large.out");

    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        cout << tc << endl;

        ll n;
        in >> n;

        string s;
        in >> s;

        vector<ll> v(n);
        v[0] = s[0] - '0';
        for(int i=1;i<n;i++) v[i] = (s[i]-'0') + v[i-1];

        ll m;
        if(n%2) m = n/2 + 1;
        else m = n/2;

        ll  ans = v[m-1];
        for(int i=m;i<n;i++) ans = max(ans,v[i]-v[i-m]);

        out << "Case #" << tc << ": " << ans << endl;
    }


}
