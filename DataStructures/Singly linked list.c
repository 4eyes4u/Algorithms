#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    struct _Node *next;
    int val;
} Node;

Node* make_node(int val) {
    Node *new_node = (Node *)calloc(1, sizeof(Node));
    new_node -> val = val;

    return new_node;
}

Node* next(Node *v) {
    return v ? v -> next : NULL;
}

void insert(Node **head, Node **tail, Node *v, int val) {
    Node *new_node = make_node(val);

    if (!v) {
        new_node -> next = *head;
        *head = new_node;
    }
    else {
        new_node -> next = next(v);
        v -> next = new_node;
    }
    
    if (!next(new_node)) *tail = new_node;
}

void erase(Node **head, Node **tail, Node *v) { // deleting v -> next    
    Node *tmp = (Node *)calloc(1, sizeof(Node));

    if (!v) {
        tmp = *head;
        *head = next(*head);
        
        if (!*head) *tail = NULL;
    }
    else {
        tmp = next(v);
        v -> next = next(v -> next);

        if (!next(v)) *tail = v;
    }

    free(tmp);
}

void print_list(Node *head, FILE *out) {
    if (!head) {
        fputs("\n", out);
        return;
    }

    fprintf(out, "%d ", head -> val);
    print_list(head -> next, out);
}

void delete_list(Node *head) {
    if (!head) return;
    delete_list(head -> next);
    free(head);    
}

void read_list(Node **head, Node **tail, FILE *in) {
    int x;
    
    while (fscanf(in, "%d", &x) != EOF)
        insert(head, tail, *tail, x);
}

int main() {
    Node *head = (Node *)calloc(1, sizeof(Node));
    Node *tail = (Node *)calloc(1, sizeof(Node));
    head = tail = NULL;

    read_list(&head, &tail, stdin);

    erase(&head, &tail, NULL);
    erase(&head, &tail, head -> next);
    print_list(head, stdout);

    printf("%d %d\n", head -> val, tail -> val);
    
    delete_list(head);

    return 0;
}
