/* Input:aba abacaba
Output:0 4

Input:Test testTesttesT
Output:4

Input:aaaaa baaaaaaa
Output: 1 2 3 */
#include <iostream>
#include <string>
#include <vector>

using std::string;

struct Data 
{
    string pattern, text;
};

Data read_input() 
{
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) 
{
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) 
{ 
    string s = input.pattern, t = input.text;
    std::vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;
}


int main() 
{
    print_occurrences(get_occurrences(read_input()));
    return 0;
}