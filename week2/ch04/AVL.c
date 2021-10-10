struct AvlNode;
typedef struct AvlNode *Position
typedef struct AvlNode *AvlTree;
AvlTree MakeEmpty(AvlTree T);
Position Find(int x,AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(int x,AvlTree T);
AvlTree Delete(int x,AvlTree T);
int Retrieve(Position P);
struct AvlNode
{
    int data;
    AvlTree left;
    AvlTree right;
    int height;
};
static int Height(Position P)
{
    if(P==NULL)
    return -1;
    else
    return P->height;
}
AvlTree Insert(int x,AvlTree T)
{
    if(T==NULL)
    {
         T=malloc(sizeof(struct AvlNode));
         if(T==NULL)
         Printf("OUt of space");
         else
         {
             T->data=x;
             T->height=0;
             T->left=T->right=NULL;

         }
    }
    else if(x<T->data)
    {
        T->left=Insert(x,T->left);
       if(Height(T->left)-Height(T->right)==2)
         if(x<T->left->data)
         T=SingleRotateWithLeft(T);
         else
          T=DoubleRotateWithLeft(T);
    }
   else if(x>T->data)
    {
        T->right=Insert(x,T->left);
       if(Height(T->right)-Height(T->left)==2)
         if(x>T->right->data)
         T=SingleRotateWithRight(T);
         else
          T=DoubleRotateWithRight(T);
    }
    T->height=Max(Height(T->left),Height(T->right))+1;
    return T;
}
static Position SingleRotateWithLeft(Position k2)
{
    Position k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height =Max(Height (k2->left),Height(k2->right))+1;
     k1->height =Max(Height (k1->left),k2->height)+1;
     return k1;
}
static Position DoubleRotateWithLeft(Position k3)
{
    k3->left=SingleRotateWithRight(k3->left);
    return SingleRotateWithLeft(k3);
}
