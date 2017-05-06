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
	int var;
	cout << "Enter elements of the vector\n";
	while(true)
	{
	cin >> var;
	if(var == -10)
	{
		break;
	}

	vec.pb(var);
	}

	int upper = vec.size(), lower = 0, mid;

	while(true)
	{
		mid = (upper + lower)/2;
		if(upper - lower == 2)
		{
			if(vec[lower+1] > vec[lower])
			{
				mid = lower+1;
			}
			else
			{
				mid = lower;
			}
			break;
		}
		else if(upper - lower == 1)
		{
			break;
		}
		else if(vec[mid] > vec[mid+1] && vec[mid] > vec[mid-1])
		{
			break;
		}
		else
		{
			if(vec[mid] < vec[mid+1])
			{
				lower = mid+1;
			}
			else
			{
				upper = mid;
			}
		}
	}
	cout << vec[mid]<<"\n";

	return 0;
}
