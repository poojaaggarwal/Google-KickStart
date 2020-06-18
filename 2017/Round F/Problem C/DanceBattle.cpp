#include<bits/stdc++.h>
using namespace std;

int main()
{

    ifstream in("B-large-practice.in");
    ofstream out("B-large-practice.out");

    int t;
    in >> t;

    for(int tc=1;tc<=t;tc++)
    {
        cout << tc << endl;

        int E,n;
        in >> E >> n;

        vector<int> v(n);
        for(int i=0;i<n;i++) in >> v[i];

        sort(v.begin(),v.end());

        if(n == 0 || v[0] >= E){
            out << "Case #" << tc << ": 0" << endl;
            continue;
        }

        int h = 0;
        int i = 0;
        int j = n-1;

        while(i <= j && v[i] < E){
            E -= v[i];
            i++;
            h++;
        }

        while(i<j){
            E += v[j];
            j--;
            h--;
            while(i<=j && v[i] < E){
                E -= v[i];
                i++;
                h++;
            }
        }

        out << "Case #" << tc << ": " << h << endl;

    }


    return 0;
}
