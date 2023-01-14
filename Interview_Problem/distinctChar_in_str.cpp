#include<bits/stdc++.h>
using namespace std;


void solve(int N, string str)
{
    long long arr[26];
    memset(arr, 0 , sizeof(arr));
    set <char> set_str(begin(str), end(str));
    int size = set_str.size();
    double val;
    val = ((N)*(N+1)) / 2 ;
    for (int i=0; i<size; i++)
    {
        arr[i]= (int) val;
        val/=2;
        cout<<val<<endl;
    }

    for (int i=0; i<26; i++)
    {
        cout << arr[i] << " ";
    }

}

int main() {

    /* ios::sync_with_stdio(0);
    cin.tie(0); */
    string str;
    int N;
    cin >> N;
    cin >> str;
    solve(N, str);
}