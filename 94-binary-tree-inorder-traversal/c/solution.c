#include "solution.h"
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

inline struct TreeNode* findPrev(struct TreeNode* curr) {
    struct TreeNode* prev = curr->left;

    if (!prev) return prev;

    while (prev->right && prev->right != curr) {
        prev = prev->right;
    }

    return prev;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = malloc(sizeof(int) * 100);

    struct TreeNode* curr = root;
    struct TreeNode* prev;

    int idx = 0;
    while (curr) {
        if (curr->left) {
            prev = findPrev(curr);

            if (prev->right) {
                ret[idx] = curr->val;
                ++idx;

                prev->right = NULL;
                curr = curr->right;
            }
            else {
                prev->right = curr;
                curr = curr->left;
            }
        }
        else {
            ret[idx] = curr->val;
            ++idx;

            curr = curr->right;
        }
    }

    *returnSize = idx;
    ret = realloc(ret, (size_t) idx * sizeof(int));
    return ret;
}
