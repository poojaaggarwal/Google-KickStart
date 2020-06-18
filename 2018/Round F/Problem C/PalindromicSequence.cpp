#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ifstream in("C-small-attempt0.in");
    ofstream out("C-small-attempt0.out");

    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        cout << tc << endl;

        ll l,n,k;
        in >> l >> n >> k;


        vector<ll> dp(n+1,1);
        ll tp = 0;
        for(ll i=1;i<=n;i++){
            if(i%2){
                dp[i] = dp[i-1]*l;
            }
            else{
                dp[i] = dp[i-1];
            }
            tp += dp[i];
        }

        if(k > tp){
            out << "Case #" << tc << ": 0" << endl;
            continue;
        }

        tp = tp/l;
        k = k%tp;

        ll ans = 0;

        if(k == 0) k = tp;

        while(k > 0){
            for(int i=1;i<=n;i++){
                if(dp[i] > 0){
                    dp[i]--;
                    k--;
                    if(k == 0){
                      ans = i;
                      break;
                    }
                }
            }
        }

        out << "Case #" << tc << ": " << ans << endl;
    }


    return 0;
}
