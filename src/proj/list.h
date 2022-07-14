#ifndef LIST_H
#define LIST_H

struct node {
        void *element = NULL;
        void *next = NULL;
        void *prev = NULL;
};

struct list {
        void *head = NULL;
        void *tail = NULL;
        uint32_t length;
};

struct list list(uint32_t length);

#endif /* LIST_H */
