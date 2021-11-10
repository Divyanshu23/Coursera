#include <iostream>
#include <vector>

// int max2(int a.int b) {
//     return a>=b?a:b;
// }
int max4(int a,int b,int c,int d) {
    int max1 = a>=b?a:b;
    int max2 = c>=d?c:d;
    return max1>=max2?max1:max2;
}
int lcs3(std::vector<int>& a,std::vector<int>& b,std::vector<int>& c,int m,int n,int l);

int main() {
    int m,n,l;
    std::cin>>m;
    std::vector<int> a(m);
    for(short i=0;i<m;i++) {
        std::cin>>a[i];
    }
    std::cin>>n;
    std::vector<int> b(n);
      for(short i=0;i<n;i++) {
        std::cin>>b[i];
    }
    std::cin>>l;
    std::vector<int> c(l);
      for(short i=0;i<l;i++) {
        std::cin>>c[i];
    }
    std::cout<<lcs3(a,b,c,m,n,l);
}

int lcs3(std::vector<int>& a,std::vector<int>& b,std::vector<int>& c,int m,int n,int l) {
    std::vector<std::vector<std::vector<int> > > arr(m+1,std::vector<std::vector<int> >(n+1,std::vector<int>(l+1,0)));
    for(int i=0;i<=m;i++) {
        arr[i][0][0] = 0;
    }
    for(int i=0;i<=n;i++) {
        arr[0][i][0] = 0;
    }
    for(int i=0;i<=l;i++) {
        arr[0][0][i] = 0;
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=l;k++) {
                if(a[i-1]==b[j-1] && b[j-1]==c[k-1]) {
                    arr[i][j][k] = max4(arr[i-1][j-1][k-1]+1,arr[i][j-1][k],arr[i][j][k-1],arr[i-1][j][k]);
                }
                else {
                    arr[i][j][k] = max4(arr[i-1][j-1][k-1],arr[i][j-1][k],arr[i][j][k-1],arr[i-1][j][k]);
                }
            }
        }
    }
    return arr[m][n][l];
}
