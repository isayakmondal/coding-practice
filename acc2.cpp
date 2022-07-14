#include <bits/stdc++.h>
using namespace std;

// Using only the pointer to char.
int OperationsBinaryString(char *str)
{
    int size = strlen(str);

    if (size == 0)
        return -1;

    int dig1 = *str - '0';
    str++;

    int ans = dig1;

    while (*str != '\0')
    {
        char temp = *str++;
        int dig2 = *str - '0';

        switch (temp)
        {
        case 'A':
            ans &= dig2;
            break;
        case 'B':
            ans |= dig2;
            break;
        case 'C':
            ans ^= dig2;
            break;

        default:
            break;
        }
    }
    return ans;
}

// int OperationsBinaryString(char* str)
// {
//     int size = strlen(str);

//     if(size == 0) return -1;

//     int dig1 = str[0] - '0';

//     int ans = dig1;
//     int i = 1;
//         while(i<size)
//     {

//         int temp = i;
//         i++;
//         int dig2 = str[i] - '0';

//         switch (str[temp])
//         {
//         case 'A':
//             ans &= dig2;
//             break;
//         case 'B':
//             ans |= dig2;
//             break;
//         case 'C':
//             ans ^= dig2;
//             break;

//         default:
//             break;
//         }
//         i++;
//     }
//     return ans;
// }

int main()
{
    string s;
    getline(cin, s);
    int len = s.size();
    char *str = &s[0];
    cout << OperationsBinaryString(str);
}