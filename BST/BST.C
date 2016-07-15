#include<stdio.h>
#include<conio.h>

typedef struct bst_node
{
	int data;
	struct bst_node *left,*right;
}bst_node;

bst_node *create();
bst_node *insert(bst_node *t, int x);
bst_node *find(bst_node *t, int x);
bst_node *del(bst_node *t, int x);

void inorder(bst_node *t);
void perorder(bst_node *t);
void postorder(bst_node *t);

void main()
{
	bst_node *root,*p;
	int x,ch;
	clrscr();

	root=NULL;

	do
	{
		printf("\n\t\t1:CREATE");
		printf("\n\t\t2:INSERT");
		printf("\n\t\t3:FIND");
		printf("\n\t\t4:DELETE");
		printf("\n\t\t5:EXIT");

		printf("\n\n\t\tEnter your choice:");
		scanf("%d ",&ch);

		switch(ch)
		{
			case 1:
				root = create();
				break;

			case 2:
				printf("\n\t\tEnter no. to be inserted:");
				scanf("%d",&x);
				root=insert(root,x);
				break;

			case 3:
				printf("\n\t\tEnter no. to be deleted:");
				scanf("%d",&x);
				root=del(root,x);
				break;

			case 4:
				printf("\n\t\tEnter no. to find: ");
				scanf("%d",&x);
				root=find(root, x);
				break;

			case 5:
				exit(0);
				break;

			default:
				printf("\n\t\tSORRY.... no such option exist");
				break;

		}
	}while(1);

}


bst_node *create()
{
	int n,x,i;
	bst_node *root;
	root =NULL;

	printf("\n\n\t\tHow many nodes to be created:");
	scanf("%d",&n);
	printf("\n\t\tEnter tree values:");
	for (i=0; i<n; i++)
	{
		scanf("%d",&x);
		root = insert(root,x);
	}
return (root);
}

bst_node * insert(bst_node *t, int x)
{
	bst_node *p,*q,*r;

	r=(bst_node *)malloc(sizeof( bst_node));
	r->data =x;
	r->left=NULL;
	r->right=NULL;

	if (t == NULL)
		return (r);

	p=t;

	while (p != NULL)
	{
		q=p;
		if (x > p->data)
			p=p->right;
		else
			p=p->left;
	}

	if (x > q->data)
		q->right=r;
	else
		q->left=r;

	return(t);
}

bst_node *del(bst_node *t, int x)
{
	bst_node *temp;

	if (t== NULL)
	{
		printf("\n\t\\DATA NOT FOUND!");
		return (t);
	}

	if (x < t->data)
	{
		t->left = del(t ->left,x);
		return (t);
	}

	if (x > t->data)
	{
		t->right = del(t ->right,x);
		return (t);
	}

	if (t->left ==NULL && t->right ==NULL)
	{
		temp=t;
		free(temp);
		return(NULL);
	}

	if (t->left ==NULL)
	{
		temp=t;
		t=t->right;
		free(temp);
		return (t);
	}

	if (t->right ==NULL)
	{
		temp=t;
		t=t->left;
		free(temp);
		return (t);
	}

	temp=t->right ;

	while (temp->left !=NULL)
	    temp=temp->left;
	t->data=temp->data;
	t->right=del(t->right,temp->data);
	return(t);
   }



   bst_node * find(bst_node *root,int x)
      {
		while(root!=NULL)

		 {
			if(x==root->data)
			   return(root);
			if(x>root->data)
			  root= root->right;
			else
			  root=root->left;
		 }
		 return(NULL);
     }

   void inorder(bst_node *t)
    {
	if(t!=NULL)
	  {
		inorder(t->left);
		printf("%d",t->data);
		inorder(t->right);
	  }
    }
  void preorder(bst_node *t)
   {
      if(t!=NULL)
	{
		printf("%d",t->data);
		preorder(t->left);
		preorder(t->right);
	}
   }

  void postorder(bst_node *t)
   {

       {
		postorder(t->left);
		postorder(t->right);
		printf("%d",t->data);
       }
  }


/*  void nonreeorder(bst_node *t)
   {
     stack s;
     int(&s)
	    if(t!=NULL)
	    return
	    while(t!=NULL)
	      {
		push(&s,t)
		t=t->left;
	      }
	    while(!empty(&s))
	      {
		t=pop(&s)
		printf("%d",t->data)
		t=t->right;
		while(t!=NULL)
		 {
			push(&s,t)
			t=t->left;
		 }
	      }
   }
   void preordernonrec(bstnode *t)
    {
	   stack s;
	   s.top=-1;
	   while(t!=NULL)
	    {
		printf("d",t->data);
		push(&s,t);
		t=t->left;
	    }
	    while



  */



