#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums;
    map<int, int> freq;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int element;
        cin >> element;
        nums.push_back(element);
    }

    for (int num : nums)
    {
        freq[num]++;
    }

    int mode = nums[0];
    int maxCount = 0;
    for (auto const &x : freq)
    {
        if (x.second >= maxCount)
        {
            maxCount = x.second;
            mode = x.first;
        }
    }

    cout << mode << endl;

    return 0;
}