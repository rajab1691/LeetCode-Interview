/*
  Bottom up Recursion
  T.C-O(n)
*/
int maxDepth(Node * root) {
   if (root == NULL)
      return 0;

   int ans = 0;
   for (int i = 0; i < root -> children.size(); i++) {
      int cnt = maxDepth(root -> children[i]);
      ans = max(ans, cnt);
   }
   return 1 + ans;
}
