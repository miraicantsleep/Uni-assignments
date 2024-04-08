#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    string exclamation;
    int exclamationCount;
    int stringLength;
} Exclamation;

int main()
{
    vector<Exclamation> exclamations;
    while (cin.peek() != EOF)
    {
        string userInput;
        getline(cin, userInput);
        exclamations.push_back({userInput, count(userInput.begin(), userInput.end(), '!'), userInput.size()});
    }

    sort(exclamations.begin(), exclamations.end(), [](Exclamation a, Exclamation b)
         {
        if (a.exclamationCount == b.exclamationCount)
        {
            return a.stringLength < b.stringLength;
        }
        return a.exclamationCount > b.exclamationCount; });

    for (auto &&i : exclamations)
    {
        cout << i.exclamation << endl;
    }
}