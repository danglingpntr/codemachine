#include <bits/stdc++.h>                          
using namespace std; 

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) 
    {
        if(index == s.size()) 
        {
            ret.push_back(path);
            return;
        }
        
        for(int i = index; i < s.size(); ++i) 
        {
            cout<<"i:"<<i<<" index_before_rec:"<<index<<endl;
            if(isPalindrome(s, index, i)) 
            {
                path.push_back(s.substr(index, i - index + 1));
                cout<< s.substr(index, i - index + 1) << endl;
                dfs(i+1, s, path, ret);
                for (auto &c:path)
                    cout<< c <<"_";
                cout<<endl<<"i="<<i<<" index_after_rec:"<<index<<endl;
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    for( auto const& string_vec : s.partition("aabaa") )
        for( auto const& s : string_vec )
            cout << s << " ";
    return 0;
}