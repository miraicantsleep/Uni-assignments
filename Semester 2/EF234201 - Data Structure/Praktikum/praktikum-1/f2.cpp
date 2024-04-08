#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    deque<char> firstSet;
    deque<char> secondSet;

    int count;
    cin >> count;

    while (count--)
    {
        char macaron;
        cin >> macaron;
        firstSet.push_front(macaron);
    }

    int tc;
    cin >> tc;
    while (tc--)
    {
        string query;
        cin >> query;
        if (query == "PULL")
        {
            int element;
            cin >> element;
            if (firstSet.size() < element)
            {
                cout << "Macaron Furina tidak sebanyak itu pls!\n";
            }
            else
            {
                secondSet.push_front(firstSet[element - 1]);
                firstSet.erase(firstSet.begin() + (element - 1));
                reverse(firstSet.begin(), firstSet.begin() + (element - 1));
            }
        }
        else if (query == "PUT")
        {
            while (!secondSet.empty())
            {
                firstSet.push_front(secondSet.front());
                secondSet.pop_front();
            }
        }
        else
        {
            cout << "Apa itu? Furina tidak paham!\n";
        }
    }

    for (auto i = firstSet.end() - 1; i >= firstSet.begin(); i--)
    {
        cout << *i << " ";
    }

    cout << "\n";

    for (auto i = secondSet.end() - 1; i >= secondSet.begin(); i--)
    {
        cout << *i << " ";
    }
    cout << "\n";
}