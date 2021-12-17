/*
  Using LOT
*/
string serialize(Node * root) {

   if (root == NULL)
      return "";
   string res = "";

   queue<Node*> q;
   q.push(root);

   res += to_string(res -> val);
   res += "#";

   while (!q.empty()) {

      Node * curr = q.front();
      q.pop();
      //if nodes has children
      for (int i = 0; i < curr -> children.size(); i++) {
         if (curr -> children[i]) {
            res += to_string(curr -> children[i] -> val);
            q.push(curr -> children[i]);
         }
      }
      //if node has no children
      res += '#';
   }
   return res;
}
//Deserialize

class TreeNode {
public:
      int data;
      vector < TreeNode * > child;

};
TreeNode * deserialize(string data) {
   if (data.size() == 0) return NULL;
   //putting the data into stream
   stringstream s(data);
   string str;
   //1st input is stream,then in which input is store,
   //then comma is delimiter which stop taking further i/p
   getline(s, str, ',');
   //making root
   TreeNode * root = new TreeNode(stoi(str));
   queue < TreeNode * > q;
   q.push(root);

   while (!q.empty()) {
      TreeNode * curr = q.front();
      q.pop();

      vector < TreeNode * > children;

      while (1) {

         getline(s, str, ',');
         if (str == "null") {
            break;
         } else {
            TreeNode * node = new TreeNode(stoi(str));
            children.push_back(node);
            q.push(node);
         }
      }
      curr -> child = children;
   }
   return root;
}
