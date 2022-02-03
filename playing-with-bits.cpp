#include <bits/stdc++.h>

using namespace std;

#define ll long long

// int binary(int n)
// {
//     int q, r;
//     int bn = 0;
//     int ct = 0;
//     int c;
//     while (n != 0)
//     {
//         r = n % 2;
//         c = pow(10, ct);
//         bn += r * c;
//         n /= 2;
//         ct++;
//     }
//     return bn;
// }

void printBinary(int n)
{
    // cout<<"n: "<<n<<endl;
    for (int i = 10; i >= 0; i--)
    {   
        // cout << " n>>i: " << (n >> i) << " i: " << i << " Current binary val: " << bitset<5>(n >> i)
        //     << " (n>>i) & 1: "<< ((n >> i) &1) << endl;
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a = 9;
    // int i = 3;
    // printBinary(a);
    // printBinary(a>>1);

    // if ((a & (1 << i)) != 0)
    //     cout << "Set bit" << endl;
    // else
    //     cout << "Unset bit" << endl;

    /*Set bit*/
    // a = a | 1 << i;

    /*Unstet bit*/
    // a = a & ~(1 << i);

    // printBinary(a);

    /* Toggle bit */
    // a = a ^ 1 << i;
    int i = 3;
    int n = 59;
    
    /**
     * To unset msb or lsb upto ith bit
     */
    // int msb = n & (~((1<<i+1) - 1));
    // int lsb = n & ((1<<i+1) - 1);
    // printBinary(n);
    // printBinary(lsb);
    // printBinary(msb);

    // cout << bitset<32>(uint32_t{0}-1);
    char ch = 'a';
    // printBinary(ch);
    // cout<<(char)(ch ^(1<<5));
    char upperCase = 'A';
    cout<<(char)((upperCase | (1<<5)))<<endl;
    return 0;
}