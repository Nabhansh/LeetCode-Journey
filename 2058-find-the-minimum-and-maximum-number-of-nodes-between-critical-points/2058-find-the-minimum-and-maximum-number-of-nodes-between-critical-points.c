int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = -1;
    res[1] = -1;
    int prev_critical_ind = -1, first_critical_ind = -1;
    struct ListNode* prev = head;
    struct ListNode* cur = head->next;
    int cur_ind = 1;

    while (cur->next != NULL) {
        if ((cur->val > prev->val && cur->val > cur->next->val) ||
            (cur->val < prev->val && cur->val < cur->next->val)) {
            if (prev_critical_ind != -1) {
                res[0] = (res[0] == -1) ? cur_ind - prev_critical_ind : (cur_ind - prev_critical_ind < res[0] ? cur_ind - prev_critical_ind : res[0]);
            } else {
                first_critical_ind = cur_ind;
            }
            prev_critical_ind = cur_ind;
        }
        prev = cur;
        cur = cur->next;
        cur_ind++;
    }

    if (prev_critical_ind != -1 && prev_critical_ind != first_critical_ind) {
        res[1] = prev_critical_ind - first_critical_ind;
    }

    *returnSize = 2;
    return res;
}