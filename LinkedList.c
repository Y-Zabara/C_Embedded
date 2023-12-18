#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 50

typedef struct {
    char title[LENGTH];
    float price;
    unsigned int number_of_pages;
    char language[LENGTH];
    float weight;
    unsigned int year;
} book;

typedef struct node {
    book harry_potter;
    struct node *next;
} node;

node *head = NULL;

void printList() {
    struct node *current = head;

    // start from the beginning
    while (current != NULL) {
        printf("%s\n"
               "price: %.3f $\n"
               "pages: %u\n"
               "language: %s\n"
               "weight: %.3f g\n"
               "year: %u\n"
               "-----------------\n",
               current->harry_potter.title,
               current->harry_potter.price,
               current->harry_potter.number_of_pages,
               current->harry_potter.language,
               current->harry_potter.weight,
               current->harry_potter.year);
        current = current->next;
    }
}

void insertatbegin(book harry_potter) {
    // create a link
    struct node *lk = (struct node *)malloc(sizeof(struct node));
    if (lk == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    lk->harry_potter = harry_potter;

    // point it to old first node
    lk->next = head;

    // point first to new first node
    head = lk;
}

void insertatend(book harry_potter) {
    // create a link
    struct node *lk = (struct node *)malloc(sizeof(struct node));
    if (lk == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    lk->harry_potter = harry_potter;
    struct node *linkedlist = head;

    // point it to old first node
    while (linkedlist->next != NULL)
        linkedlist = linkedlist->next;

    // point first to new first node
    linkedlist->next = lk;
}

int main() {
    book book1 = {"Philosopher's Stone", 10.35, 223, "english", 379.884, 2014};
    book book2 = {"Chamber of Secrets", 21.98, 341, "english", 1587.57, 2016};
    book book3 = {"Prisoner of Azkaban", 27.285, 383, "ukrainian", 370, 2017};
    book book4 = {"Goblet of Fire", 32.99, 636, "english", 604.68, 2000};
    book book5 = {"Order of the Phoenix", 25.5, 870, "english", 813.65, 2003};
    book book6 = {"Half-Blood Prince", 29.99, 652, "english", 652.68, 2005};
    book book7 = {"Deathly Hallows", 28.5, 759, "english", 654.77, 2007};

    insertatbegin(book1);
    insertatend(book2);
    insertatend(book3);
    insertatend(book4);
    insertatend(book5);
    insertatend(book6);
    insertatend(book7);
    // print list
    printList();
    return 0;
}

