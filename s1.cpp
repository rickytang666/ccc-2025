#include <iostream>
#include <cmath>

using namespace std;

// Score: 15/15
// Time: O(1)

int main()
{
    long long A, B, X, Y;
    cin >> A >> B >> X >> Y;

    long long width_1 = A + X;
    long long height_1 = max(B, Y);
    long long perimeter_1 = 2 * (width_1 + height_1);

    long long width_2 = max(A, X);
    long long height_2 = B + Y;
    long long perimeter_2 = 2 * (width_2 + height_2);

    cout << min(perimeter_1, perimeter_2) << endl;

    return 0;
}