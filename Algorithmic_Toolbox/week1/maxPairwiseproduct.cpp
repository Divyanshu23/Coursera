#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
long long max(vector<int> numbers)
{
    int n= numbers.size();
    long long result = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(((long long)numbers[i])*numbers[j]>result)
            {
                result = ((long long)numbers[i])*numbers[j];
            }
        }
    }
    return result;
}

long long max_fast(vector<int> numbers)
{
    int max_index1 = -1;
    int max_index2 = -1;
    int n = numbers.size();
    for(int i=0;i<n;i++)
    {
        if((max_index1==-1) || (numbers[i]>numbers[max_index1]))
        {
            max_index1 = i;
        }
    }
    for(int j=0;j<n;j++)
    {
        if((j!=max_index1) && ((max_index2 == -1) || (numbers[j]>numbers[max_index2])))
        {
            max_index2 = j;
        }
    }
    long long result = ((long long)numbers[max_index1])*numbers[max_index2];
    return result;
}
int main()
{
    while(1)
    {
        int n = (rand()%10) +2;
        cout<<n<<endl;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            int a1 = (rand()%10);
            a.push_back(a1);
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        long long r1 = max_fast(a);
        long long r2 = max(a);
        if(r1=r2)
        {
            cout<<"OK"<<endl;
        }
        else if(r1!=r2)
        {
            cout<<r1<<" "<<r2<<endl;
            cout<<"Wrong"<<endl;
            break;
        }
        
    }
    int n;
    cin >>n;
    vector<int>numbers(n);
    for(int i=0;i<n;i++)
    {
        cin>>numbers[i];
    }
    long long result = max_fast(numbers);
    cout << result << endl;
    return 0;
}