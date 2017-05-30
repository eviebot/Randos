#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

int main()
{
    ofstream outfile;
    outfile.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    long long int t, i, j, r, sum = 0, num;
    vector <long long int> A;
    vector <vector <long long int > > HT;
    vector <long long int> temp;
    for(i = 0; i< 1000000; ++i)
        HT.pb(temp);

    for(i = 0; i< 1000000; ++i)
    {
        infile >> t;
        A.pb(t);
        j = abs(t)%1000000;
        HT[j].pb(t);
    }

    for( r = -10000; r <= 10000; ++r)
    {
        cout << r <<" "<< sum <<"\n";
        bool flag = true;
        for( i = 0; i< 1000000 && flag; ++i)
        {
            num = r - A[i];
            if(num == A[i])
                continue;
            temp = HT[ abs(num)%1000000];
            for(j = 0; j< temp.size(); ++j)
            {
                if(temp[j] == num)
                {
                    flag = false;
                    ++sum;
                    break;
                }
            }
        }
    }
    cout << sum<<"\n";
}
