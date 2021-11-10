#include <iostream>
#include <vector>

void moneyChange(int money);          //function to change money with denominations
int min(int num1,int num2,int num3);  // function to get min out of num1,num2,num3

int main() {
    int money;
    std::cin>>money;
    moneyChange(money);
    return 0;
}

int min(int num1,int num2,int num3) {         // In the min function. care has been taken to ensure that 
    int min;                                  // only non- zero values out of num1,num2 and num3 are 
    if(num2!=0 && num3!=0) {                  // compared and min is returned.
        min = num1<=num2 ? num1:num2;          // Note that num1 will be alwasy npn-negative. How?
        return min<=num3 ? min:num3;          // Because that's what the logic of moneyChange function allows.
    }
    else if(num2!=0 && num3==0) {
        return num1<=num2?num1:num2;
    }
    else{
        return num1;
    }
}

//Dynamic Programming approcah to fill the vector from v[0] to v[min] wher v[i]  is the no. of ways to
// change i from the denominations 1,3,4.
void moneyChange(int money) {
    std::vector<int> v(money+1);
    int num1=0;
    int num2=0;
    int num3=0;
    v[0] = 0;
    for(int i=1;i<=money;i++) {
        num1 = v[i-1]+1;                  // mo condition on num1 because v[i-1] will be always greater than or
        if((i-3)>=0) num2 = v[i-3]+1;     // equal to 0 as i goes from 1.
        if((i-4)>=0) num3 = v[i-4]+1;
        num1 = min(num1,num2,num3);
        v[i] = num1;
        num1=0;
        num2=0;
        num3=0;
    }
    std::cout<<v[money];
}