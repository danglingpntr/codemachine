/* Problem Introduction
You are given a primitive calculator that can perform the following three operations with
the current number 𝑥: multiply 𝑥 by 2, multiply 𝑥 by 3, or add 1 to 𝑥. Your goal is given a
positive integer 𝑛, find the minimum number of operations needed to obtain the number 𝑛
starting from the number 1.

Problem Description

Task-> Given an integer 𝑛, compute the minimum number of operations needed to obtain the number 𝑛
starting from the number 1.

Input Format-> The input consists of a single integer 1 ≤ 𝑛 ≤ 106.

Output Format-> In the first line, output the minimum number 𝑘 of operations needed to get 𝑛 from 1.
In the second line output a sequence of intermediate numbers. That is, the second line should contain
positive integers 𝑎0, 𝑎2, . . . , 𝑎𝑘−1 such that 𝑎0 = 1, 𝑎𝑘−1 = 𝑛 and for all 0 ≤ 𝑖 < 𝑘 − 1, 𝑎 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int32_t number;
    cin >> number;
    std::vector<int32_t> min_steps(number + 1);
    std::vector<int32_t> predecessor(number + 1);

    for (int32_t i = 2; i <= number; i++) {
        min_steps[i] = min_steps[i-1] + 1;
        predecessor[i] = i - 1;
        if (i % 3 == 0) {
            if (min_steps[i/3] < min_steps[i]) {
                min_steps[i] = min_steps[i/3] + 1;
                predecessor[i] = i/3;
            }
        }
        if (i % 2 == 0) {
            if (min_steps[i/2] < min_steps[i]) {
                min_steps[i] = min_steps[i/2] + 1;
                predecessor[i] = i/2;
            }
        }
    }

    std::cout << min_steps[number] << "\n";

    for (auto it = min_steps.begin(); it != min_steps.end(); ++it)
        std::cout <<"Min Step:"<< *it  << endl;
    
     for (auto it = predecessor.begin(); it != predecessor.end(); ++it)
        std::cout <<"predecessor:"<< *it  << endl;

    std::list<int32_t> sequence;
    for (int32_t i = number; i != 0; i = predecessor[i]) {
        sequence.push_front(i);
    }
    for (auto it = sequence.begin(); it != sequence.end(); ++it)
        std::cout << *it  << " ";

    return 0;
}