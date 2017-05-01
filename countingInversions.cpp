#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
int inversions = 0;
vector <int> merger(vector <int> &vec1, vector <int> &vec2)
{
    vector <int>::iterator vec1beg = vec1.begin(), vec2beg = vec2.begin(), vec1end = vec1.end(), vec2end = vec2.end();
    vector <int> c;
    while(true)
    {
        if(*vec1beg < *vec2beg)
        {
            c.pb(*vec1beg);
            ++vec1beg;
        }
        else
        {
            c.pb(*vec2beg);
            ++vec2beg;
            inversions += vec1end - vec1beg;
        }

        if(vec1beg == vec1end)
        {
            while(vec2beg != vec2end)
            {
                c.pb(*vec2beg);
                ++vec2beg;
            }
            break;
        }
        else if(vec2beg == vec2end)
        {
            while(vec1beg != vec1end)
            {
                c.pb(*vec1beg);
                ++vec1beg;
            }
            break;
        }
    }
    return c;
}
vector <int> mergeSort(vector <int> & x, int beg, int en)
{
    vector <int> a, b, c;
    if(beg == en)
    {
        a.pb(x[beg]);
        return a;
    }
    int len = en-beg, mid;
    mid = (len-1)/2;
    a = mergeSort(x, beg, beg+mid);
    b = mergeSort(x, beg+mid+1, beg+len);
    c = merger(a, b);
    return c;
}
int main()
{
    /*ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("input.txt");*/

    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector <int> myvec, a, b, c;
    int i;
    cout << "Enter a buncha numbers..enter -1 to exit\n";
    while(true)
    {
        cin >> i;
        if(i==-1)
            break;
        myvec.pb(i);
    }

    if(myvec.size()==0)
        return 0;
    cout << "The number of inversions are..\n";
    if(myvec.size() == 1)
    {
        cout << 1<<"\n";
        return 0;
    }
    int len, mid;
    len = myvec.size();

    mid = (len-1)/2;
    a = mergeSort(myvec, 0, mid);
    b = mergeSort(myvec, mid+1, len-1);
    c = merger(a, b);

    cout << inversions<<"\n";
}
