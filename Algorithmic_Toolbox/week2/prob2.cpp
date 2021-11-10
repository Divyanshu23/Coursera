#include<iostream>
using namespace std;
int lastdigit(int n)
{
    int* ptr = (int*)malloc((n+1)*sizeof(int));
    ptr[0] = 0;
    ptr[1] = 1;
    for(int i=2;i<=n;i++)
    {
        ptr[i] = (ptr[i-1] + ptr[i-2])%10;
    }
    return ptr[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<lastdigit(n);
    return 0;
}