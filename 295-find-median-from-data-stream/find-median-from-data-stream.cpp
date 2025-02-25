class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if(!small.empty() && !large.empty() && small.top()>large.top())
        {
            large.push(small.top());
            small.pop();
        }
        if(small.size()>large.size()+1)
        {
            large.push(small.top());
            small.pop();
        }
        if(large.size()>small.size()+1)
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        double ans;
        if(small.size()>large.size())
        return small.top();
        if(large.size()>small.size())
        return large.top();
        ans=small.top()+large.top();
        ans=ans/2.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */