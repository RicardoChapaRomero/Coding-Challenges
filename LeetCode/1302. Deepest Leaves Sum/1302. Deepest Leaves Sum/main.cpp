/*
 Given a binary tree, return the sum of values of its deepest leaves.

 Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 Output: 15
 
 This is just the solution for the problem, it isn't useful for testing.
 To try or debug your code, go to https://leetcode.com/problems/deepest-leaves-sum/
 */


#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void getSum(TreeNode* temp, int& sum, int& contMax, int contAct){
    if(contAct > contMax){
        contMax = contAct;
        sum=0;
    }
    if(temp->left != nullptr){
        contAct++;
        getSum(temp->left, sum, contMax, contAct);
        contAct--;
    }
    if(temp->right != nullptr){
        contAct++;
        getSum(temp->right, sum, contMax, contAct);
        contAct--;
    }
    if(contAct == contMax) sum += temp->val;
}
int deepestLeavesSum(TreeNode* root) {
    TreeNode* temp = root;
    int sum=0,contMax=0, contAct=0;
    getSum(temp, sum, contMax, contAct);
    return sum;
}

int main() {
    deepestLeavesSum(new TreeNode(3));
    return 0;
}
