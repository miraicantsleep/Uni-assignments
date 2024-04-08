#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> strings;

    while (cin.peek() != '\n')
    {
        string element;
        cin >> element;
        strings.push_back(element);
    }

    sort(strings.begin(), strings.end(), greater<string>());

    while (!strings.empty())
    {
        cout << strings.back() << " ";
        strings.pop_back();
    }
}