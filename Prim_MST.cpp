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

    int vertices, edges, i, j, v1, v2, cost, recent;
    long long int sum = 0;
    infile >> vertices >> edges;

    vector < vector <pair <int, int> > > graph;
    vector <pair <int, int> > temp;
    set < pair <int, int> > myset;
    set < pair <int, int> >::iterator it;
    bool visited[vertices+1];
    int updated_cost[vertices+1];
    for(i = 0; i<= vertices; ++i)
    {
        graph.pb(temp);
        visited[i] = false;
    }

    for(i = 0; i< edges; ++i)
    {
        infile >> v1 >> v2 >> cost;

        graph[v1].pb( MP (v2, cost));
        graph[v2].pb( MP (v1, cost));
    }

    recent = 1;
    visited[1] = true;
    updated_cost[1] = 0;
    for(i = 2; i<= 500; ++i)
    {
        myset.insert( MP ( 10000, i));
        updated_cost[i] = 10000;
    }

    for(i = 2; i<= 500; ++i)
    {
        for( j = 0; j< graph[recent].size(); ++j)
        {
            if( !visited[graph[recent][j].first] )
            {
                it = myset.find( MP (updated_cost[graph[recent][j].fi] , graph[recent][j].fi) );
                if( graph[recent][j].se < it->first)
                {
                    myset.erase(it);
                    myset.insert( MP (graph[recent][j].se, graph[recent][j].fi));
                    updated_cost[graph[recent][j].fi] = graph[recent][j].se;
                }
            }
        }
        it = myset.begin();
        sum += it->first;
        recent = it->second;
        myset.erase(it);
        visited[recent] = true;
    }
    cout <<sum;
}
