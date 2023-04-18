#include <iostream>

using namespace std;

int main()
{
    std::freopen("input.txt", "r", stdin);
    int a = 0, b = 0;
    cin >> a >> b;
    cout << a - b;
    return 0;
}