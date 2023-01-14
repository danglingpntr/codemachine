#include <bits/stdc++.h>
using namespace std;

void maxValueOfarray(vector<int> &arr)
{
    map<int, int> note;

    for (int i = 0; i < arr.size(); ++i)
        note.insert({arr[i], i});

    int i = arr.size() - 1, beg, end;
    auto it = note.end(); it--;
    while (i >= 0)
    {
        if (it->first != arr[i])
        {
            beg = it->second;
            end = arr[i];
            arr[i] = it->first;
            break;
        }
        it--; i--;
    }
    
    for (int a = beg; a < i - 1; a++)
        arr[a] = arr[a + 1];
    
    cout<<endl;
    arr[i - 1] = end;
    for (auto &i : arr)
        cout << i<<" ";
}

int main()
{
    unsigned int n;
    std::cin >> n;
    vector<int> notes(n);
    for (size_t i = 0; i < n; ++i)
        cin >> notes[i];

    maxValueOfarray(notes);

    return 0;
}