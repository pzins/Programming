
struct Node
{
    Node* children[2];
    Node(){
        children[0] = nullptr; //0 
        children[1] = nullptr; //1
    }
};

class Solution {
public:
    Node* head;

    void insert(int num, Node* trie)
    {
        bitset<32> bs(num);
        for(int i = 31; i >= 0; --i)
        {
            if(!trie->children[bs[i]]) trie->children[bs[i]] = new Node();
            trie = trie->children[bs[i]];
        }

    }

    int maxi(int num, Node* trie)
    {
        bitset<32> bs(num);
        int res = 0;
        for(int i = 31; i >= 0; --i)
        {
            if(trie->children[!bs[i]])
            {
                res += (1<<i);
                trie = trie->children[!bs[i]];
            }
            else
            {
                trie = trie->children[bs[i]];
            }
        }
        return res;
    }

    int findMaximumXOR(vector<int>& nums) {
        Node n;
        for(auto num : nums)
        {
            insert(num, &n);
        }

        int m = 0;
        for(auto num : nums)
        {
            m = max(m, maxi(num, &n));
        }
        return m;
        
    }
};
