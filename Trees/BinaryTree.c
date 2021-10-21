#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
  char data;
  struct node *left;
  struct node *right;
} node;
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}
node *create()
{
    node *p;
    char x[2];
    printf("\nEnter data($ for no node):");
    scanf("%s",x);
    if(strcmp(x,"$")==0)
    {
       return NULL;
    }
    p=(node*)malloc(sizeof(node));
    p->data=x[0];
    printf("Enter left child of %c:\n",x[0]);
    p->left=create();
    if(p->left==NULL){p->right=NULL;return p;}
    printf("Enter right child of %c:\n",x[0]);
    p->right=create();
    return p;
}
int main()
{
  node *tree;
  printf("\nEnter the elements of the binary tree:");
  tree=create();
  inorder(tree);
  return 0;
}
/*OUTPUT:
Enter the elements of the binary tree:
Enter data($ for no node):A
Enter left child of A:

Enter data($ for no node):B
Enter left child of B:

Enter data($ for no node):$
Enter right child of A:

Enter data($ for no node):C
Enter left child of C:

Enter data($ for no node):$
B A C
*/
