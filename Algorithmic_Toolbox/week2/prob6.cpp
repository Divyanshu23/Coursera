#include<iostream>
using namespace std;
void fun(long n)
{
    long long *ptr = (long long*)malloc(3*sizeof(long long));
    int rem = n%60;
    if(rem==0)
    {
        cout<<0;
        return;
    }
    ptr[0] = 0;
    ptr[1] = 1;
    short digit=1;
    for(long i=2;i<=rem;i++)
    {
        ptr[2] = (ptr[0] + ptr[1])%10;
        ptr[0] = ptr[1];
        ptr[1] = ptr[2];
        digit = (digit + ptr[2])%10;
    }
    cout<<digit;
}
int main()
{
    long n;
    cin>>n;
    fun(n);
    return 0;
}