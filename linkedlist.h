struct node
{
  int data;
  struct node *next;
};

void
ll_add(struct node** head, int i)
{
  struct node* n;
  n = (struct node *) malloc(sizeof(struct node));
  n->data = i;
  n->next = 0;
  if (*head == 0)
    *head = n;
  else
  {
    struct node* curr = *head;
    while(curr->next != 0)
      curr = curr->next;
    curr->next = n;
  }
}

void
ll_print(struct node* head)
{
  struct node *n;
  n = head;
  while(n != 0) {
    printf(1, "%d\n", n->data);
    n = n->next;
  }
}
