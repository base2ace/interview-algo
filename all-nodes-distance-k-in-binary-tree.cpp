Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Input: root = [1], target = 1, k = 3
Output: []

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

void populateParentNodeToParentvalMap(TreeNode *node, 
  unordered_map<int, TreeNode*> &parentMap, TreeNode* parent)
{
  if(node != nullptr)
  {
    parentMap[node->val] = parent;
    populateParentNodeToParentvalMap(node->left, parentMap, node);
    populateParentNodeToParentvalMap(node->right, parentMap, node);
  }
}

vector<int> BFS_NodeDistanceK(TreeNode* targetNode, 
  unordered_map<int, TreeNode*> &parentMap, int k)
{
  deque<pair<TreeNode*, int>> queue = {pair<TreeNode*, int>(targetNode, 0)};
  unordered_set<int> seen = {targetNode->val};

  while(queue.size() > 0)
  {
    auto curNode = queue.front().first;
    auto distanceFromTarget = queue.front().second;

    queue.pop_front();

    if(distanceFromTarget == k)
    {
      vector<int> ansNode;
      for(auto item : queue)
      {
        ansNode.push_back(item.first->val);
      }
      ansNode.push_back(curNode->val);
      return ansNode;
    }

    vector<TreeNode*> connectedNodes = {curNode->left, curNode->right, parentMap[curNode->val]};

    for(auto node : connectedNodes)
    {
      if (node == nullptr) continue;

      if(seen.find(node->val) != seen.end()) continue;

      seen.insert(node->val);
      queue.push_back(pair<TreeNode*, int>(node, distanceFromTarget + 1));
    }
  }
  
return {};  
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       // Write your code here.
  unordered_map<int, TreeNode*> parentMap;
  populateParentNodeToParentvalMap(root, parentMap, nullptr);
  
  return BFS_NodeDistanceK(target, parentMap, k);   
    }
};
