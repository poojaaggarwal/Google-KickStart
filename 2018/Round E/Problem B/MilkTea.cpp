#include<bits/stdc++.h>
using namespace std;

int main()
{

    ifstream in("B-large-practice.in");
    ofstream out("B-large-practice.out");

    int t;
    in >> t;

    for(int tc=1;tc<=t;tc++){

        int n,m,p;
        in >> n >> m >> p;

        vector<string> v(n);
        for(int i=0;i<n;i++) in >> v[i];

        set<string> s;
        for(int i=0;i<m;i++){
            string x;
            in >> x;
            s.insert(x);
        }

        priority_queue<pair<int,string> > pq1,pq2;
        pq1.push(make_pair(0,""));

        for(int i=0;i<p;i++){

            int z = 0, o = 0;
            for(int j=0;j<n;j++){
                if(v[j][i] == '0') z++;
                else  o++;
            }

            if(i%2){

                while(!pq2.empty()){

                    pair<int,string> x = pq2.top();
                    pq2.pop();

                    pq1.push(make_pair(x.first + o,x.second + '0'));
                    pq1.push(make_pair(x.first + z,x.second + '1'));

                    while(pq1.size() > m + 1) pq1.pop();
                }


            }
            else{

                while(!pq1.empty()){

                    pair<int,string> x = pq1.top();
                    pq1.pop();

                    pq2.push(make_pair(x.first + o,x.second + '0'));
                    pq2.push(make_pair(x.first + z,x.second + '1'));

                    while(pq2.size() > m + 1) pq2.pop();
                }
            }
        }

        int ans = 0;
        if(p%2){

           while(!pq2.empty()){

                pair<int,string> x = pq2.top();
                pq2.pop();

                if(s.find(x.second) == s.end()) ans = x.first;

           }

        }
        else{

           while(!pq1.empty()){

                pair<int,string> x = pq1.top();
                pq1.pop();

                if(s.find(x.second) == s.end()) ans = x.first;

           }

        }

        out << "Case #" << tc << ": " << ans << endl;
    }


    return 0;
}
