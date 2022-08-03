class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       
        stack<int> s;
        int op1,op2,res=0;
        for(string token:tokens){
            
            if(token=="+" && !s.empty()){
                
                op2=s.top();
                s.pop();
                op1=s.top();
                s.pop();
                res=op1+op2;
                s.push(res);
            } else if(token=="-" && !s.empty()){
                
                op2=s.top();
                s.pop();
                op1=s.top();
                s.pop();
                res=op1-op2;
                s.push(res);
            } else if(token=="*" && !s.empty()){
                
                op2=s.top();
                s.pop();
                op1=s.top();
                s.pop();
                res=op1*op2;
                s.push(res);
            } else if(token=="/" && !s.empty()){
                
                op2=s.top();
                s.pop();
                op1=s.top();
                s.pop();
                res=op1/op2;
                s.push(res);
            } else{
                
                int tokenInt=stoi(token);
                s.push(tokenInt);
            }
            
            
            
        }
        
        return s.top();
    }
};