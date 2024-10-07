#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>

int lower_bound(vector<int> arr, int key){
    int low=0, high=arr.size()-1;
    int res=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid] >= key){
            res=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return res;
}

int main()
{
    vector<int> arr={1,3,5,8,10};
    int ans=lower_bound(arr, 9);
    cout << ans << endl;
}
