/*
  Recursion
*/

void utilPost(Node * root, vector < int > & res) {

  if (root == NULL) return;

  for (int i = 0; i < root -> children.size(); i++) {
    utilPost(root -> children[i], res);
  }
  res.push_back(root -> val);
}
vector < int > postorder(Node * root) {
  vector < int > res;
  if (root == NULL)
    return res;

  utilPost(root, res);
  return res;
}
