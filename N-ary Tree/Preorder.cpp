/*
  Recursion
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
void utilPre(Node * root, vector < int > & res) {

  if (root == NULL)
    return;

  res.push_back(root -> val);
  for (int i = 0; i < root -> children.size(); i++) {
    Node * temp = root -> children[i];
    utilPre(temp, res);
  }
}
vector < int > preorder(Node * root) {
  vector < int > res;
  if (root == NULL)
    return res;

  utilPre(root, res);
  return res;
}
