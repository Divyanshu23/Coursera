#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin>>n;
    std::vector<int> vect;
    int count=1;
    while(n) {
        if(n-count<0) {
            vect.pop_back();
            vect.push_back(n+count-1);
            n=0;
            continue;
        }
        n-=count;
        vect.push_back(count);
        count++;
    }
    std::cout<<count-1<<std::endl;
    for(int i=0;i<vect.size();i++) {
        std::cout<<vect[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}