#ifndef LIST_H
#define LIST_H

typedef struct List {
        void *head;
        void *tail;
        uint32_t length;
} list;

list init_list(uint32_t length);

#endif /* LIST_H */
