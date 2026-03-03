// method-1 O(n*k)    TLE
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
         // rotate array by k times
         
         int n= arr.size();
         if(n==1) return;
         k=k%n;
         if(k<=n/2)
         {
             while(k--)
            {
                int last=arr[n-1];
                for(int i=n-1;i>0;i--)
                {
                    arr[i]=arr[i-1];
                }
                arr[0]=last;
            }
         }

        // we rotate array n-k time right that is exactly same as k time left rotation
         else 
         {
            k=n-k;
             while(k--)
            {
                int first=arr[0];
                for(int i=0; i<n-1;i++)
                {
                    arr[i]=arr[i+1];
                }
                arr[n-1]=first;
            }
         }
    }
};


// method -2 O(n) 
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
       
        k= k% arr.size();
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
        
    }
};
