#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        int value;
        int key;
        struct tree *left;
        struct tree *right;
        struct tree *parent;
} node;
typedef node* tree;
int count=0;
tree init(int key, int value){
    tree tmp = malloc(sizeof(node));

    tmp -> value = value;
    tmp -> key = key;

    tmp -> parent = NULL;
    tmp -> left = NULL;
    tmp -> right = NULL;

    return tmp;
}

void add(tree root, int key, int value)
{

        while(1)
        {
                if (root->key==key)
                {
                        root->value=value;
                        break;
                }

                if (key>root->key)
                {
                        if (root->right==NULL)
                        {
                                tree tmp = malloc(sizeof(node));
                                root->right = tmp;
                                tmp->key=key;
				tmp->value=value;
                                tmp->parent=root;
                                break;
                        }
                        else
                        {
                                root=root->right;
                                continue;
                        }
                }

                if (key<root->key)
                {
                        if (root->left==NULL)
                        {
                                tree tmp = malloc(sizeof(node));
                                root->left = tmp;
                                tmp->key=key;
                                tmp->value=value;
                                tmp->parent=root;
                                break;
                        }
                        else
                        {
                                root=root->left;
                                continue;
                        }
                }
    }
}
int find(tree root, int key){
        count++;
        if (root==NULL)
                return -1;

        if (root -> key == key)
                return root->value;

        if (key < root -> key)
                return find(root -> left, key);
	else return find(root -> right, key);
}
int main()
{
  int n, key, value;
  int a,b,c, tp;
  scanf ("%d", &n);
  scanf("%d", &key);
  scanf("%d", &value);
  tree root = init(key, value);
  for (int i=1; i<n; i++)
 {
           scanf("%d", &key);
           scanf("%d", &value);
           add (root, key, value);
        }
        
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        
        tp=0;
        count=-1;
        tp=find(root,a);
                if (tp!=-1)
                        printf("%d ", count);
                printf("%d", tp);

                printf ("\n");
                
        tp=0;
        count=-1;
        tp=find(root,b);
                if (tp!=-1)
                        printf("%d ", count);
                printf("%d", tp);

                printf ("\n");
        
        tp=0;
        count=-1;
        tp=find(root,c);
                if (tp!=-1)
                        printf("%d ", count);
                printf("%d", tp);

                printf ("\n");
    
}
