#include<bits/stdc++.h>
using namespace std;

int main()
{

    ifstream in("B-small-attempt0.in");
    ofstream out("B-small-attempt0.out");

    int t;
    in >> t;

    for(int tc=1;tc<=t;tc++)
    {
        int v,e;
        in >> v >> e;

        vector<vector<int> > path(v,vector<int>(v,-1));
        for(int i=0;i<e;i++){
            int v1,v2,c;
            in >> v1 >> v2 >> c;
            path[v1-1][v2-1] = path[v2-1][v1-1] = c;
        }

        for(int k=0;k<v;k++){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    if(path[i][k] == -1 || path[k][j] == -1) continue;

                    if(path[i][j] == -1) path[i][j] = path[i][k] + path[k][j];
                    else  path[i][j] = min(path[i][j],path[i][k] + path[k][j]);
                }
            }
        }

        int times = pow(2,v);
        int mpath = -1;
        int cpath = 0;
        for(int i=0;i<times;i++){

            int ans = 0;
            int tcost;
            for(int j=0;j<v;j++){

                int tfj = (i>>j)&1;
                tcost = -1;

                for(int k=0;k<v;k++){
                    if( path[j][k] != -1 && ((i>>k)&1) != tfj)
                    {
                        if(tcost == -1)
                            tcost = path[j][k];
                        else
                            tcost = min(path[j][k],tcost);
                    }
                }

                if(tcost == -1) break;
                ans += tcost;
            }

            if(tcost != -1) {
                if(mpath == -1 || ans < mpath){
                    mpath = ans;
                    cpath = 1;
                }
                else if(ans == mpath) cpath++;
            }

        }

        out << "Case #" << tc << ": " << cpath << endl;

    }

    return 0;
}
