class Solution {
public:
    string decodeString(string s) {
        stack<int> count;
        stack<string> str;

        string currStr = "" ;
        int currNum = 0;

        for(char c : s){
            if(isdigit(c)){
                currNum = currNum*10 + (c-'0') ;
            }
            else if(c == '['){
                count.push(currNum);
                str.push(currStr);

                currNum = 0;
                currStr = "";
            }
            else if(c == ']'){
                int repeat = count.top();
                count.pop();

                string decodePre = str.top();
                str.pop();

                for(int i = 0; i <repeat ; i++){
                    decodePre += currStr ;
                }

                currStr = decodePre;
            }
            else{
                currStr += c;
            }
        }
        return currStr ;
    }
};