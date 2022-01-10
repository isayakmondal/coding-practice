#include<iostream>

using namespace std;

int gcd(int a, int b){

    if(a%b==0) return b;
     return gcd(b,a%b);
   
}

int main(int argc, char const *argv[])
{
    int a=18,b=12;
    cout<<gcd(a,b)<<endl;
    cout<<"LCM = "<< a*b/gcd(a,b);
    
    return 0;
}
