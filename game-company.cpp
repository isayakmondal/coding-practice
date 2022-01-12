#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    long long s = 0;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        s += arr[i] / k;
    }

    cout << s << endl;

    return 0;
}
