#include<iostream>
using namespace std;
short fib1(short rem1)
{
    long* ptr = (long*)malloc(3*sizeof(long));
    ptr[0] = 0;ptr[1]=1;;
    for(int i=2;i<=(rem1+1);i++)
    {
        ptr[2] = ptr[0]+ptr[1];
        ptr[0] = ptr[1];
        ptr[1] = ptr[2];
    }      // ptr[0] = ptr[rem1]  ptr[1] = ptr[rem1+1]
    short digit = (ptr[0]%10+ptr[1]%10)%10; ;
    for(short i=(rem1+2);i<=59;i++)
    {
        ptr[2] = ptr[0]+ptr[1];
        ptr[0] = ptr[1];
        ptr[1] = ptr[2];
        digit = (digit + ptr[2]%10)%10;
    }
    free(ptr);
    return digit;
}

short fib2(short rem2)
{
    long* ptr = (long*)malloc(3*sizeof(long));
    ptr[0] = 0;
    ptr[1] = 1;
    short digit = 1;
    for(short i=2;i<=rem2;i++)
    {
        ptr[2] = ptr[0]+ptr[1];
        ptr[0] = ptr[1];
        ptr[1] = ptr[2];
        digit = (digit + ptr[2]%10)%10;
    }
    free(ptr);
    return digit;
}

void sum(long m,long n)
{
    short rem1 = m%60;
    short rem2 = n%60;
    short digit1,digit2,flag1=0,flag2=0;
    if(rem1==0)
    {
        flag1 = 1;
        digit1 = 0;
    }
    if(rem2 == 0)
    {
        flag2 = 1;
        digit2 = 0;
    }
    if(!flag1)
        digit1 = fib1(rem1);
    if(!flag2)
        digit2 = fib2(rem2);
    cout<<(digit1+digit2)%10;
}

int main()
{
    long m,n;
    cin>>m>>n;
    sum(m,n);
    return 0;
}