struct Node {
  int val;
  vector <Node *> children;
};


Node *GetNode(int val)
{
  Node *node  = new Node;
  node->val = val;
  node->children.clear();
  return node;
}

Node *DeepCopy(Node *head)
{
  
  if (!head) {
    return NULL;
  }
  Node *copyHeadMain = GetNode(head->val);
  Node *copyHead = copyHeadMain;
  queue <Node *> q;
  queue <Node *> copyq;
  Node *temp;
  Node *copyTemp;
  
  q.push(head);
  copyq.push(copyHead);
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    copyTemp = copyq.front();
    copyq.pop();
    
    for (auto child: q->children) {
      Node *copyChild = GetNode(child->val);
      copyTemp->children.push_back(copyChild);
      q.push(child);
      copyq.push(copyChild);
    }
  }
    return copyHeadMain;
}



Node *DCA_Helper(Node *root, Node *node_A, Node *node_B, bool *found_A, bool *found_B)
           {
             if (!root) {
               return NULL;
             }


             if (root == node_A) {
               *found_A = true;
              
             } else if (root == node_B) {
               *found_B = true;
             }
               
             Node *left = DCA_Helper(root->left, node_A, node_B, found_A, found_B);
           
  
             Node *right = DCA_Helper(root->right, node_A, node_B, found_A, found_B);

             if ((*found_A && *found_B) &&
                 
             (left == node_A && right == node_B) ||
                 (left == node_B && right == node_A) ||
                 (root == node_A && (right == node_B || left == node_B)) ||
                 (root == node_B && (right == node_A || left == node_A))) {
               return root;
             }
             */
             


Node *DeepestCommonAncestor(Node *root, Node *node_A, Node *node_B)
           {
             bool found_A = false;
             bool found_B = false;
             DCA_Helper(root, node_A, node_B, &found_A, &found_B);

           }
             
             
             
