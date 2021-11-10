#include <iostream>
#include <vector>

void ways(int n);
int min2(int num1,int num2) {
    return num1<=num2?num1:num2;
}
int min3(int num1,int num2,int num3) {
    int min = num1<=num2?num1:num2;
    return min<num3?min:num3;
}

int min2Index(std::vector<int>& v,int i1,int i2) {
    return v[i1]<=v[i2]?i1:i2;
}

int min3Index(std::vector<int>& v,int i1,int i2,int i3) {
    int min = v[i1]<=v[i2]?i1:i2;
    return v[min]<=v[i3]?min:i3;
}

int main() {
    int n;
    std::cin>>n;
    ways(n);
}

void ways(int n) {
    std::vector<int> v(n);
    std::vector<int> v1;
    int num1=0;
    int num2=0;
    int num3=0;
    v[0] = 0;
    for(int i=1;i<n;i++) {
        num1 = (i+1)-1;
        if((i+1)%2==0) num2=(i+1)/2;
        if((i+1)%3==0) num3=(i+1)/3;
        if(num2!=0 && num3!=0) {
            num1=min3(v[num1-1],v[num2-1],v[num3-1]);
            v[i] = num1+1;
            num1=0;
            num2=0;
            num3=0; 
            continue;
        }
        if(num2==0 && num3==0) {
            v[i] = v[num1-1]+1;
            num1=0;
            continue;
        }
        if(num2==0 && num3!=0) {
            num1 = min2(v[num1-1],v[num3-1]);
            v[i] = num1+1;
            num1=0;
            num3=0;
            continue;
        }
        if(num3==0 && num2!=0) {
            num1 = min2(v[num1-1],v[num2-1]);
            v[i] = num1+1;
            num1=0;
            num2=0;
            continue;
        }
    }

    std::cout<<v[n-1]<<std::endl;

    int i=n;
    v1.push_back(i);
    while(i!=1) {
        num1 = i-1;
        if(i%2==0) num2=i/2;
        if(i%3==0) num3=i/3;
        if(num2!=0 && num3!=0) {
            i=min3Index(v,num1-1,num2-1,num3-1);
            v1.insert(v1.begin(),i+1);
            num1=0;
            num2=0;
            num3=0; 
            continue;
        }
        if(num2==0 && num3==0) {
            i = (num1-1)+1;
            v1.insert(v1.begin(),i);
            num1=0;
            continue;
        }
        if(num2==0 && num3!=0) {
            i = min2Index(v,num1-1,num3-1)+1;
            v1.insert(v1.begin(),i);
            num1=0;
            num3=0;
            continue;
        }
        if(num3==0 && num2!=0) {
            i = min2Index(v,num1-1,num2-1)+1;
            v1.insert(v1.begin(),i);
            num1=0;
            num2=0;
            continue;
        }
    }
    for(int i=0;i<v1.size();i++) {
        std::cout<<v1[i]<<" ";
    }
    std::cout<<std::endl;
}