#include <bits/stdc++.h>
using namespace std;

long long maxPairWiseProductFast(vector<long int>& num);

int main()
{
    int n;
    cin>>n;
    vector<long int> numbers(n);
    for(int i=0;i<n;i++)
        cin>>numbers[i];
    
    long long res1=maxPairWiseProductFast(numbers);
    cout<<res1;
    return 0;
}

long long maxPairWiseProductFast(vector<long int>& num)
{
    int n=num.size();

    int max_ind1 = 0;
    for(int i=0;i<n;i++)
        if(num[i] > num[max_ind1])
            max_ind1=i;

    long long max1= num[max_ind1];
    
    auto it = num.begin() + max_ind1;
    num.erase(it);

    int max_ind2 = 0;
    for(int i=0;i<n;i++)
        if((i != max_ind1 ) && (num[i] > num[max_ind2]))
            max_ind2=i;

    return max1*num[max_ind2];
}