class Solution {
public:
    int ans = 0;
    map<int,vector<int>> adj_list;
    
    int countGoodNodes(vector<vector<int>>& edges) {
        for(int i=0; i<edges.size(); i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        dfs(0, -1);
        
        return ans;
    }
    
private:
    int dfs(int node, int parent){
        int total = 1;
        set<int> st;
        for(int n: adj_list[node]){
            if(n != parent){
                int c = dfs(n, node);
                st.insert(c);
                total += c;
            }
        }
        
        if(st.size()==1 or st.size()==0)
            ans++;
        
        return total;
    }
};