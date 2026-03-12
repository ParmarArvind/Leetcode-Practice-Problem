class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tank=0;
        int start=0;
        int count=0;
        
        int i=0;
        while(i<2*n)
        {
            tank += gas[i%n]-cost[i%n];
            count++;

            if(tank<0 )
            {
                tank=0;
                start=(i+1)%n;
                count=0;;
            } 
            if(count ==n ) return start;

            i++;
        }

        
        return -1;

    }
};
