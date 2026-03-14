class MedianFinder {
    int size=0;
    priority_queue<int,vector<int> ,greater<int>>rightMinPQ ; //min heap
    priority_queue<int,vector<int>> leftMaxPQ; //max heap
public:
    
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        size++;
        if(leftMaxPQ.empty() || num<leftMaxPQ.top()) leftMaxPQ.push(num);
        else rightMinPQ.push(num);

        if(leftMaxPQ.size() > rightMinPQ.size()+1 ) 
        {
            rightMinPQ.push(leftMaxPQ.top());
            leftMaxPQ.pop();
        }
        else if(leftMaxPQ.size() < rightMinPQ.size())
        {
            leftMaxPQ.push(rightMinPQ.top());
            rightMinPQ.pop();
        }
    }
    
    double findMedian() {
        if(size %2==0)//size/2 mid and (size-1) /2
        {
            return (leftMaxPQ.top() + rightMinPQ.top() )/2.0;
        }
        return (double)(leftMaxPQ.top()+0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
