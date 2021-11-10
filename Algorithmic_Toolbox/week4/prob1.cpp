#include <iostream>
#include <vector>

int bSearch(std::vector<int>& v1,int key,int l,int r);

int main() {
    int n,k;
    int input;
    std::cin>>n;
    std::vector<int> v1;

    for(int i=0;i<n;i++) {
        std::cin>>input;
        v1.push_back(input);
    }
    std::cin>>k;
    std::vector<int> v2;
    for(int i=0;i<k;i++) {
        std::cin>>input;
        v2.push_back(input);
    }
    for(int i=0;i<k;i++) {
        std::cout<<bSearch(v1,v2[i],0,n-1)<<" ";
    }
    std::cout<<"\n";
    return 0;
}

int bSearch(std::vector<int>& v1,int key,int l,int r) {
    if(r<l) return -1;
    int m = l + (r-l)/2;
    if(v1[m]==key) return m;
    else if(v1[m]<key) return bSearch(v1,key,m+1,r);
    else return bSearch(v1,key,l,m-1);
}