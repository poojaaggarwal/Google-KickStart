#include<bits/stdc++.h>
using namespace std;

int main()
{

    ifstream in("A-large-practice.in");
    ofstream out("A-large-practice.out");

    int t;
    in >> t;

    for(int tc=1;tc<=t;tc++)
    {
        int n;
        in >> n;

        vector<int> v(n);
        for(int i=0;i<n;i++) in >> v[i];

        if(n<=2){
            out << "Case #" << tc << ": YES" << endl;
            continue;
        }

        int maxv = n;
        int minv = 1;

        if(n%2){
            if(v[n/2]==maxv) maxv--;
            else if(v[n/2]==minv) minv++;
            else{
                out << "Case #" << tc << ": NO" << endl;
                continue;
            }
        }

        int l,r;
        if(n%2){
            l = n/2-1;
            r = n/2+1;
        }
        else{
            l = n/2-1;
            r = n/2;
        }

        while(l!=0){

            if(v[l] == maxv) maxv--;
            else if(v[l] == minv) minv++;
            else {
                out << "Case #" << tc << ": NO" << endl;
                break;
            }

            if(v[r] == maxv) maxv--;
            else if(v[r] == minv) minv++;
            else {
                out << "Case #" << tc << ": NO" << endl;
                break;
            }

            l--;
            r++;

        }

        if(l == 0)
        out << "Case #" << tc << ": YES" << endl;

    }

    return 0;
}
