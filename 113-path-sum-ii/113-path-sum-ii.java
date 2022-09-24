/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    List<List<Integer>> res = new ArrayList<>();    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {

        getSum(root, new ArrayList<Integer>(), 0, sum);
        return res;
    }

    private void getSum(TreeNode node, List<Integer> list, int current, int sum){
        if(node == null) return;
        current += node.val;
        list.add(node.val);

        if(node.left == null && node.right == null){
            if(current == sum){
                res.add(list);
            }else{
                return;
            }
        }
        if(node.left != null){
            getSum(node.left, new ArrayList<Integer>(list), current, sum);
        }
        if(node.right != null){
            getSum(node.right, new ArrayList<Integer>(list), current, sum);

        }

    }

}