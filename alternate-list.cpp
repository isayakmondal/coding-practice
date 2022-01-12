#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
   
    cin >> n;

    char pid[n];

    for (int i = 0; i < n; i++)
    {

        cin >> pid[i];
    }
    
    cin>>m;

    int quantity[m];

    for (int i = 0; i < m; i++)
    {

        cin >> quantity[i];
    }
    

    for (int i = 0; i < n; i++)
    {
        cout<<pid[i]<<" "<<quantity[i]<<" ";
        
    }
    

    return 0;
}
