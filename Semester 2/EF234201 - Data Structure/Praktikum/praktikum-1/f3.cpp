#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> myVector;
    int tc1, tc2;
    cin >> tc1 >> tc2;

    int totalTC = tc1 + tc2;

    while (totalTC--)
    {
        int element;
        cin >> element;
        myVector.push_back(element);
    }

    sort(myVector.begin(), myVector.end());

    while (!myVector.empty())
    {
        cout << myVector.back() << " ";
        myVector.pop_back();
    }
}
