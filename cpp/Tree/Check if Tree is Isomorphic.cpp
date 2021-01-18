/*
*	condition two;
*     1            1
*    / \          / \
*   2   3        3   2
*  /                  \
* 4                    4
*
* 
*	condition one;
*     1            1
*    / \          / \
*   2   3        2   3
*  /            /     
* 4            4      
* 
*/
bool isIsomorphic(Node *root1,Node *root2)
{
    if (!root1 && !root2)
        return true;
        
    if (root1 && root2 && root1->data == root2->data) {
        
        return (    /* condition one */
        			isIsomorphic(root1->left, root2->left) 
                    && isIsomorphic(root1->right, root2->right)
               ) || 
               (   /* condition two */
               		isIsomorphic(root1->left, root2->right)
                    && isIsomorphic(root1->right, root2->left)
               );
    }
    
    return false;
}
