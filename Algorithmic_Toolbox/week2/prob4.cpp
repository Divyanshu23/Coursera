#include<iostream>
using namespace std;
long long lcm(int m,int n)
{
    if(m>=n)
    {
        for(int i=1;i<=n;i++)
        {
            if(((long long)m*i)%n == 0) return (long long)m*i;
        }
    }else
    {
        for(int i=1;i<=m;i++)
        {
            if(((long long)n*i)%m == 0) return (long long)n*i;
        }
    }
    
}
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<lcm(m,n);
    return 0;
}