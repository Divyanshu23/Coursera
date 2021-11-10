#include <iostream>
#include <vector>

using namespace std;

void mergeSort(std::vector<int>& v,int l,int r);
void merge(std::vector<int> &v,int l,int m,int r);
int max(std::vector<int>& v2,bool t);
long long product(std::vector<int>& v1,std::vector<int>& v2);

int main() {
    int n;
    std::cin>>n;
    std::vector<int> v1(n);
    std::vector<int> v2(n);
    for(int i=0;i<n;i++) {
        std::cin>>v1[i];
    }

    for(int i=0;i<n;i++) {
        std::cin>>v2[i];
    }
    mergeSort(v1,0,n-1);
    mergeSort(v2,0,n-1);
    std::cout<<product(v1,v2);
}

void mergeSort(std::vector<int>& v, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(v, l, m); 
        mergeSort(v, m+1, r); 
  
        merge(v, l, m, r); 
    } 
}

void merge(std::vector<int>& v, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = v[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = v[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] >= R[j]) 
        { 
            v[k] = L[i]; 
            i++; 
        } 
        else
        { 
            v[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        v[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        v[k] = R[j]; 
        j++; 
        k++; 
    } 
}

int max(std::vector<int>& v2,bool t) {
    int value;
    if(t) {
        value = v2[0];
        v2.erase(v2.begin());
        return value;
    }
    else{
        value = v2[v2.size()-1];
        v2.erase(v2.end()-1);
        return value;
    }  
}

long long product(std::vector<int>& v1,std::vector<int>& v2) {
    long long Product=0;
    for(int i=0;i<v1.size();i++) {
        if(v1[i]>=0) {
            Product=Product+((long long)v1[i])*max(v2,true);
        }
        else{
            Product=Product+((long long)v1[i])*max(v2,false);
        }
    }
    return Product;
}