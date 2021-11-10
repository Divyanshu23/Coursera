#include <iostream>
#include <algorithm> 
#include <vector>
#include <cstdlib>

using namespace std;

int raise(short n) {
    int value=1;
    for(int i=0;i<n;i++) {
        value *=10;
    }
    return value;
}

bool isGreaterOrEqual(int a,int b) {
    int n=a;
    int m=b;
    short count1=0;
    short count2=0;
    while(n) {
        n = n/10;
        count1++;
    }
    n=a;
    while(m) {
        m = m/10;
        count2++;
    }
    m=b;
    short count = count1<=count2 ? count1:count2;
    short i;
    for(i=1;i<=count;i++) {
        n = n/raise(count1-i);
        m = m/raise(count2-i);
        if(n%10 > m % 10) {
            return true;
        }
        else if(n%10 == m % 10) {
            n=a;
            m=b;
        }
        else {
            return false;
        }
    }
    if(count1<count2) {
        n = n/raise(count1-1);
        m = m/raise(count2-i);
        if(n%10 > m%10) return true;
        else if((n%10 == m&10) && (count1==1 && count2==3)) {
            n=a; m=b;
            if(n%10 >= m%10) return true;
            else return false;
        } else if(n%10 == m%10) return true;
        else return false;
    } else if(count1>count2) {
        m = m/raise(count2-1);
        n = n/raise(count1-i);
        if(n%10 > m%10) return true;
        else if((n%10 == m&10) && (count1==3 && count2==1)) {
            n=a; m=b;
            if(n%10 >= m%10) return true;
            else return false;
        } else if(n%10 == m%10) return true;
        else return false;
    }
    return true;
}

void maxNumber (std::vector<int>& v) {
    std::vector<int> u;
    int maxdigit;
    int digit;
    while(!v.empty()) {
        maxdigit = v[0];
        for(int i=1;i<v.size();i++) {
            if(isGreaterOrEqual(v[i],maxdigit)) {
                maxdigit = v[i];
            }
        }
        u.push_back(maxdigit);
        for(int i=0;i<v.size();i++) {
            if(v[i]==maxdigit) {
                v.erase(v.begin()+i); break;
            }
        }
    }
    for(int i=0;i<u.size();i++) {
        std::cout<<u[i];
    }
    std::cout<<std::endl;
}

int main() {
    short n;
    std::cin>>n;
    std::vector<int> v;
    int input;
    for(int i=0;i<n;i++) {
        std::cin>>input;
        v.push_back(input);
    }
    maxNumber(v);
    // std::cout<<isGreaterOrEqual(21,0);
    return 0;
}