#include<iostream>
short outputCoins(int);
int main()
{
    int n;
    std::cin>>n;
    std::cout<<outputCoins(n)<<std::endl;
}

short outputCoins(int n) {
    short count1 = 0;
    int rem=n;
    count1 += n/10;
    rem = n%10;
    n = rem;
    count1 += n/5;
    rem = n%5;
    return count1+rem;
}