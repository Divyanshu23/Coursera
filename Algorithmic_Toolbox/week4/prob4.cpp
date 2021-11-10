#include <iostream>
#include <vector>

using namespace std;

int mergeSort(vector<int>& v,int l,int r);
int merge(vector<int>& v,int l,int m,int r,int count1,int count2);

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
    cout<<mergeSort(v,0,n-1);
    // for(int i=0;i<n;i++) {
    //     cout<<v[i]<<" ";
    // }
    cout<<endl;
    return 0;
}

int merge(vector<int>& v,int l,int m,int r,int count1,int count2) {
    vector<int> v1,v2;
    int n1,n2;
    n1 = m-l+1;
    n2 = r-m;
    int input;
    int count=count1+count2;
    for(int i=l;i<=m;i++) {
        input = v[i];
        v1.push_back(input);
    }
    for(int i=m+1;i<=r;i++) {
        input = v[i];
        v2.push_back(input);
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2) {
        if(v2[j]<v1[i]) {
            count = count+(v1.size()-i);
            // if(j==(n2-1) || j==n) {
            //     for(int l=i+1;l<n1;l++) {
            //         if(v2[j]<v1[l]) count++;
            //     }
            // }
            v[k] = v2[j];
            j++;
        }else {
            // for(int l=i+1;l<n1;l++) {
            //     if(v2[j]<v1[l]) count++;
            // }
            v[k] = v1[i];
            i++;
        }
        k++;
        
    }
    while(i<n1) {
        v[k] = v1[i];
        i++;
        k++;
    }
    while(j<n2) {
        v[k] = v2[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(vector<int>& v,int l,int r) {
    if(r<=l) return 0;
    int m = l+(r-l)/2;
    int count1 = mergeSort(v,l,m);
    int count2 = mergeSort(v,m+1,r);
    return merge(v,l,m,r,count1,count2);
}