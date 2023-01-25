struct Node {
    int id = 0;
    vector<Node*> children = {};
};


void dfs(Node* start, vector<int>& others)
{
    if(start != nullptr && find(others.begin(), others.end(), start->id) == others.end())
    {
        others.push_back(start->id);
        cout << start->children.size() << endl;
        for(auto i : start->children)
        {
            dfs(i, others);
        }
    }
}

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<Node*> vec_bombs;
        for(int i = 0; i < bombs.size(); ++i)
        {
            Node* a = new Node();
            a->id = i;
            vec_bombs.push_back(a);
        }

        // Create graphs
        for(int i = 0; i < bombs.size(); ++i)
        {
            for(int j = 0; j < bombs.size(); ++j)
            {
                if(i != j)
                {
                    float dist = pow(pow(bombs.at(j).at(0) - bombs.at(i).at(0), 2) + pow(bombs.at(j).at(1) - bombs.at(i).at(1), 2), 0.5);
                    if(dist <= bombs.at(i).at(2))
                    {
                        vec_bombs.at(i)->children.push_back(vec_bombs.at(j));
                    }
                }
            }
        }

        int maxi = 0;
        for(int i = 0; i < vec_bombs.size(); ++i)
        {
            vector<int> tmp = {};
            dfs(vec_bombs.at(i), tmp);

            if(maxi < tmp.size())
            {
                maxi = tmp.size();
            }

        }
        
        return maxi;


    }
};
