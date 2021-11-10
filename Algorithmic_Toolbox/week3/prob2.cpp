#include <iostream>
#include <iomanip>

double largestLoot(int ptr[][3], int W,int n);
int max(int ptr[][3],int n) {
	int index=0;
	for(int i=index;i<(n-1);i++) {
		if(ptr[i+1][1]>0) {
			if(((float)ptr[i+1][0])/ptr[i+1][1] > ((float)ptr[index][0])/ptr[index][1]) {
				index = i+1;
			}
		}
	}
	return index;
}

int main() {
    int n,W;
    std::cin>>n>>W;
    int arr1[n][3];

    for(int i=0;i<n;i++) {
        std::cin>>arr1[i][0]>>arr1[i][1];
	}

	std::cout<<std::fixed<<std::setprecision(4);
	std::cout<<largestLoot(arr1,W,n);
    return 0;
}

double largestLoot(int ptr[][3], int W,int n) {

	double value=0;
	int index;

	for(int i=0;i<n;i++) {
		if(W==0) {
			return value;
		}
		index = max(ptr,n);
		if(W>ptr[index][1]) {
			value += ptr[index][0];
			W -= ptr[index][1];
			ptr[index][1] = 0;
		} 
		else {
			value += (((float)ptr[index][0])/ptr[index][1])*W;
			W = 0;
			ptr[index][1] -= W;
		}
	}
	return value;
}