#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, string>> pq;
void solve()
{
    int pr;
    string what;
    cin >> pr;
    cin.ignore();
    getline(cin, what);
    if (strstr(what.c_str(), "seru-seruan") != NULL)
    {
        return;
    }

    pq.push(make_pair(pr, what));
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    while (!pq.empty())
    {
        cout << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}
