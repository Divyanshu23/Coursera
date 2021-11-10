#include <iostream>
#include <vector>

using namespace std;

long discreteKnapsack(vector<int>& v1,int W);

int main() {
    int W;
    int n;
    cin>>W;
    cin>>n;
    vector<int> v1(n);
    for(int i=0;i<n;i++) {
        cin>>v1[i];
    }
    cout<<discreteKnapsack(v1,W)<<"\n";
}

long discreteKnapsack(vector<int>& v1,int W) {
    long a,b;
    vector<vector<long> > v2(v1.size()+1,vector<long>(W+1));
    vector<int> v3(v1.size());

    for(int i=0;i<=W;i++) {
        v2[0][i] = 0;
    }
    for(int i=0;i<=v1.size();i++) {
        v2[i][0] = 0;
    }
    for(int i=1;i<=v1.size();i++) {
        for(int j=1;j<=W;j++) {
            if(j>=v1[i-1]) {
                a = v2[i-1][j-v1[i-1]] + v1[i-1];
                b = v2[i-1][j];
                v2[i][j] = a>=b?a:b;
            } else {
                v2[i][j] = v2[i-1][j];
            }
        }
    }
    // int k=v3.size()-1;
    // int i=v1.size();
    // int j=W;
    // while(i>=1 && j>=1) {
    //         if(j>=v1[i-1]) {
    //             if(v2[i][j]==(v2[i-1][j-v1[i-1]]+v1[i-1])) {
    //                 v3[k] = 1;
    //                 k--;
    //                 j = j-v1[i-1];
    //                 i=i-1;
    //             } else {
    //                 v3[k] = 0;
    //                 k--;
    //                 i=i-1;
    //             }
    //         } else {
    //             v3[k] = 0;
    //             k--;
    //             i=i-1;
    //         }
    // }
    // for(int i=0;i<v3.size();i++) {
    //     cout<<v3[i]<<" ";
    // }
    // cout<<"\n";
    return v2[v1.size()][W];
}