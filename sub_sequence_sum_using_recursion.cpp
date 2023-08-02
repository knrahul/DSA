//subsequences with sum k
#include<bits/stdc++.h>
using namespace std;
void sub(int index,vector<int>& ds,int arr[],int n,int sum,int target)
{
    if(index>=n)
    {
        if(sum==target)
        {
         for(auto it:ds)
         {
             cout<<it<<" ";
         }
        cout<<endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    sum+=arr[index];
    sub(index+1,ds,arr,n,sum,target);
    ds.pop_back();
    sum-=arr[index];
    sub(index+1,ds,arr,n,sum,target);
}
int main()
{
    int arr[]={3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> ds;
    int target=3;
    sub(0,ds,arr,n,0,target);
    return 0;
}