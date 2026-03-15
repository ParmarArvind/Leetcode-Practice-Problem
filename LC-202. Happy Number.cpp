class Solution {
public:
    unordered_set<int> st;
    bool solve(int n)
    {
        if(n==1) return true;
        
        if(st.find(n) !=st.end()) return false;

        st.insert(n);
        int num=0;
        while(n)
        {
            int rem=n%10;
            n /=10;
            num += rem*rem;
            
        }
        return solve(num);

    }
    bool isHappy(int n) {
        
      
        return solve(n);
        
        
    }
};
