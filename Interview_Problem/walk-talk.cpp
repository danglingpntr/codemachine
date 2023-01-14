
// Program to find the max difference of indexes of repetitive number in input of numbers 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    vector<int> diffMax;
    cout << "Enter the number of items:"
         << "\n";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " items" << endl;
    for ( x = 0; x < n; x++)
    {
        cin >> arr[x];
    }

    unordered_map<int, vector<int>> myMap;
    for (int i=0; i<n; i++)
    {
        myMap[arr[i]].push_back(i);
    }

    for (auto i = myMap.begin(); i != myMap.end(); i++)
    {
        cout <<"IN MAP: "<< i->first <<endl;
        if (i->second.size() == 1)
            continue;
        if (i->second.size() == 2)
        {
            double dbl=round((i->second[1] - i->second[0]) / 2.0);
            diffMax.push_back(dbl);
            cout <<"Diff:"<<dbl<<endl;
        }
        else
        {
            int intial = 0;
            cout << "Indexes:";
            for (const auto &s : i->second)
            {
                cout << s << ' ';
                cout << (s - intial) << ' ';
                diffMax.push_back(s - intial);
                intial = s;
            }
        }
        cout<<"\n";
    }
    if ( diffMax.size() > 1 )
        cout <<"\n"<< *max_element(diffMax.begin(), diffMax.end())<<endl;
    else
        cout << "No element repeated";
    return 0;
}