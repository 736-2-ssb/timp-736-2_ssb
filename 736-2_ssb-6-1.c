#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
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
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    if (root -> value)
        printf("%d ", root -> value);
}

int main()
{
  int n, key, value;
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
        
        postorder(root);
        printf ("\n");
    
}

