#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll mod = 1e9 + 7;

ll mul(ll a, ll b)
{
    ll res = 0;
    a = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % mod;

        a = (a * 2) % mod;

        b /= 2;
    }
    return res % mod;
}

ll gcdExtended(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, x1, y1);

    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}

ll modInverse(ll b)
{
    ll x, y;
    ll g = gcdExtended(b, mod, x, y);
    return (x%mod + mod) % mod;
}

void compute(vector<ll> &C, ll m)
{
    C[0] = 1;
    for(ll i=1;i<=m;i++) C[i] = mul(mul(C[i-1],m-i+1),modInverse(i));
}

int main()
{

    ifstream in("C-large.in");
    ofstream out("C-large.out");

    vector<ll> F(200001);
    F[0] = 1;
    for(ll i=1;i<200001;i++) F[i] = (i*F[i-1])%mod;

    vector<ll> P2(200001);
    P2[0] = 1;
    for(ll i=1;i<200001;i++) P2[i] = (P2[i-1]*2)%mod;


    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++){

        cout << tc  << endl;

        ll n,m;
        in >> n >> m;

        vector<ll> C(m+1);
        compute(C,m);

        ll ans = 0;
        for(ll i=1;i<=m;i++){
           ll temp = mul(mul(C[i],F[2*n-i]),P2[i]);
           if(i%2) ans = (ans + temp)%mod;
           else ans = (ans + mod - temp)%mod;
        }
        ans = (F[2*n] + mod - ans)%mod;
        out << "Case #" << tc << ": " << ans << endl;

    }



    return 0;
}
