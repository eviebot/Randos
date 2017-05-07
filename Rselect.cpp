#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

int partition_(vector <int> & vec, int fi, int se, int p)
{
    int temp, i, j;
    if(p != fi)
    {
        temp = vec[fi];
        vec[fi] = vec[p];
        vec[p] = temp;
        p = fi;
    }

    j = fi+1;i = j;
    for(; j < se; ++j)
    {
        if( vec[j] < vec[p] )
        {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            ++i;
        }
    }
    temp = vec[i-1];
    vec[i-1] = vec[p];
    vec[p] = temp;
    return i-1;
}
int Rselect(vector <int> & vec, int start, int en, int i)
{
    //cout << start<<" "<< en<<' '<< i<<'\n';

    if(en - start == 1)
    {
        return vec[start];
    }
    int pivot = start + ((en - start) * rand()) / (RAND_MAX + 1), j;
    pivot = partition_(vec, start, en, pivot);
    //cout << pivot<<" "<< ' '<<'\n';
    //getchar();
    j = pivot - start + 1;
    if(j == i)
    {
        return vec[pivot];
    }
    else if(j > i)
    {
        Rselect(vec, start, pivot, i);
    }
    else
    {
        Rselect(vec, pivot+1, en, i-j);
    }

}
int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("kargerMinCut.txt");

    //ios::sync_with_stdio(false);infile.tie(0);cout.tie(0);

    vector <int> stor;
    int i, var;
    for(i = 0; i< 10 ; ++i)
    {
        cin >> var;
        stor.pb(var);
    }

    cout << "Enter the ordered statistic you want to find (between 1 and number of elements n): ";
    cin >> i;
    srand(time(NULL));
    cout << "The element is "<< Rselect(stor, 0, stor.size(), i);
    return 0;

}
