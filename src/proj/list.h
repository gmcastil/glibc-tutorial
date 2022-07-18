#ifndef LIST_H
#define LIST_H

struct node {
	void *element;
	void *next;
};

struct list {
        struct node *head;
        struct node *tail;
        uint32_t length;
};

struct list *init_list(uint32_t length);

#endif /* LIST_H */
