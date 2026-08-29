class Solution {
public:

    void backtrack(
        std::string& currentString,
        int n,
        int cost,
        int k,
        std::vector<std::string>& ans
    ){  

        if(currentString.length()>n) return;

        if(currentString.length()==n){
            ans.push_back(currentString);
            return;
        }

        if(currentString.length()==0){
            currentString+='0';
            backtrack(currentString,n,cost,k,ans);
            currentString.pop_back();

            cost+=currentString.length();
            if(cost>k) return;
            currentString+='1';
            backtrack(currentString,n,cost,k,ans);
            currentString.pop_back();
        }else{
            currentString+='0';
            backtrack(currentString,n,cost,k,ans);
            currentString.pop_back();

            if(currentString.back()=='1') return;

            cost+=currentString.length();
            if(cost>k) return;
            currentString+='1';
            backtrack(currentString,n,cost,k,ans);
            currentString.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        std::string tempString="";
        std::vector<std::string> ans;
        backtrack(tempString,n,0,k,ans);
        return ans;
    }
};