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

    int i, j, a, recent = 1;
    bool visited[201] = {false};
    visited[0] = true;
    visited[1] = true;
    vector <pair <int, int> > temp;
    vector < vector <pair <int, int> > > myvec;
    pair <int, int> mypair, mypair1;
    vector <int> short_dist (201, 1000000);
    set <pair <int, int> > myset;
    set <pair <int, int> >::iterator it;
    string s;
    short_dist[1] = 0;


    while(infile >> s)
    {
        if(s.length() <= 3 && s != "9,2")
        {
            myvec.pb(temp);
            temp.clear();
            continue;
        }
        a=0;
        for(i = 0; i< s.length(); ++i)
        {
            if(s[i] == ',')
            {
                mypair.fi = a;
                a=0;
                continue;
            }
            a *= 10;
            a += (s[i]-'0');
        }
        mypair.se = a;
        temp.pb(mypair);
    }
    myvec.pb(temp);temp.clear();

    /*for(i = 1; i<= 200 ; ++i)
    {
        cout << i<<"\n";
        for(j = 0; j< myvec[i].size(); ++j)
        {
            cout << (myvec[i][j]).first <<" "<< (myvec[i][j]).second<<" ";
        }
        cout <<"YAHOO\n";
    }
    getchar();*/

    for (i = 2; i<= 200; ++i)
    {
        myset.insert( MP (1000000, i));
    }

    for(i = 1; i < 200; ++i)
    {
        for(j = 0; j< myvec[recent].size(); ++j)
        {
            mypair = myvec[recent][j];
            if( !visited[mypair.first] )
            {
                it = myset.find( MP (short_dist[mypair.first] , mypair.first ) );
                if(it == myset.end())
                {
                    cout << "HALLELUJAH YOUR ALGORITHM IS CRAP\n";
                    getchar();
                }
                if(short_dist[recent] + mypair.second < it->first)
                {
                    myset.erase(it);
                    myset.insert( MP(short_dist[recent] + mypair.second , mypair.first ) );
                    short_dist[mypair.first] = short_dist[recent] + mypair.second;
                }
            }
        }
        for(it = myset.begin(); it != myset.end(); ++it)
        {
            //cout << it->first <<" "<< it->second <<"\n";
        }

        it = myset.begin();
        short_dist[it->second] = it->first;
        recent = it->second;
        myset.erase(it);
        visited[recent] = true;
        cout << "adding .."<< recent<<"\n";
    }
    for(i = 0 ; i<= 200; ++i)
    {
        cout << i<<" "<< short_dist[i]<<"\n";
    }

    return 0;
}
