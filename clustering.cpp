#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

pair <int, pair <int, int>> mypair;
vector <pair <int, pair <int, int> > > edgy;
vector < pair <int, int> > union_set;
vector < vector <int> > vertices_conn;
vector <int> temp;


void BFS(int small, int big)
{
    union_set[big].se += union_set[small].se;

    for(int j = 0; j< signed(vertices_conn[small].size()); ++j)
    {
        union_set[vertices_conn[small][j]].fi = big;
        vertices_conn[big].pb(vertices_conn[small][j]);
    }
}
int find_leader(int a)
{
    return union_set[a].fi;
}
void union_pls(int x, int y)
{
    int l1 = find_leader(x), l2 = find_leader(y);
    if( union_set[l1].se < union_set[l2].se )
    {
        BFS(l1, l2);
    }
    else
    {
        BFS(l2, l1);
    }
}
int main()
{
    ofstream outfile;
    outfile.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    bool boolean;
    int vertices, u, v, cost, i, c = 0, bits, j;
    vector <vector <bool> > node;
    vector <bool> temp1(24, false);
    infile >> vertices;
    for(i = 0; i<= vertices; ++i)
    {
        union_set.pb( MP (i, 1));
        vertices_conn.pb(temp);
        vertices_conn[i].pb(i);
    }

    
    while(infile >> u >> v >> cost)
    {
            edgy.pb ( MP (cost , MP ( u, v ) ) );
    }
    sort(edgy.begin(), edgy.end());

    for(i = 0; i< edgy.size(); ++i)
    {
        if(c == vertices - 4)
            break;

        mypair = edgy[i];
        if(find_leader(mypair.se.fi) != find_leader(mypair.se.se))
        {
            union_pls(mypair.se.fi, mypair.se.se);
            c++;
        }
    }
    for(; i< edgy.size(); ++i)
    {
        mypair = edgy[i];
        if(find_leader(mypair.se.fi) != find_leader(mypair.se.se))
        {
            cout << mypair.fi<<"\n";
            break;
        }
    }

}
s