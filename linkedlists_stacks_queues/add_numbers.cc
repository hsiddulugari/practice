LinkedListNode* addNumbers(LinkedListNode* l1, LinkedListNode* l2) {
    int carry = 0;
    LinkedListNode *res = NULL;
    LinkedListNode *res_tail = NULL;
    while (l1 || l2 || carry) {
        int add_nums = carry;
        if (l1) {
            add_nums += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            add_nums += l2->val;
            l2 = l2->next;
        }
        carry = add_nums/10;

        if (!res) {
            res = _insert_node_into_singlylinkedlist(res, res_tail, add_nums%10);
            res_tail = res;
        } else {
            res_tail = _insert_node_into_singlylinkedlist(res, res_tail, add_nums%10);
        }
    }
    return res;
