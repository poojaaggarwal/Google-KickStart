#include<bits/stdc++.h>
using namespace std;

int main()
{

    ifstream in("A-large.in");
    ofstream out("A-large.out");

    int t;
    in >> t;

    for(int tc=1;tc<=t;tc++)
    {

        int l;
        in >> l;

        string a,b;
        in >> a >> b;

        set<vector<int> > s;
        for(int i=0;i<l;i++)
        {
            vector<int> dp(26,0);
            for(int j=i;j<l;j++)
            {
                dp[b[j]-'A']++;
                s.insert(dp);
            }

        }

        int ans = 0;
        for(int i=0;i<l;i++)
        {
            vector<int> dp(26,0);
            for(int j=i;j<l;j++)
            {
                dp[a[j]-'A']++;
                if(s.find(dp) != s.end()) ans++;
            }

        }

        out << "Case #" << tc << ": " << ans << endl;

    }


    return 0;
}
