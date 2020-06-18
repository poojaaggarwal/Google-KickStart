#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll T;
    cin >> T;

    for(ll tc=1;tc<=T;tc++){

        ll N,O,D;
        cin >> N >> O >> D;

        ll X1, X2, A, B, C, M, L;
        cin >> X1 >> X2 >> A >> B >> C >> M >> L;

        vector<ll> S(N+1);
        S[0] = 0,S[1] = X1,S[2] = X2;
        for(ll i=3;i<=N;i++) S[i] = (A *  S[i-1] + B * S[i-2] + C) % M;
        for(ll i=1;i<=N;i++) S[i] = S[i] + L;

        vector<ll> Cum_S(N+1);
        Cum_S[0] = 0;
        for(ll i=1;i<=N;i++) Cum_S[i] = Cum_S[i-1] + S[i];

        multiset<ll> mset;
        ll odd_candies = 0;
        ll j = N;
        ll ans = LONG_MIN;
        for(ll i=N;i>0;i--){

          if(S[i]%2) odd_candies++;

          mset.insert(Cum_S[i]);

          while(odd_candies > O){
            mset.erase(Cum_S[j]);
            if(S[j]%2) odd_candies--;
            j--;
          }

          multiset<ll>::iterator it = mset.upper_bound(D+Cum_S[i-1]);
          if(it != mset.begin()) {
                it--;
                ans = max(ans,*it-Cum_S[i-1]);
          }

        }

        if(ans == LONG_MIN) cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
        else cout << "Case #" << tc << ": " << ans << endl;

    }


    return 0;
}
