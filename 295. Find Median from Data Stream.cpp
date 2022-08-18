class MedianFinder {
public:
    
    priority_queue<int> leftHalf;
    priority_queue<int,vector<int>, greater<int>> rightHalf;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        
        if(leftHalf.size()==0){
            leftHalf.push(num);
            return;
        }
        
        if(leftHalf.size()==rightHalf.size()){
            if(num>leftHalf.top()){
                int temp = rightHalf.top();
                rightHalf.top();
                rightHalf.push(num);
                leftHalf.push(temp);
            }
            else{
                leftHalf.push(num);
            }
            // if(num <= rightHalf.top()){
            //     leftHalf.push(num);
            // }else{
            //     int rightMin = rightHalf.top(); //10
            //     rightHalf.pop();
            //     leftHalf.push(rightMin);
            //     rightHalf.push(num);
            // }
            return;
        }
        else{
            if(num>leftHalf.top()){
                rightHalf.push(num);
            }
            else{
                int temp = leftHalf.top();
                leftHalf.pop();
                rightHalf.push(temp);
                leftHalf.push(num);
            }
            return;
        }
        
    }
    
    double findMedian() {
        if(leftHalf.size()==rightHalf.size()){
            return (leftHalf.top()+rightHalf.top())/2.0;
        }
        else{
            return leftHalf.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */