#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair

deque <int> subtract(deque <int> & a, deque <int> &b)
{
    deque <int> sub;
    deque <int>::iterator ita = a.begin(), itb = b.begin();
    while(itb != b.end())
    {
        *ita -= *itb;
        ++ita;
        ++itb;
    }

    ita = a.begin();
    while(ita != a.end())
    {
        if(*ita < 0)
        {
            *ita += 10;
            ++ita;
            --(*ita);
        }
        else
        {
            ++ita;
        }
    }
    return a;
}

deque <int> add(deque <int> &a, deque <int> & b)
{
    deque <int> addi;
    deque <int>::iterator ena = a.begin(), enb = b.begin();

    while(ena != a.end() && enb != b.end())
    {
        addi.pb((*ena) + (*enb));
        ++ena; ++enb;
    }
    while(ena != a.end())
    {
        addi.pb(*ena);
        ++ena;
    }
    while(enb != b.end())
    {
        addi.pb(*enb);
        ++enb;
    }
    ena = addi.begin();
    enb = addi.end();
    --enb;
    while(ena != enb)
    {
        if((*ena) > 9)
        {
            *ena = (*ena) - 10;
            ++ena;
            *ena = (*ena)+1;
        }
        else
        {
            ++ena;
        }
    }
    if(*ena > 9)
    {
        *ena = (*ena) - 10;
        addi.pb(1);
    }
    return addi;
}
deque <int> findProd(deque <int> &vec1, deque <int> &vec2, int len1, int len2)
{
    deque <int> subvec1, subvec2, subvec3, a, b, c, d, e, f;
    deque <int>::iterator beg2 = vec2.begin(), beg1 = vec1.begin();
    int num1, num2, l2 = len1/2 + len1%2, i;

    if(len2 == 1)
    {
        num1 = vec2[0];
        num2 = vec1[0];
        num1 *= num2;
        while(true)
        {
            subvec3.pb(num1%10);
            num1/=10;
            if(num1==0){

                return subvec3;
            }
        }
    }

    for(i = 0; i< l2; ++i)
    {
        b.pb(vec1[i]);
    }
    for(i = l2; i< len1; ++i)
    {
        a.pb(vec1[i]);
    }
    l2 = len2/2 + len2%2;
    for(i = 0; i< l2; ++i)
    {
        d.pb(vec2[i]);
    }
    for(i = l2; i< len2; ++i)
    {
        c.pb(vec2[i]);
    }
    /*cout << "a= ";
    for(i = a.size()-1; i>= 0; --i)
    {
        cout << a[i];
    }
    cout << "\nb= ";
    for(i = b.size()-1; i>= 0; --i)
    {
        cout << b[i];
    }
    cout << "\nc= ";
    for(i = c.size()-1; i>= 0; --i)
    {
        cout << c[i];
    }cout << "\nd= ";
    for(i = d.size()-1; i>= 0; --i)
    {
        cout << d[i];
    }
    cout <<"\n";*/

    //cout << a[0]<<" "<< c[0]<<" "<< b[0]<<" "<< d[0]<<"\n";
    //cout << a.size()<<" "<< b.size()<<" "<< c.size()<<" "<< d.size()<<"\n";
    if(a.size()< c.size())
    {
        while(a.size() != c.size())
        {
            a.pb(0);
        }
    }
    if(c.size() < a.size())
    {
        while(a.size() != c.size())
        {
            c.pb(0);
        }
    }
    if(b.size() < d.size())
    {
        while(b.size() != d.size())
        {
            b.pb(0);
        }
    }
    if(d.size() < b.size())
    {
        while(b.size() != d.size())
        {
            d.pb(0);
        }
    }
    subvec1 = findProd(a, c, a.size(), c.size());
    subvec2 = findProd(b, d, b.size(), d.size());

    e = add(a, b);
    f = add(c, d);
    if(e.size()< f.size())
    {
        while(e.size() != f.size())
        {
            e.pb(0);
        }
    }
    if(f.size() < e.size())
    {
        while(e.size() != f.size())
        {
            f.pb(0);
        }
    }
    subvec3 = findProd(e, f, e.size(), f.size());
    subvec3 = subtract(subvec3, subvec1);
    subvec3 = subtract(subvec3, subvec2);

    /*cout << "subvec1 ";
    for(i = subvec1.size()-1; i>= 0; --i)
    {
        cout << subvec1[i];
    }
    cout <<"\n";
    cout << "subvec2 ";
    for(i = subvec2.size()-1; i>= 0; --i)
    {
        cout << subvec2[i];
    }
    cout <<"\n";
    cout << "subvec3 ";
    for(i = subvec3.size()-1; i>= 0; --i)
    {
        cout << subvec3[i];
    }
    cout <<"\n";*/
    for(i = 0; i < b.size(); ++i)
    {
        subvec1.pf(0);
        subvec1.pf(0);
        subvec3.pf(0);
    }
    subvec3 = add(subvec1, subvec3);
    subvec3 = add(subvec2, subvec3);

    return subvec3;
}
int main()
{
    ofstream file;
    file.open("output.txt");
    ifstream infile;
    infile.open("A-large.in");

    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s1, s2;

    cin >> s1 >> s2;
    deque <int> vec1, vec2, vec3;

    int l = s1.length(), i;

    for(i = l-1; i >= 0 ; --i)
    {
        vec1.pb(s1[i]-'0');
    }
    l = s2.length();
    for(i = l-1; i >= 0 ; --i)
    {
        vec2.pb(s2[i]-'0');
    }
    if(vec1.size() < vec2.size())
    {
        while(vec1.size() != vec2.size())
        {
            vec1.pb(0);
        }
    }
    else
    {
        while(vec1.size() != vec2.size())
        {
            vec2.pb(0);
        }
    }
    cout << vec1.size()<<" "<< vec2.size()<<"\n";
    vec3 = findProd(vec1, vec2, vec1.size(), vec2.size());
    //vec3 = subtract(vec1, vec2);
    for(int i = vec3.size()-1; i>= 0; --i)
        cout << vec3[i];
    return 0;
}
