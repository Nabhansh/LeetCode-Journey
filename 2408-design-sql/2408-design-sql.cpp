class SQL {
public:
    unordered_map<string,map<int,vector<string>>>data;
    unordered_map<string,int>rowId;
    unordered_map<string,int>colsize;
    SQL(vector<string>& names, vector<int>& columns) {
        data.clear();
        for(int i=0;i<names.size();i++)
             colsize[names[i]]= columns[i], rowId[names[i]]=1;
    }
    
    bool ins(string name, vector<string> row) {
        if(colsize.count(name) && row.size()==colsize[name]){
             data[name][rowId[name]++]=row;
             return true;
        }else
           return false;
    }
    
    void rmv(string name, int rowId) {
        if(data.count(name) && data[name].count(rowId)){
            data[name].erase(rowId);
        }
    }
    
    string sel(string name, int rowId, int columnId) {
        if(data.count(name) && data[name].count(rowId) && columnId<=data[name][rowId].size())
             return data[name][rowId][columnId-1];
        else
           return "<null>";
    }
    
    vector<string> exp(string name) {
        auto it = data[name].begin();
        vector<string>ans;
        while(it!=data[name].end()){
            string curr =to_string(it->first);
            for(int i=0;i<it->second.size();i++){
                curr = curr+','+it->second[i];
            }
            ans.push_back(curr);
            it++;
        }
        return ans;
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */