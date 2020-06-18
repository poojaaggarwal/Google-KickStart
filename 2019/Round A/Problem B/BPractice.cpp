#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > dp;
int n,m;

bool valid(int d){

        int maxxplusy = INT_MIN;
        int minxplusy = INT_MAX;
        int maxxminusy = INT_MIN;
        int minxminusy = INT_MAX;

        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j] > d){
                        maxxplusy =  max(i+j,maxxplusy);
                        maxxminusy = max(i-j,maxxminusy);
                        minxplusy =  min(i+j,minxplusy);
                        minxminusy = min(i-j,minxminusy);
                        flag = true;
                }
            }
        }

        if(!flag) return true;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int d1 = max(abs(maxxminusy - (i-j)), abs(minxminusy - (i-j)) );
                int d2 = max(abs(maxxplusy - (i+j)), abs(minxplusy - (i+j)) );
                int d3 = max(d1,d2);

                if(d3 <= d) return true;

            }
        }
        return false;
}

int main()
{
    int t;
    cin >> t;

    for(int tc=1;tc<=t;tc++){

        cin >> n >> m;

        dp.clear();
        dp.resize(n, vector<int>(m,-1));

        queue<pair<int,int> > q;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(int j=0;j<m;j++){
                if(s[j] == '1'){
                    dp[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();

            if(p.first > 0){
                if(dp[p.first-1][p.second] == -1 || dp[p.first-1][p.second] > dp[p.first][p.second] + 1){
                    dp[p.first-1][p.second] = dp[p.first][p.second] + 1;
                    q.push(make_pair(p.first-1,p.second));
                }
            }

            if(p.first < n-1){
                if(dp[p.first+1][p.second] == -1 || dp[p.first+1][p.second] > dp[p.first][p.second] + 1){
                    dp[p.first+1][p.second] = dp[p.first][p.second] + 1;
                    q.push(make_pair(p.first+1,p.second));
                }
            }

            if(p.second > 0){
                if(dp[p.first][p.second-1] == -1 || dp[p.first][p.second-1] > dp[p.first][p.second] + 1){
                    dp[p.first][p.second-1] = dp[p.first][p.second] + 1;
                    q.push(make_pair(p.first,p.second-1));
                }
            }

            if(p.second < m-1){
                if(dp[p.first][p.second+1] == -1 || dp[p.first][p.second+1] > dp[p.first][p.second] + 1){
                    dp[p.first][p.second+1] = dp[p.first][p.second] + 1;
                    q.push(make_pair(p.first,p.second+1));
                }
            }
        }

        int l = 0;
        int h = m+n-1;

        while(l < h)
        {
            int m = (l+h)/2;
            if(valid(m)) h = m;
            else l = m+1;
        }

        cout << "Case #" << tc << ": " << l << endl;

    }

    return 0;
}
