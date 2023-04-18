#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    std::freopen("input.txt", "r", stdin);
    int t, x1, y1, r1, x2, y2, r2;
    double d;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
        if (d == 0)
        {
            if (r1 == r2)
                cout << -1 << "\n";
            else
                cout << 0 << "\n";
        }
        else
        {
            if ((d < (r1 + r2)) && (d > abs(r1 - r2)))
                cout << 2 << "\n";
            else if ((d == (r1 + r2)) || (d == abs(r1 - r2)))
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }
    return 0;
}