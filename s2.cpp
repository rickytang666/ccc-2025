#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

// Score: 15/15
// Time: O(n)

int main()
{
    string S;
    cin >> S;

    long long c;
    cin >> c;

    long long total_length = 0;
    vector<pair<char, long long>> v;

    for (long long i = 0; i < S.size(); ++i)
    {
        if (!isdigit(S[i]))
        {
            long long count = 1;

            for (long long j = i + 1; j < S.size(); ++j)
            {
                if (j + 1 == S.size() || !isdigit(S[j + 1]))
                {
                    count = stoll(S.substr(i + 1, j - i));
                    break;
                }
            }

            v.emplace_back(S[i], count);
            total_length += count;

            // cout << "char: " << S[i] << " count: " << count << endl;
        }
    }

    c = c % total_length;

    // cout << total_length << endl;

    // cout << c << endl;

    long long curr_length = -1;

    for (long long i = 0; i < v.size(); ++i)
    {
        curr_length += v[i].second;
        if (curr_length >= c)
        {
            cout << v[i].first << endl;
            break;
        }
    }

    return 0;
}