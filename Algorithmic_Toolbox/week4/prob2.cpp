#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int> > getMajor(std::vector<int>& v,int l,int r);
std::vector<std::vector<int> > mergeResult(std::vector<std::vector<int> >& v1,
                                            std::vector<std::vector<int> >& v2);

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> v;
    int input;
    for(int i=0;i<n;i++) {
        std::cin>>input;
        v.push_back(input);
    }
    
    std::vector<std::vector<int> > v1;
    v1 = getMajor(v,0,n-1);
    if(v1[0].size()>(n/2)) {
        std::cout<<1;
    }
    else std::cout<<0;
    return 0;
}

std::vector<std::vector<int> > getMajor(std::vector<int>& v,int l,int r) {
    if((r-l)==0) {
        std::vector<std::vector<int> > v2(2);
        v2[0].push_back(v[l]);
        v2[1].clear();
        return v2;
    }
    int m = l + (r-l)/2;
    std::vector<std::vector<int> > v3,v4;
    v3 = getMajor(v,l,m);
    v4 = getMajor(v,m+1,r);
    return mergeResult(v3,v4);
}

std::vector<std::vector<int> > mergeResult(std::vector<std::vector<int> >& v1,std::vector<std::vector<int> >& v2) {
    std::vector<int>::iterator it = std::find(v2[1].begin(),v2[1].end(),v1[0][0]);
    while(it!=v2[1].end()){
        it = std::find(v2[1].begin(),v2[1].end(),v1[0][0]);
        if(it!=v2[1].end()) {
            v1[0].push_back(*it);
            v2[1].erase(it);
        }
    }
    it = std::find(v1[1].begin(),v1[1].end(),v2[0][0]);
    while(it!=v1[1].end()){
        it = std::find(v1[1].begin(),v1[1].end(),v2[0][0]);
        if(it!=v1[1].end()) {
            v2[0].push_back(*it);
            v1[1].erase(it);
        }
    }

    if(v1[0][0]==v2[0][0]) {
        v1[0].insert(v1[0].end(),v2[0].begin(),v2[0].end());
        v1[1].insert(v1[1].end(),v2[1].begin(),v2[1].end());
        return v1;
    }else if(v1[0].size()==v2[0].size()){
        v1[1].insert(v1[1].end(),v2[0].begin(),v2[0].end());
        v1[1].insert(v1[1].end(),v2[1].begin(),v2[1].end());
        return v1;
    }
    else if(v1[0].size()>v2[0].size()) {
        v1[1].insert(v1[1].end(),v2[0].begin(),v2[0].end());
        v1[1].insert(v1[1].end(),v2[1].begin(),v2[1].end());
        return v1;
    }
    else {
        v2[1].insert(v2[1].end(),v1[0].begin(),v1[0].end());
        v2[1].insert(v2[1].end(),v1[1].begin(),v1[1].end());
        return v2;
    }
}