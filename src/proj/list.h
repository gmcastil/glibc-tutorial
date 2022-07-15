#ifndef LIST_H
#define LIST_H

struct list {
        void *head;
        void *tail;
        uint32_t length;
};

struct list init_list(uint32_t length);

#endif /* LIST_H */
