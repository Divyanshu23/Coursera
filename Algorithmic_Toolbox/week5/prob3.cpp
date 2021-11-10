#include <iostream>
#include <vector>

int editDistance(std::string a,std::string b);
int min(int a,int b,int c) {
    int min = a<=b?a:b;
    return min<=c?min:c;
}

int main() {
    std::string a;
    std::string b;
    std::cin>>a;
    std::cin>>b;
    std::cout<<editDistance(a,b);
}

int editDistance(std::string a,std::string b) {
    int m = a.length();
    int n = b.length();
    bool flag=0;
    std::vector<std::vector<int> > v(m+1,std::vector<int>(n+1));
    for(int i=0;i<=n;i++) {
        v[0][i] = i;
    }
    for(int i=0;i<=m;i++) {
        v[i][0] = i;
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i-1]==b[j-1]) {
                v[i][j] = min(v[i-1][j]+1,v[i][j-1]+1,v[i-1][j-1]);
            }
            else {
                v[i][j] = min(v[i-1][j]+1,v[i][j-1]+1,v[i-1][j-1]+1);
            }
        }
    }
    return v[m][n];
}