#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

const int t = 875714;
vector < vector <int> > myvec, myvec_rev;
vector <int> temp, SCC_sizes;
bool visited[t];
int timeO[t], g_time , sizeu;

void DFS_2(int x)
{
    int j;
    ++sizeu;
    visited[x] = true;
    for(j = 0; j< myvec[x].size(); ++j)
    {
        if( ! visited[myvec[x][j]] )
        {
            DFS_2(myvec[x][j]);
        }
    }
}
void DFS_1(int x)
{
    visited[x] = true;
    int j;
    cout << x<<" "<< g_time<<"\n";
    for(j = 0; j< myvec_rev[x].size() ; ++j)
    {
        if( !visited[myvec_rev[x][j]] )
        {
            DFS_1(myvec_rev[x][j]);
        }
    }
    timeO[g_time] = x;
    ++g_time;
}
int main()
{
    ofstream outfile;
    outfile.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int i, j;
    for(i = 0; i< t; ++i)
    {
        myvec.push_back(temp);
        myvec_rev.pb(temp);
        visited[i] = false;
    }
    while(infile >> i>> j)
    {
        --i;--j;
        myvec[i].pb(j);
        myvec_rev[j].pb(i);
    }
    g_time = 0;

    for(i = t-1; i>=0; --i)
    {
        if( !visited[i] )
        {
            DFS_1(i);
        }
    }
    /*for(i = t-1; i>= 0; --i)
    {
        cout << i<<" "<<timeO[i]+1<<"\n";
    }*/



    for(i = 0; i< t; ++i)
    {
        visited[i] = false;
    }

    for(i = t-1; i>= 0; --i)
    {
        if( ! visited[timeO[i]] )
        {
            sizeu = 0;
            DFS_2( timeO[i]);
            SCC_sizes.pb(sizeu);
            cout << "leader = "<< timeO[i]+1 <<"\n";
        }
    }
    sort(SCC_sizes.begin(), SCC_sizes.end());
    for(i = 0; i< SCC_sizes.size(); ++i)
    {
        cout << SCC_sizes[i]<<" ";
    }
}
