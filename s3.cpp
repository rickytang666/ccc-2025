#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

/*
    Score: 0/15 😭 (Didn't even understand the question)
*/

bool compare_1(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

bool compare_2(pair<int, set<int, greater<int>>> p1, pair<int, set<int, greater<int>>> p2)
{
    return *p1.second.begin() > *p2.second.begin();
}

int main()
{
    int M, N, Q;
    cin >> N >> M >> Q;

    vector<pair<int, int>> v(N); // color : prettiness
    map<int, set<int, greater<int>>> m; // color : prettiness
    
    for (int i = 0; i < N; ++i)
    {
        int c, p;
        cin >> c >> p;
        v[i].first = c;
        v[i].second = p;
        m[c].insert(p);
    }

    vector<pair<int, set<int, greater<int>>>> m2;

    for (auto a : m)
    {
        m2.emplace_back(a.first, a.second);
    }

    sort(m2.begin(), m2.end(), compare_2);

    vector<vector<int>> changes; // option, id, color/prettiness

    for (int i = 0; i < Q; ++i)
    {
        vector<int> vec(3);
        for (int j = 0; j < 3; ++j)
        {
            cin >> vec[j];
        }
        changes.push_back(vec);
    }

    for (int i = 0; i <= Q; ++i)
    {
        if (i == 0)
        {
            
            vector<pair<int, int>> temp = v;

            sort(temp.begin(), temp.end(), compare_1);

            int new_max = 0;

            for (int i = 0; i < M - 1; ++i)
            {
                auto a = m2[i];
                new_max += *a.second.begin();

                for (int j = 0; j < temp.size(); ++j)
                {
                    auto b = temp[j];
                    if (a.first == b.first && *a.second.begin() == b.second)
                    {
                        temp.erase(temp.begin() + j);
                        break;
                    }
                }
            }

            new_max += temp.front().second;

            cout << new_max << endl;
            
        }
    }

    return 0;
}