LinkedListNode* swapNodes(LinkedListNode* pList, int iK) {
    stack <LinkedListNode *> nodeStack;
    LinkedListNode *itr = pList;
    while (itr) {
        nodeStack.push(itr);
        itr = itr->next;
    }
    int size = nodeStack.size();
    int num_pops = iK - 1;
    LinkedListNode *endSwapNode = NULL;
    LinkedListNode *endSwapNodeParent = NULL;
    while (num_pops--) {
        nodeStack.pop();
    }
    endSwapNode = nodeStack.top();
    nodeStack.pop();
        if (!nodeStack.empty()) {
            endSwapNodeParent = nodeStack.top();
        } else {
            endSwapNodeParent = endSwapNode;
        }    

    
    num_pops = size - iK;
    LinkedListNode *startSwapNode = NULL;
    LinkedListNode *startSwapNodeParent = NULL;
    while (num_pops--) {
        nodeStack.top();
    }
        startSwapNode = nodeStack.top();
        nodeStack.pop();
        if (!nodeStack.empty()) {
            startSwapNodeParent = nodeStack.top();
        } else {
            startSwapNodeParent = pList;
        }        
    

    LinkedListNode *endNodeNext = endSwapNode->next;
    endSwapNode->next = startSwapNode->next;
    startSwapNode->next = endNodeNext;
    LinkedListNode *endNodeParentNext = endSwapNodeParent->next;
    endSwapNodeParent->next = startSwapNodeParent->next;
    startSwapNodeParent->next = endNodeParentNext;
    return pList;
}

