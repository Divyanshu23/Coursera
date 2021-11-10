#include <iostream>
#include <vector>
#include<cstdlib>

using namespace std;

void randomizedQuicksort(vector<int>& v,int l,int r);
vector<int> partition3(vector<int>& v,int l,int r);

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int input;
    for(int i=0;i<n;i++) {
        cin>>input;
        v.push_back(input);
    }
    randomizedQuicksort(v,0,n-1);
    for(int i =0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
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