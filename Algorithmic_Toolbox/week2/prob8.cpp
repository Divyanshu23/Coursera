#include<iostream>
using namespace std;
void sum(long n);
int main()
{
    long n;
    cin>>n;
    sum(n);
    return 0;
}
void sum(long n)
{
    short* ptr = (short*)malloc(3*sizeof(short));
    ptr[0] = 0;
    ptr[1] = 1;
    short rem = n%60;
    if(rem==0)
    {
        cout<<0;
        return;
    }
    short digit = 1;
    for(short i=2;i<=rem;i++)
    {
        ptr[2] = ((ptr[0])%10) + ((ptr[1])%10);
        ptr[0] = ptr[1];
        ptr[1] = ptr[2];
        digit = (digit+((ptr[2]*ptr[2])%10))%10;
    }
    cout<<digit;
}