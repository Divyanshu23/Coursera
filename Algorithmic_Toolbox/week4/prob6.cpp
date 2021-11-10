#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>

using namespace std;

double Min(double a,double b) {
    return a<=b?a:b;
}
void randomizedQuicksort_X(vector<vector<int> >& v1,int l,int r);
void randomizedQuicksort_Y(vector<vector<int> >& v1,int l,int r);
vector<int> partition3_X(vector<vector<int> >& v1,int l,int r);
vector<int> partition3_Y(vector<vector<int> >& v1,int l,int r);
double minDistace(vector<vector<int> >& v,vector<vector<int> >& v2,int l,int r);
int bSearch(std::vector<int>& v1,int key,int l,int r);
double minInDeltaStrip(vector<vector<int> >& v3,int l,int r,double d1);

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v1(2,vector<int>(n));
    for(int i=0;i<n;i++) {
        cin>>v1[0][i];
        cin>>v1[1][i];
    }
    vector<vector<int> > v2(v1);
    randomizedQuicksort_X(v1,0,n-1);
    randomizedQuicksort_Y(v2,0,n-1);

    double d = minDistace(v1,v2,0,n-1);
    printf("%lf\n",d);
}

void randomizedQuicksort_X(vector<vector<int> >& v1,int l,int r) {
    if(r<=l) return;
    int m = l + (rand()%(r-l+1));
    swap(v1[0][l],v1[0][m]);
    swap(v1[1][l],v1[1][m]);
    vector<int> v2 = partition3_X(v1,l,r);
    randomizedQuicksort_X(v1,l,v2[0]-1);
    randomizedQuicksort_X(v1,v2[1]+1,r);
}

vector<int> partition3_X(vector<vector<int> >& v,int l,int r) {
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

void randomizedQuicksort_Y(vector<vector<int> >& v1,int l,int r) {
    if(r<=l) return;
    int m = l + (rand()%(r-l+1));
    swap(v1[1][l],v1[1][m]);
    swap(v1[0][l],v1[0][m]);
    vector<int> v2 = partition3_Y(v1,l,r);
    randomizedQuicksort_Y(v1,l,v2[0]-1);
    randomizedQuicksort_Y(v1,v2[1]+1,r);
}

vector<int> partition3_Y(vector<vector<int> >& v,int l,int r) {
    int m = v[1][l];
    int i,j,k;
    k=l;
    j=l-1;
    for(i=l+1;i<=r;i++) {
        if(v[1][i]==m) {
            ++k;
            swap(v[1][k],v[1][i]);
            swap(v[0][k],v[0][i]);
        }
        else if(v[1][i]<m) {
                v[1].insert(v[1].begin()+(j+1),v[1][i]);
                v[1].erase(v[1].begin()+(i+1));
                v[0].insert(v[0].begin()+(j+1),v[0][i]);
                v[0].erase(v[0].begin()+(i+1));
                j++;
                k++;
        }
    }
    vector<int> v1;
    v1.push_back(j+1);
    v1.push_back(k);
    return v1;
}

int bSearch(std::vector<int>& v1,int key,int l,int r) {
    if(r<l) return l-1;
    int m = l + (r-l)/2;
    if(v1[m]==key) return m;
    else if(v1[m]<key) return bSearch(v1,key,m+1,r);
    else return bSearch(v1,key,l,m-1);
}

double minDistace(vector<vector<int> >& v,vector<vector<int> >& v2,int l,int r) {
    if((r-l)<=2) {
        if(r-l==2) {
            double d1 = (double)sqrt((v[0][l]-v[0][l+1])*(v[0][l]-v[0][l+1]) + (v[1][l]-v[1][l+1])*(v[1][l]-v[1][l+1]));
            double d2 = (double)sqrt((v[0][l+1]-v[0][r])*(v[0][l+1]-v[0][r]) + (v[1][l+1]-v[1][r])*(v[1][l+1]-v[1][r]));
            d1 = Min(d1,d2);
            d2 = (double)sqrt((v[0][l]-v[0][r])*(v[0][l]-v[0][r]) + (v[1][l]-v[1][r])*(v[1][l]-v[1][r]));
            return Min(d1,d2); 
            } else {
                return (double)sqrt((v[0][l]-v[0][r])*(v[0][l]-v[0][r]) + (v[1][l]-v[1][r])*(v[1][l]-v[1][r]));
            }
    }

    int m = l+(r-l)/2;
    double d1 = minDistace(v,v2,l,m);
    double d2 = minDistace(v,v2,m,r);
    d1 = Min(d1,d2);

    int l1 = bSearch(v[0],v[0][m]-d1,l,m);
    int r1 = bSearch(v[0],v[0][m]+d1,m,r);
    if((l1<=l && r1>=r) || l1==r1) return d1;

    vector<vector<int> > v3(2);
    for(int i=0;i<=v2[0].size();i++) {
        if(v2[0][i]>=v[0][l1] && v2[0][i]<=v[0][r1]) {
            v3[0].push_back(v2[0][i]);
            v3[1].push_back(v2[1][i]);
        }
    }
    return minInDeltaStrip(v3,0,v3.size()-1,d1);
}

double minInDeltaStrip(vector<vector<int> >& v3,int l,int r,double d1) {
    double d2;
    for(int i=l;i<=r;i++) {
        for(int j=i+1;(j<=i+1 && j<=r);j++) {
            d2 = sqrt((v3[0][i]-v3[0][j])*(v3[0][i]-v3[0][j]) + (v3[1][i]-v3[1][j])*(v3[1][i]-v3[1][j]));
            if(d2<=d1) d1 = d2;
        }
    }
    return d1;
}