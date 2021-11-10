#include <iostream>
#include <vector>

int longestCommonSubseq(std::vector<int>& a,std::vector<int>& b,int m,int n);
int min(int a,int b,int c) {
    int min = a<=b?a:b;
    return min<=c?min:c;
}
int min2(int a,int b) {
    return a<=b?a:b;
}

// remember that longest commmon subseq is a special case of edit disatnce problem where we allow
// insertions and deletions only

int main() {
    int m,n,input;
    std::cin>>m;
    std::vector<int> a(m);
    for(int i=0;i<m;i++) {
        std::cin>>input;
        a[i]=input;
    }
    std::cin>>n;
    std::vector<int> b(n);
    for(int i=0;i<n;i++) {
        std::cin>>input;
        b[i]=input;
    }
    std::cout<<longestCommonSubseq(a,b,m,n);
}

int longestCommonSubseq(std::vector<int>& a,std::vector<int>& b,int m,int n) {
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
                v[i][j] = min2(v[i-1][j]+1,v[i][j-1]+1);
            }
        }
    }
    // for(int i=0;i<=m;i++) {
    //     for(int j=0;j<=n;j++) {
    //         std::cout<<v[i][j]<<" ";
    //     }
    //     std::cout<<"\n";
    // }
    return ((m+n)-v[m][n])/2;
}