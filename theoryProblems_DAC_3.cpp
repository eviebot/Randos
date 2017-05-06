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

	vector <int> vec;
	int i, var;
	cout << "Enter a sorted array of distinct integers\n";

	while(true)
	{
		cin >> var;
		if(var == -100)
			break;
		vec.pb(var);
	}
	int upper = vec.size(), lower = 0, mid;
	while(upper > lower)
	{
		mid = (lower + upper)/2;
		if(vec[mid] == mid)
		{
			cout << "A[i] = i at position "<< mid <<"\n";
			break;
		}
		else if(vec[mid] > mid)
		{
			upper = mid;
		}
		else
		{
			lower = mid+1;
		}
	}
	if(upper == lower)
	{
		cout << "No such element found in the array\n";
	}
	return 0;
}
