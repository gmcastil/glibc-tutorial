#ifndef LIST_H
#define LIST_H

struct node {
	void *element;
	struct node *prev;
	struct node *next;
};

struct list {
        struct node *head;
        struct node *tail;
        uint32_t length;
};

struct list *list_init(void);

struct node *create_node(struct list *lptr, void *element);

void list_append(struct list *lptr, void *element);

#endif /* LIST_H */
