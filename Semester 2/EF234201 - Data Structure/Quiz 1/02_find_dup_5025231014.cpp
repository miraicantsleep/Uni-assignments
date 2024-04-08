#include <bits/stdc++.h>
using namespace std;

int main()
{
    string userInput;
    cin >> userInput;
    for (int i = 0; i < userInput.size(); i++) // Looping through the string
    {
        char currentChar = userInput[i]; // Setting the current character to find the dup
        userInput.erase(i, 1); // Erase it so it doesn't find itself
        if (userInput.find(currentChar) != string::npos) // If found, print it and get out of the loop
        {
            cout << currentChar << endl;
            break;
        }
    }
}