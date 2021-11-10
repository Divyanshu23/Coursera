#include<iostream>
using namespace std;
long long fib(int n)
{
    long long *ptr = (long long*)malloc((n+1)*sizeof(long long));
    ptr[0] = 0;
    ptr[1] = 1;
    if(n>=2)
    {
        for(int i=2;i<=n;i++)
        {
            ptr[i] = ptr[i-1] + ptr[i-2];
        }
        return ptr[n];
    }else
    {
        return ptr[n];
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}