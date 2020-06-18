#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("D-large-practice.in");
    ofstream out("D-large-practice.out");

    vector<int> dp(10001);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=10000;i++){
        dp[i] = i;
        for(int j=1;j<=sqrt(i);j++)
            dp[i] = min(dp[i],1+dp[i-j*j]);
    }
    int t;
    in >> t;

    for(int tc=1;tc<=t;tc++)
    {
        cout << tc << endl;

        int n;
        in >> n;

        out << "Case #" << tc << ": " << dp[n] << endl;

    }


    return 0;
}
