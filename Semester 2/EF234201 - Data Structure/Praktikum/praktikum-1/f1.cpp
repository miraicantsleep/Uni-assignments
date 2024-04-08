#include <bits/stdc++.h>
using namespace std;

vector<int> myVector;

void solve()
{
    int query;
    cin >> query;
    if (query == 1)
    {
        int element;
        cin >> element;
        myVector.push_back(element);
    }
    else if (query == 2)
    {
        int angka;
        cin >> angka;
        for (auto &&i : myVector)
        {
            i += angka;
        }
    }
    else if (query == 3)
    {
        if (myVector.empty())
        {
            cout << "kosong woe\n";
        }
        else
        {
            myVector.pop_back();
        }
    }
    else if (query == 4)
    {
        if (myVector.empty())
        {
            cout << "gaada isinya :(\n";
        }
        else
        {
            for (auto &&i : myVector)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    else if (query == 5)
    {
        int position;
        int element;
        cin >> position >> element;
        myVector.insert(myVector.begin() + position, element);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
