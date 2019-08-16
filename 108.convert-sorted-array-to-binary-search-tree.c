/*
 * @lc app=leetcode id=108 lang=c
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* convert(int* nums, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = convert(nums, start, mid - 1);
    node->right = convert(nums, mid + 1, end);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return convert(nums, 0, numsSize - 1);
}
