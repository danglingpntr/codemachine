#include <bits/stdc++.h>
using namespace std;

int find_len(int a, int b, vector<int> &lsp)
{
    if (lsp[a] == 0 || lsp[b] == 0 || lsp[a] == lsp[b])
    {
        return lsp[a] & lsp[b];
    }

    if (lsp[a] > lsp[b])
        return find_len(lsp[a] - 1, b, lsp);

    else if (lsp[b] > lsp[a])
        return find_len(a, lsp[b] - 1, lsp);
}

void fill_lsp(int m, string pat, vector<int> &lsp)
{
    int j = 0;
    int i = 1;
    lsp[0] = 0;

    while (i < m)
    {
        if (pat[i] == pat[j])
        {
            lsp[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lsp[j - 1];
            else
            {
                lsp[i] = 0;
                i++;
            }
        }
    }
    // for (auto a:lsp)
    //     cout <<"LSP a:" << a <<endl;
}

int main()
{
    int t;
    cin >> t;
    string s;
    int k;

    while (t--)
    {
        cin >> s >> k;
        int m = s.size();
        vector<int> lsp(m);
        fill_lsp(m, s, lsp);
        if (lsp[m - 1] != 0)
        {
            int id = 0;
            int mx = 0;
            for (int i = k - 1; i > 0; i--)
            {
                if (lsp[i] != 0 && s[i] == s[m - 1] && mx < lsp[i])
                {
                    id = i;
                    mx = lsp[i];
                }
            }
            
            if (id == 0)
                cout << "Puchi is a cheat!" << '\n';
            else
            {
                int len = find_len(id, m - 1, lsp);
                if (len == 0)
                    cout << "Puchi is a cheat!" << '\n';
                else
                {
                    string p = s.substr(0, len);
                    cout << p << '\n';
                }
            }
        }
        else
            cout << "Puchi is a cheat!" << '\n';
    }
}