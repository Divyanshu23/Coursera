#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void randomizedQuicksort(vector<int>& v,int l,int r);
vector<int> partition3(vector<int>& v,int l,int r);
bool partition(vector<int>& v1,int sum);

int main() {
    int n;
    cin>>n;
    vector<int> v1(n);
    int sum=0;
    for(int i=0;i<n;i++) {
        cin>>v1[i];
        sum += v1[i];
    }
    randomizedQuicksort(v1,0,n-1);
    cout<<partition(v1,sum);
}

void randomizedQuicksort(vector<int>& v,int l,int r) {
    if(r<=l) return;
    int m = l + (rand()%(r-l+1));
    swap(v[l],v[m]);
    vector<int> v1 = partition3(v,l,r);
    randomizedQuicksort(v,l,v1[0]-1);
    randomizedQuicksort(v,v1[1]+1,r);
}

vector<int> partition3(vector<int>& v,int l,int r) {
    int m = v[l];
    int i,j,k;
    k=l;
    j=l-1;
    for(i=l+1;i<=r;i++) {
        if(v[i]==m) {
            ++k;
            swap(v[k],v[i]);
        }
        else if(v[i]<m) {
                v.insert(v.begin()+(j+1),v[i]);
                v.erase(v.begin()+(i+1));
                j++;
                k++;
        }
    }
    vector<int> v1;
    v1.push_back(j+1);
    v1.push_back(k);
    return v1;
}

bool partition(vector<int>& v1,int sum) {
    if(sum%3!=0) return false;
    sum = sum/3;
    int a,b;
    vector<vector<int> > v2(v1.size()+1,vector<int>(sum+1));

    for(int i=0;i<=sum;i++) {
        v2[0][i] = 0;
    }
    for(int i=0;i<=v1.size();i++) {
        v2[i][0] = 0;
    }

    do {
        for(int i=1;i<=v1.size();i++) {
            for(int j=1;j<=sum;j++) {
                if(j>=v1[i-1]) {
                    a = v2[i-1][j-v1[i-1]] + v1[i-1];
                    b = v2[i-1][j];
                    v2[i][j] = a>=b?a:b;
                } else {
                    v2[i][j] = v2[i-1][j];
                }
            }
        }
        if(v2[v1.size()][sum]!=sum) return false;

        vector<int> v3;
        int i=v1.size();
        int j=sum;
        while(i>=0 && j>=0) {
            if(i==0) break;
            if(j==0) {
                for(auto it=v1.begin()+(i-1);it>=v1.begin();it--) {
                    v3.insert(v3.begin(),*it);
                }
                break;
            } 
            if(j>=v1[i-1]) {
                if(v2[i][j]==(v2[i-1][j-v1[i-1]]+v1[i-1])) {
                    j = j-v1[i-1];
                    i=i-1;
                } else {
                    v3.insert(v3.begin(),v1[i-1]);
                    i=i-1;
                }
            } else {
                v3.insert(v3.begin(),v1[i-1]);
                i=i-1;
            }
        }

        vector<vector<int> > v4(v3.size()+1,vector<int>(sum+1));
        for(int i=0;i<=sum;i++) {
            v4[0][i] = 0;
        }
        for(int i=0;i<=v3.size();i++) {
            v4[i][0] = 0;
        }
        for(int i=1;i<=v3.size();i++) {
            for(int j=1;j<=sum;j++) {
                if(j>=v3[i-1]) {
                    a = v4[i-1][j-v3[i-1]] + v3[i-1];
                    b = v4[i-1][j];
                    v4[i][j] = a>=b?a:b;
                } else {
                    v4[i][j] = v4[i-1][j];
                }
            }
        }
        if(v2[v1.size()][sum]==v4[v3.size()][sum]) return true;
        else continue;
    } while(next_permutation(v1.begin(),v1.end()));
    return false;
}