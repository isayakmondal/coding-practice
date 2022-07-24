class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        vector<vector<int>> tmatrix ;
        vector<int> temp;
        
        // image.clear();
        
        for(auto && v: image){
            
            temp = v;
            reverse(temp.begin(), temp.end());
            for(int i=0;i<temp.size();i++){
                temp[i] = (!temp[i]);
            }
            tmatrix.push_back(temp);
            
        }
        
        return tmatrix;
    }
};