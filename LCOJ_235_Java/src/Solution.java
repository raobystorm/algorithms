/**
 * Created by ZhongRui on 2015/07/26.
 */
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;
        if(p.val > root.val && q.val > root.val) {
            return lowestCommonAncestor(root.right, p, q);
        }else if(p.val < root.val && q.val < root.val){
            return lowestCommonAncestor(root.left, p, q);
        }else return root;
    }
    public static void main(String args[]){

        System.out.println("hello world!");
    }
}
