#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll minv[41][41][41][41];
ll dp[41][41][41][41];

ll fn(ll r1, ll c1, ll r2, ll c2)
{
    if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];

    if(r1 == r2 && c1 == c2) return (dp[r1][c1][r2][c2] = 0);

    ll ret = 0;
    for(ll c=c1;c<c2;c++)
        ret = max(ret,fn(r1,c1,r2,c) + fn(r1,c+1,r2,c2));
    for(ll r=r1;r<r2;r++)
        ret = max(ret,fn(r1,c1,r,c2) + fn(r+1,c1,r2,c2));

    return (dp[r1][c1][r2][c2] = ret + minv[r1][c1][r2][c2]);
}

int main()
{

    ifstream in("C-large-practice.in");
    ofstream out("C-large-practice.out");

    ll t;
    in >> t;

    for(ll tc=1;tc<=t;tc++)
    {
        ll n,m;
        in >> n >> m;

        vector<vector<ll> > v(n,vector<ll>(m));
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++)
                in >> v[i][j];


        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                minv[i][j][i][j] = v[i][j];
                for(ll l=j+1;l<m;l++){
                    minv[i][j][i][l] = min(minv[i][j][i][l-1],v[i][l]);
                    dp[i][j][i][l] = -1;
                }
                for(ll k=i+1;k<n;k++){
                    minv[i][j][k][j] = min(minv[i][j][k-1][j],v[k][j]);
                    dp[i][j][k][j] = -1;
                }
                for(ll k=i+1;k<n;k++){
                    for(ll l=j+1;l<m;l++){
                        minv[i][j][k][l] = min(min(minv[i][j][k][l-1],minv[i][j][k-1][l]),v[k][l]);
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        out << "Case #" << tc << ": " << fn(0,0,n-1,m-1) << endl;


    }


    return 0;
}
