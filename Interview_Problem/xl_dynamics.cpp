#include <bits/stdc++.h>

using namespace std;

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int main() {
    string str = "5.0,100,5.5,101,6.0,102:L10;5.0,99,5.5,100,6.0,101:L20;5.0,100,5.5,101,6.0,102:L30;";
    vector<string> v1 = split (str, ';');
    map<string, vector<string>> val_str;

    for (auto i : v1)
    {
        vector<string> v2=split (i , ':');
        vector<string> v3=split (v2[0] , ',');
        v2[1].erase(v2[1].begin());
        cout<<"      "<<v2[1];
        for (int i=0;i<v3.size();i++)
        {
            string key=v3[i];
            i++;
            val_str[key].push_back(v3[i]);
        }
        
    }
    cout<<endl;
    for(auto it = val_str.begin(); it != val_str.end(); ++it)
    {
        cout << it->first << "   ";
        for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            cout << *it2 << "   ";
        cout<<endl;
    }
    return 0;
}