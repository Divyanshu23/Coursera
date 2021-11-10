#include <iostream>
#include <vector>

// void mergeSort(int** ptr,short l,short r);
// void merge(int** ptr,short l,short m,short r);

short minElement(std::vector<std::vector<int> >& vect) {
    short index=0;
    for(auto i=1;i<vect[0].size();i++) {
        if(vect[0][i]<=vect[0][index]) index=i;
        }
    return index;
}

void minPoints(std::vector<std::vector<int> >& vect) {
    short points=0;
    short index;
    int a,b,c;
    index = minElement(vect);
    a = vect[0][index];
    b= vect[1][index];
    vect[0].erase(vect[0].begin()+index);
    vect[1].erase(vect[1].begin()+index);
    std::vector<int> vect_points;
    while(!vect[0].empty()) {
        index = minElement(vect);
        c = vect[0][index];
        if(a==c) {
            if(vect[1][index]<=b) b = vect[1][index];
            vect[0].erase(vect[0].begin()+index);
            vect[1].erase(vect[1].begin()+index);
            continue;
        }
        if (a<=c && c<=b) {
            a=c;
            if(vect[1][index]<=b) b = vect[1][index];
            vect[0].erase(vect[0].begin()+index);
            vect[1].erase(vect[1].begin()+index);
        }
        else {
            points+=1;
            vect_points.push_back(a);
            index = minElement(vect);
            a = vect[0][index];
            b= vect[1][index];
            vect[0].erase(vect[0].begin()+index);
            vect[1].erase(vect[1].begin()+index);
        }
    }
    points+=1;
    vect_points.push_back(a);
    std::cout<<points<<std::endl;
    for(auto i=vect_points.begin();i<vect_points.end();i++) {
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
}

int main() {
    short n;
    std::cin>>n;
    std::vector<std::vector<int> > vect;
    std::vector<int> v1;
    std::vector<int> v2;
    int input1,input2;

    for(short i=0;i<n;i++) {
        std::cin>>input1>>input2;
        v1.push_back(input1);
        v2.push_back(input2);
    }
    vect.push_back(v1);
    vect.push_back(v2);

    minPoints(vect);
    return 0;
}