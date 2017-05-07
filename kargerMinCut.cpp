#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
bool sear(vector <int> & vec, int element)
{
    int upper = vec.size(), lower = 0, mid;
    while(upper >= lower)
    {
        mid = (upper + lower)/2;
        if( vec[mid] == element)
        {
            return true;
        }
        else if(vec[mid] > element)
        {
            upper = mid-1;
        }
        else
        {
            lower = mid+1;
        }
    }
    return false;
}
bool findit(vector <int> & vec, int element)
{
    int j = vec.size(), i;
    for(i = 0; i< j; ++i)
    {
        if(vec[i] == element)
            return true;
    }
    return false;
}
long long int min_cut(vector <pair <vector<int>, vector <int>>> & vec)
{
    vector < pair <vector <int>, vector <int> > > graph = vec;
    vector <int> a, b, c;

    int floor, ceil = graph.size(), ran1, ran2, i, j, k, l;
    bool flag;
    long long int mini = 0;
    while(ceil != 2)
    {
        floor = 0;
        ran1 = floor + ((ceil - floor) * rand()) / (RAND_MAX + 1);
        ran2 = floor + ((ceil - floor) * rand()) / (RAND_MAX + 1);
        //cout << ran1 << " "<< ran2<<"\n";
        flag = false;
        if(ran1 != ran2 )
        {
            l = (graph[ran2].first).size();
            for(j = 0; j< l; ++j)
            {
                if(findit(graph[ran1].second, (graph[ran2].first)[j]) )
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
            {
                //cout <<"works?"<< ceil<<" "<< ran1<<" "<< ran2<<"\n";
                a = graph[ran1].first;
                b = graph[ran2].first;
                for(i = 0; i< b.size(); ++i)
                {
                    a.pb(b[i]);
                }
                graph[ran1].first = a;

                b = graph[ran2].second;
                /*for(i = 0; i< a.size(); ++i)
                {
                    for(j = 0; j< c.size(); ++j)
                    {
                        if(a[i] != c[j])
                        {
                            //(graph[ran1].second).pb(a[i]);
                        }
                    }
                }
                for(i = 0; i< b.size(); ++i)
                {
                    for(j = 0; j< c.size(); ++j)
                    {
                        if(b[i] != c[j])
                        {
                            //(graph[ran1].second).pb(b[i]);
                        }
                    }
                }*/

                for(i = 0; i < b.size(); ++i)
                {
                    (graph[ran1].second).pb(b[i]);
                }

                graph.erase(graph.begin()+ran2);
                --ceil;
            }
        }
    }
    k = (graph[0].first).size();
    //sort((graph[0].first).begin(), (graph[0].first).begin() + k);
    //cout << graph[0].first[0]<< " "<< graph[0].first[1]<<" "<< graph[0].first[2]<<"\n";
    i = (graph[0].second).size();
    for(j = 0; j< i; ++j)
    {
        if( ! findit(graph[0].first, (graph[0].second)[j]))
        {
            ++mini;
        }
    }
    return mini;
}
int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("kargerMinCut.txt");

    //ios::sync_with_stdio(false);infile.tie(0);cout.tie(0);

    string s;
    vector <pair <vector <int>, vector <int>>> graph;
    vector <int> a, b;
    pair <vector <int>, vector <int>> mypair;
    while(getline(infile, s))
    {
        a.clear();
        b.clear();
        stringstream ss(s);
        int z;
        ss >> z;
        a.pb(z);
        while(ss >> z)
        {
            b.pb(z);
        }
        graph.pb( MP( a, b ) );
    }
    long long int cut_min = 100000, t;
    srand(time(NULL));
    for(int j = 0; j < 100000; ++j)
    {
        t = min_cut(graph);
        if(t < cut_min)
        {
            cut_min = t;
        }
        cout << j<<" "<< t<<" "<< cut_min<<"\n";
    }

    cout << cut_min << "\n";
    return 0;
}
