#include<bits/stdc++.h>
using namespace std;

long long solve (int N, vector<int> A) 
{
   map<long, vector<long>, greater<long>> allGcd;
   for (int i=0; i<2*N ; i++)
   {
      for (int j=i+1; j<2*N ; j++)
      {
         long x = __gcd(A[i], A[j]);
         allGcd[x].push_back(A[i]);
         allGcd[x].push_back(A[j]);
      }
   }

   map<long, vector<long>>:: iterator it;
   int count;
   long gcdSum=0;
   it=allGcd.begin();
   while(N > 0)
   {
      long gcdTop = it->first;
      count=0; 
      for(auto itV =  it->second.begin() ; itV != it->second.end() ; itV++)
      {
         auto itA = find (A.begin(),A.end(),*itV);
         if(itA != A.end())
         {
            A.erase(itA);
            count++;
         }
      }

      for (int i = 0; i<count/2; i++)
      {
         gcdSum+=N*gcdTop;
         N--;
      }
      it++;
   }

   return gcdSum;
}

int main()
{
   int N;
   cin >> N;
   vector<int> A(2 * N);
   for (int i_A = 0; i_A < 2 * N; i_A++)
   {
      cin >> A[i_A];
   }
   long long out_;
   out_ = solve(N, A);
   cout << out_<<endl;
}