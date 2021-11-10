#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void randomizedQuicksort(vector<vector<int> >& v1,int l,int r);
vector<int> partition3(vector<vector<int> >& v1,int l,int r);
void fSegment(vector<vector<int> >&v1,vector<int>& v2);
int bSearch(std::vector<int>& v1,int key,int l,int r);

int main()
{
    int s,p;
    int input;
    cin>>s>>p;
    vector<vector<int> > v1(2);
    vector<int> v2;
    for(int j=0;j<s;j++) {
            cin>>input;
            v1[0].push_back(input);
            v1[1].push_back(1);
            cin>>input;
            v1[0].push_back(input);
            v1[1].push_back(3);
    }
    for(int i=2*s;i<(2*s+p);i++) {
        cin>>input;
        v1[0].push_back(input);
        v1[1].push_back(2);
        v2.push_back(input);
    }
    // for(int i=0;i<v1[0].size();i++) {
    //        cout<<"( "<<v1[0][i]<<","<<v1[1][i]<<" )"<<" , ";
    // }
    // cout<<endl;
    // randomizedQuicksort(v1,0,v1[0].size()-1);
    // for(int i=0;i<v1[0].size();i++) {
    //        cout<<"( "<<v1[0][i]<<","<<v1[1][i]<<" )"<<" , ";
    // }
    // cout<<endl;
    fSegment(v1,v2);
}

int bSearch(std::vector<int>& v1,int key,int l,int r) {
    if(r<l) return -1;
    int m = l + (r-l)/2;
    if(v1[m]==key) return m;
    else if(v1[m]<key) return bSearch(v1,key,m+1,r);
    else return bSearch(v1,key,l,m-1);
}

void randomizedQuicksort(vector<vector<int> >& v1,int l,int r) {
    if(r<=l) return;
    int m = l + (rand()%(r-l+1));
    swap(v1[0][l],v1[0][m]);
    swap(v1[1][l],v1[1][m]);
    vector<int> v2 = partition3(v1,l,r);
    randomizedQuicksort(v1,l,v2[0]-1);
    randomizedQuicksort(v1,v2[1]+1,r);
}

vector<int> partition3(vector<vector<int> >& v,int l,int r) {
    int m = v[0][l];
    int i,j,k;
    k=l;
    j=l-1;
    for(i=l+1;i<=r;i++) {
        if(v[0][i]==m) {
            ++k;
            swap(v[0][k],v[0][i]);
            swap(v[1][k],v[1][i]);
        }
        else if(v[0][i]<m) {
                v[0].insert(v[0].begin()+(j+1),v[0][i]);
                v[0].erase(v[0].begin()+(i+1));
                v[1].insert(v[1].begin()+(j+1),v[1][i]);
                v[1].erase(v[1].begin()+(i+1));
                j++;
                k++;
        }
    }
    vector<int> v1;
    v1.push_back(j+1);
    v1.push_back(k);
    return v1;
}

void fSegment(vector<vector<int> >& v1,vector<int>& v2) {
    int index;
    int count1,count2;
    std::vector<int>::iterator it;
    randomizedQuicksort(v1,0,v1[0].size()-1);
    std::vector<int> v3;
    for(int i=0;i<v2.size();i++) {
        it = std::find(v1[0].begin(),v1[0].end(),v2[i]);
        index = std::distance(v1[0].begin(),it);
        count1 = std::count(v1[1].begin(),v1[1].begin()+index,1);
        count2 = std::count(v1[1].begin(),v1[1].begin()+index,3);
        v3.push_back(count1-count2);
    }
    for(int i=0;i<v3.size();i++) {
        std::cout<<v3[i]<<" ";
    }
    std::cout<<"\n";
}