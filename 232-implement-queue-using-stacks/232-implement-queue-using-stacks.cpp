class MyQueue {
public:
    
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        s2.push(x);
      
    }
    
    int pop() {
         while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }            
        int val=s1.top();
        s1.pop();
         while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return val;
        
    }
    
    int peek() {
        
         while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        } 
        int val=s1.top();
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        return val;
    }
    
    bool empty() {
        return s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */