#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

void insert_it(vector <int> & x, bool a, int index)
{
    int parent = index/2 - !(index%2), temp;
    if(index == 0)
        return;
    if(a)
    {
        if( x[index] > x[parent])
        {
            temp = x[index];
            x[index] = x[parent];
            x[parent] = temp;
            insert_it(x, a, parent);
        }
    }
    else
    {
        if( x[index] < x[parent])
        {
            temp = x[index];
            x[index] = x[parent];
            x[parent] = temp;
            insert_it(x, a, parent);
        }
    }
}
void bubble_down(vector <int> & x, bool a, int index)
{
    int j = x.size(), left= 2*index+1, right= 2*index+2, temp;
    if(left >= j)
    {
        return;
    }
    if(a)
    {
        if(right >= j)
        {
            if( x[index] < x[left])
            {
                temp = x[left];
                x[left] = x[index];
                x[index] = temp;
            }
            return;
        }
        else
        {
            if(x[index] < x[left] || x[index] < x[right])
            {
                if(x[left] > x[right])
                {
                    temp = x[left];
                    x[left] = x[index];
                    x[index] = temp;
                    bubble_down(x, a, left);
                }
                else
                {
                    temp = x[right];
                    x[right] = x[index];
                    x[index] = temp;
                    bubble_down(x, a, right);
                }
            }
        }
    }
    else
    {
        if(right >= j)
        {
            if( x[index] > x[left])
            {
                temp = x[left];
                x[left] = x[index];
                x[index] = temp;
            }
            return;
        }
        else
        {
            if(x[index] > x[left] || x[index] > x[right])
            {
                if(x[left] < x[right])
                {
                    temp = x[left];
                    x[left] = x[index];
                    x[index] = temp;
                    bubble_down(x, a, left);
                }
                else
                {
                    temp = x[right];
                    x[right] = x[index];
                    x[index] = temp;
                    bubble_down(x, a, right);
                }
            }
        }
    }
}
int extract(vector <int> &x, bool a)                // 1 is extract max , 0 is extract min
{
    vector <int>::iterator it = x.end();--it;
    int temp;
    temp = x[0];
    x[0] = *it;
    x.erase(it);

    bubble_down(x, a, 0);
    return temp;
}

int main()
{
    ofstream outfile;
    outfile.open("output.txt");
    ifstream infile;
    infile.open("input.txt");

    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector <int> small, large;
    int i, n, temp, result = 6331+2793;
    infile >> n >> temp;

    if(n > temp)
    {
        large.pb(n);
        small.pb(temp);
    }
    else
    {
        large.pb(temp);
        small.pb(n);
    }
    for(i = 1; i<= 9998; ++i)
    {
        infile >> n;
        if(n >= small[0] && n <= large[0])
        {
            if(small.size() > large.size())
            {
                large.pb(n);
                insert_it(large, 0, large.size()-1);
            }
            else
            {
                small.pb(n);
                insert_it(small, 1, small.size()-1);
            }
        }
        else if( n < small[0])
        {
            if( small.size() > large.size())
            {
                temp = extract(small, 1);
                small.pb(n);
                large.pb(temp);
                insert_it(small, 1,  small.size()-1);
                insert_it(large, 0, large.size()-1);
            }
            else
            {
                small.pb(n);
                insert_it(small, 1, small.size()-1);
            }
        }
        else
        {
            if(large.size() > small.size())
            {
                temp = extract(large, 0);
                large.pb(n);
                small.pb(temp);
                insert_it(large, 0, large.size()-1);
                insert_it(small, 1, small.size()-1);
            }
            else
            {
                large.pb(n);
                insert_it(large, 0, large.size()-1);
            }
        }
        /*for(int t = 0; t < small.size(); ++t)
        {
            cout << small[t] <<" ";
        }
        cout <<"\n";
        for(int t = 0; t < large.size(); ++t)
        {
            cout << large[t] <<" ";
        }
        cout <<"\n";*/


        cout << (i+2)<<" ";
        if(small.size() >= large.size())
        {
            cout << small[0];
            result += small[0];
        }
        else
        {
            cout << large[0];
            result += large[0];
        }
        cout <<"\n";
        result %= 10000;
    }
    cout << result;
}
