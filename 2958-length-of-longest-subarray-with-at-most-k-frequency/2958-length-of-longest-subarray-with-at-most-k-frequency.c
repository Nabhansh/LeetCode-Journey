#define HASH_MOD 1009
typedef struct node {
    int idx;
    int val;
    struct node* next;
} node_t;

node_t* hash[HASH_MOD];
void hash_init() { memset((void*)hash, 0, sizeof(hash)); }
int hash_get(int idx, int* val) {
    for (node_t* hdr = hash[idx % HASH_MOD]; hdr; hdr = hdr->next) {
        if (hdr->idx == idx) {
            *val = hdr->val;
            return 0;
        }
    }
    return -1;
}
void hash_set(int idx, int val) {
    int key = idx % HASH_MOD;
    node_t* hdr;
    for (hdr = hash[key]; hdr; hdr = hdr->next) {
        if (hdr->idx == idx)
            break;
    }
    if (hdr == NULL) {
        hdr = (node_t*)malloc(sizeof(node_t));
        hdr->idx = idx;
        hdr->next = hash[key];
        hash[key] = hdr;
    }
    hdr->val = val;
}

int maxSubarrayLength(int* nums, int numsSize, int k) {
    int ans = 0, freq;
    hash_init();
    for (int i = 0, j = 0; j < numsSize;) {
        freq = 0;
        hash_get(nums[j], &freq);
        if (freq + 1 <= k)
            hash_set(nums[j++], freq + 1);
        else {
            hash_get(nums[i], &freq);
            hash_set(nums[i], freq - 1);
            i++;
        }
        if (j - i > ans)
            ans = j - i;
    }
    return ans;
}