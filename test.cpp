#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> iv = {
        {-1, -1, -1},
        {-1, -333, -1}, 
        {-1, -1, -1}
        };
    for (const auto &ev: iv)
    {
        for (const auto &ei: ev)
        {
            cout << ei << " ";
        }
        cout << endl;
    }
    return 0;
}