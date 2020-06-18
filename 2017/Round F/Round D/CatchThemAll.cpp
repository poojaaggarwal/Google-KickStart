#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("C-large-practice.in");
    ofstream out("C-large-practice.out");

    int t;
    in >> t;

    for(int tc=1;tc<=t;tc++)
    {
        cout << tc << endl;

        int n,m,p;
        in >> n >> m >> p;

        vector<vector<int> > path(n,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++)
        {
            int u,v,d;
            in >> u >> v >> d;
            path[u-1][v-1] = path[v-1][u-1] = d;
        }

        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(path[i][k] != INT_MAX && path[k][j] != INT_MAX)
                        path[i][j] = min(path[i][j],path[i][k]+path[k][j]);

        vector<vector<double> > dp(2,vector<double>(n,0));
        for(int k=1;k<=p;k++){
            for(int i=0;i<n;i++){
                dp[k%2][i] = 0;
                for(int j=0;j<n;j++) if(i != j) dp[k%2][i] += (path[i][j]  + dp[1-k%2][j]) / (n-1) ;
            }
        }

        out << "Case #" << tc << ": " << fixed << setprecision(6) << dp[p%2][0] << endl;

    }

    return 0;
}

