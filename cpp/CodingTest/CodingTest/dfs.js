/*

    I: tree, pos val
    O: maximum depth of the tree
        
    C: 1) range - [0, 10^4]
        2) val_range - -100 <= Node.val <= 100 (X)
        
    E: tree== null return 0;
    
    
    brute force: naive && optimal solution:
        BFS or DFS (V) 
        DS - none;
    
    Time - O(N); ==> Vary(?) come back;
    Space - O(N); ==> call stack
    
    code:
        
     depth, height
     
            
            tree height = 4
            
         3       d=0, Math.max(h=2, h=3, h=1)
        / \
        9  20     d=1, h=1, h = 2, h=0
            /\
           15 7    d=2,  h=0, h = 1
             \
              8    h = 1
           
*/

var maxDepth = function(root) {
    
    // base case ==> edge case
    if(root === null) return 0;
    const depth = [0];
    depthRecursive(root, depth, 1)
    return depth[0];
    //return heightRecursive(root).height;
};

// top to bottom approach
function depthRecursive(curNode, depth, curDepth) {
    if(!curNode.left && !curNode.right) {
        depth[0] = Math.max(depth[0], curDepth);
        return;
    }
    
    if(curNode.left) {
        depthRecursive(curNode.left, depth, curDepth + 1);
    }
    
    if(curNode.right) {
        depthRecursive(curNode.right, depth, curDepth + 1);
    }
    
    return;
    
}

/// bottom up approach
function heightRecursive(curNode) {
    if(curNode === null) {
        return {height: 0};
    }
    
    let left = heightRecursive(curNode.left);
    let right = heightRecursive(curNode.right);
    //console.log(left.height, right.height)
    
    return {height : Math.max(left.height, right.height) + 1};
}
