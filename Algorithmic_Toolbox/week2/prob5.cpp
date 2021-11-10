#include<iostream>
using namespace std;
void period(int m,long n)
{
    int* ptr = (int*)malloc(1501*sizeof(int));
    ptr[0] = 0;
    ptr[1] = 1;
    short prd = 2;
    short flag=0;
    for(int i=2;i<=3000;i++)
    {
        ptr[i] = (ptr[i-1] + ptr[i-2])%m;
        if(ptr[i]==0)
        {
            flag=1;
            continue;
        }
        if(flag==1 && ptr[i]==1)
        {
            prd = i-1;
            break;
        }
        flag=0;
    }
    short temp = n%prd;
    cout<<ptr[temp];
}

int main()
{
    long n;
    int m;
    cin>>n>>m;
    period(m,n);
    return 0;
}