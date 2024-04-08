#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> bank; // Insert data, name as the key and money as the value
    bank.insert({"Puspita", 50});
    bank.insert({"Bejo", 35});
    bank.insert({"Sarita", 20});
    bank.insert({"Pujo", 45});
    bank.insert({"Lestari", 60});

    string name;
    cin >> name;

    if (bank.find(name) != bank.end()) // If found, output the money
    {
        cout << bank[name] << endl;
    }
    else
    {
        cout << "Not found" << endl; // If name not found, output "Not found"
    }
}