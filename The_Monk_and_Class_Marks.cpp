#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<int, set<string>> mp;
    while (n--)
    {
        string name;
        int marks;
        cin >> name >> marks;
        mp[marks].insert(name);
    }

    auto cur_it = --mp.end();
    while (true)
    {
        auto &total_marks = cur_it->first;
        auto &name = cur_it->second;

        for (auto &students : name)
        {
            cout << students << " " << total_marks << endl;
        }
        if (cur_it == mp.begin())
            break;
        cur_it--;
    }

    return 0;
}
