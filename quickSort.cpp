#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

long long int comparisons = 0;
int findPivot(int a, int b)
{
    //return a;
    return (a+b)/2 - !((a+b)%2);
}

int partition_(vector <int> & vec, int fi, int en, int p)
{
    int temp;
    if(p != fi)
    {
        temp = vec[fi];
        vec[fi] = vec[p];
        vec[p] = temp;
        p = fi;
    }
    comparisons += (en-fi)-1;
    int i = fi + 1, j = fi + 1;
    for(; j < en; ++j)
    {
        if(vec[j] <= vec[p])
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
    return (i-1);
}
void quicksort(vector <int> & vec, int fi, int en)
{
    if( (en - fi) <= 1)
        return;
    int pivot = findPivot(fi, en);
    int middle = findPivot(fi, en);
    int arr[3] = {vec[fi], vec[middle], vec[en-1]};
    sort(arr, arr+3);
    if(middle == fi) // note median of 3 elements where 1st is the same element is that element itself
    {
        pivot = middle;
    }
    else
    {
        if(vec[fi] == arr[1])
            pivot = fi;
        else if(vec[middle] == arr[1])
            pivot = middle;
        else
            pivot = en-1;
    }
    pivot = partition_(vec, fi, en, pivot);
    quicksort(vec, fi, pivot);
    quicksort(vec, pivot+1, en);
}
int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("quickSort1.txt");

    ios::sync_with_stdio(false);infile.tie(0);cout.tie(0);

    vector <int> storage;

    int i, var;
    for(i = 1; i<= 10000; ++i)
    {
        infile >> var;
        storage.pb(var);
    }

    quicksort(storage, 0, storage.size());
    cout << comparisons<<"\n";
    for(i = 0; i< storage.size(); ++i)
    {
        file << storage[i]<<"\n";
    }
    return 0;
}
