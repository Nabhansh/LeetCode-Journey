class Solution {
public:
    string longestNiceSubstring(string s) 
    {
        if(s.size() < 2)           //Base Case
        {
            return "";
        }
        unordered_set<char> st(s.begin(),s.end());    //Pehle ek set me daaldo puri string ko

        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            if(st.count(tolower(c)) && st.count(toupper(c)))     //phhir count krlo agar lower and upper hai toh
            {
                continue;                                        //continue mtlb shi chal rha hai 
            }
            string left = longestNiceSubstring(s.substr(0, i));   //Left Substring bnao i-1 tk
            string right = longestNiceSubstring(s.substr(i+1));   //Right Substring bnao i+1 se end tk

            return (left.size() >= right.size()) ? left : right;  //Size Comparison
        }
        return s;        //Return String
    }  
};