class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> st;

        int i = 0;
        int n = word.size();

        while (i < n) {
            if (isdigit(word[i])) {
                string num = "";

                while (i < n && isdigit(word[i])) {
                    num += word[i];
                    i++;
                }

                int pos = num.find_first_not_of('0');

                if (pos == string::npos)
                    num = "0";
                else
                    num = num.substr(pos);

                st.insert(num);
            }
            else {
                i++;
            }
        }

        return st.size();
    }
};