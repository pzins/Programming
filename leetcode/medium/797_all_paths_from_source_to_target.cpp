class Solution {
public:
    
    void fct(vector<vector<int>>& graph, vector<vector<int>>& res, int curr, vector<int> path) {
        if(curr == graph.size()-1)
        {
            res.push_back(path);
        }
        else
        {
            for(auto i : graph.at(curr))
            {
                path.push_back(i);
                fct(graph, res, i, path);
                path.pop_back();

            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path = {0};
        
        fct(graph, res, 0, path);
        return res;
    }
};
