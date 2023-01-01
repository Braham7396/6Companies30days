
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> b; // value wala stack
        int val;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                string c= tokens[i];
                string op2 = b.top();
                b.pop();
                string op1 = b.top();
                b.pop();
                if(c=="+") 
                    val= stoi(op1)+stoi(op2);
                else if(c=="-") 
                    val= stoi(op1)-stoi(op2);
                else if(c=="*") 
                    val= stoi(op1)*stoi(op2);
                else if(c=="/") 
                    val= stoi(op1)/stoi(op2);
                b.push(to_string(val));   
            }
            else b.push(tokens[i]); 
        }
        return stoi(b.top());    
    }
};
