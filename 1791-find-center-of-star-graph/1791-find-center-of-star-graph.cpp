class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // the center will be the only one repeated
        if(edges[0][0]==edges[1][0] or edges[0][0]==edges[1][1])
            return edges[0][0];
        if(edges[0][1]==edges[1][0] or edges[0][1]==edges[1][1])
            return edges[0][1];
        
        return 0;
    }
};