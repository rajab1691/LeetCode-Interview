vector < vector < int >> levelOrder(Node * root) {
  vector < vector < int >> res;
  if (root == NULL)
    return res;
  queue < Node * > q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    vector < int > ans;
    while (size--) {
      Node * node = q.front();
      q.pop();
      ans.push_back(node -> val);
      for (int i = 0; i < node -> children.size(); i++) {
        q.push(node -> children[i]);
      }
    }
    res.push_back(ans);
  }
  return res;
}
