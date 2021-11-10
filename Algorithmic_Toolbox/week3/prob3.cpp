#include <iostream>
#include <vector>

int refills(std::vector<int>& v,int d,int m,int n);

int main() {
    int d,m,n;
	std::cin>>d>>m>>n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++) {
        std::cin>>v[i];
    }
    std::cout<<refills(v,d,m,n);
}

int refills(std::vector<int>& v,int d,int m,int n) {
    int refills=0;
    int curr_stop=-1;
    int fuel=m;
    bool start=true;
    while(true) {
        if(start) {
            if(v[curr_stop+1]<=fuel) {
            fuel = fuel-v[curr_stop+1];
            curr_stop++;
            start=false;
            } else return-1;
        }
        if(curr_stop == n-1) {
            if((d-v[curr_stop])<=fuel) {
                fuel = fuel-(d-v[curr_stop]);
                curr_stop++;
                return refills;
            } else {
                fuel=m;
                if((d-v[curr_stop])<=fuel) {
                    fuel = fuel-(d-v[curr_stop]);
                    curr_stop++;
                    refills++;
                    return refills;
                }else return -1;
            }
        }
        if((v[curr_stop+1]-v[curr_stop])<=fuel) {
            fuel = fuel-(v[curr_stop+1]-v[curr_stop]);
            curr_stop++;
        }
        else {
                fuel=m;
                if((v[curr_stop+1]-v[curr_stop])<=fuel) {
                    fuel = fuel-(v[curr_stop+1]-v[curr_stop]);
                    curr_stop++;
                    refills++;
                }else return -1;
        }
    }
}