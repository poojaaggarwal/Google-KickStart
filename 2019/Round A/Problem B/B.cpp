#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t;
    cin >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        ll r,c;
        cin >> r >> c;

        vector<string> S(r);
        for(ll i=0;i<r;i++)
            cin >> S[i];

        vector<pair<ll,ll> > v1;
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                if(S[i][j] == '1') v1.push_back(make_pair(i,j));
            }
        }

        ll n = v1.size();
        vector<vector<ll> > matrix(r,vector<ll>(c));
        for(ll k=0;k<n;k++){
            for(ll i=0;i<r;i++){
                for(ll j=0;j<c;j++){
                    if(k == 0) matrix[i][j] = abs(v1[k].first-i) + abs(v1[k].second-j);
                    else matrix[i][j] = min(matrix[i][j],abs(v1[k].first-i) + abs(v1[k].second-j));
                }
            }
        }

        ll mval=-1, maxr, maxc, minr, minc;
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                if(matrix[i][j] == mval){
                    maxr = max(maxr,i);minr = min(minr,i);
                    maxc = max(maxc,j);minc = min(minc,j);
                }
                if(matrix[i][j] > mval){
                    maxr=i;minr=i;
                    maxc=j;minc=j;
                    mval = matrix[i][j];
                }
            }
        }

        ll cr = minr + (maxr-minr)/2;
        ll cc = minc + (maxc-minc)/2;

        ll ans = 0;
        for(ll i=0;i<r;i++)
            for(ll j=0;j<c;j++)
                ans = max(ans,min(matrix[i][j],abs(cr-i) + abs(cc-j)));

        cout << "Case #" << tc << ": " << ans << endl;
    }


}
