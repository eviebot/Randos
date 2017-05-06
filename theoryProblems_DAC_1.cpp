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
	ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("A-large.in");

    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cout << "Enter number of elements of the array\n";
    int n;
    cin >> n;
    int storage[n], max_1st, max_2nd, i;

    cout << "Enter elements of the array\n";
    for(i = 0; i< n; ++i)
    {
    	cin >> storage[i];
    }

    max_1st = max(storage[0], storage[1]);
    max_2nd = min(storage[0], storage[1]);

    for(i = 2; i< n; ++i)
    {
    	if(storage[i] > max_1st)
    	{
    		max_2nd = max_1st;
    		max_1st = storage[i];
    	}
    }

    cout << max_2nd<<"\n";
}