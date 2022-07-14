#include <bits/stdc++.h>
using namespace std;

int CheckPassword(char str[], int n)
{
    char current_char = *str;
    if(*str >=48 && *str <=57) return 0;
    str++;
    int total_char = 0, num_dig = 0, caps = 0, space_slash = 0;
    int i = 0;
    while (i<n)
    {
        if(*str >=48 && *str <= 57) num_dig++;
        if(*str >= 65 && *str<= 90) caps++;
        if(*str == 32 || *str == 47 || *str == 92){ space_slash++; break;}
        total_char++;
        i++, str++;
    }
    return total_char>=4 && num_dig>=1 && caps>=1 && space_slash==0;
}

int main()
{
    string s;
    getline(cin, s);
    int len = s.size();
    char *c = &s[0];
    cout << CheckPassword(c, len);
}