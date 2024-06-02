/**
 * @author Mariella Jeanne A. Dellosa
 * 
 * This creates the queue data structure and consists of its corresponding
 * helper functions.
*/

#ifndef QUEUE
#define QUEUE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "token.h"

#define QUEUE_MAX_SIZE (1 << 8) // Max size of the queue.

typedef struct Queue Queue;
typedef struct QueueEntry QueueEntry;

// The queue data structure.
struct Queue {
    int size;           // The queue's current size.
    QueueEntry *head;   // Head of the queue.
    QueueEntry *tail;   // Tail of the queue.
};

// An entry of a queue.
struct QueueEntry {
    Token token;        // The token of the entry.
    TokenType type;     // The token type (operator/operand).
    QueueEntry *next;   // A pointer to the next entry.
};

/**
 * Creates an empty queue.
 * 
 * @return {Queue *} A pointer to an empty queue.
*/
Queue *createQueue() {

    // Allocates memory for the queue.
    Queue *queue = calloc(1, sizeof(*queue)); 
    
    queue->size = 0; // Sets the queue's size to 0.
    queue->head = NULL; // Sets the head's pointer to NULL.
    queue->tail = NULL; // Sets the tail's pointer to NULL.

    return queue;
}

/**
 * Creates a new entry given the token.
 * 
 * @param token {Token} The token to be stored in the entry.
 * @param type {TokenType} The token type (operand/operator).
 * @return {QueueEntry *} A pointer to the newly created entry.
*/
QueueEntry *createQueueEntry(Token token, TokenType type) {

    // Allocates memory for the entry.
    QueueEntry *entry = calloc(1, sizeof(*entry));

    entry->token = token; // Sets the entry's token.
    entry->type = type; // Sets the entry's token type.
    entry->next = NULL; // Sets the pointer to the next entry to NULL.

    return entry;
}

/**
 * Checks if a queue is empty.
 * 
 * @param stack {Queue} The queue.
 * @return {int} 1 if the queue is empty, 0 otherwise.
*/
int isQueueEmpty(Queue queue) {
    return queue.size == 0;
}

/**
 * Checks if a queue is full.
 * 
 * @param stack {Queue} The queue.
 * @return {int} 1 if the queue is full, 0 otherwise.
*/
int isQueueFull(Queue queue) {
    return queue.size == QUEUE_MAX_SIZE;
}

/**
 * Frees a queue entry from the heap.
 * 
 * @param entry {QueueEntry *} A pointer to the queue entry.
*/
void freeQueueEntry(QueueEntry *entry) {
    free(entry); // Frees the entry's pointer.
}

/**
 * Inserts an entry into the queue.
 * 
 * @param queue {Queue *} A pointer to the queue.
 * @param token {Token} The token to be inserted in the queue.
 * @param type {TokenType} The token type (operand/operator).
*/
void enqueue(Queue *queue, Token token, TokenType type) {

    // Creates a new queue entry.
    QueueEntry *entry = createQueueEntry(token, type);

    // Sets the head to the new entry if it is empty.
    if(isQueueEmpty(*queue))
        queue->head = entry;

    // Re-assigns the tail to the new entry.
    if(queue->tail != NULL)
        queue->tail->next = entry;
    queue->tail = entry;

    // Updates the size of the queue.
    queue->size++; 
}

/**
 * Removes an entry from the queue and returns its token.
 * 
 * @param queue {Queue *} A pointer to the queue.
 * @param isFree {int} Determines if the head must be freed.
 * @return {Token} The token to be removed.
*/
Token dequeue(Queue *queue, int isFree) {

    Token token; // Stores the token to be removed.

    // Temporarily stores the former head.
    QueueEntry *temp = queue->head; 

    // Stores operands.
    if(queue->head->type == OPERAND)
        token.operand = queue->head->token.operand;
    
    // Stores operators.
    else token.operator = queue->head->token.operator;

    // Re-assigns the head.
    if(queue->head->next != NULL)
        queue->head = queue->head->next;
    
    // Frees the former head.
    if(isFree) freeQueueEntry(temp);

    // Decreases the size of the queue by 1.
    queue->size--; 

    // Returns the removed token.
    return token;
}

/**
 * Returns a pointer to the tail.
 * 
 * @param queue {Queue} The queue.
 * @return {QueueEntry *} A pointer to the tail.
*/
QueueEntry *getTailEntry(Queue queue) {

    // Returns NULL if the queue is empty.
    if(isQueueEmpty(queue))
        return NULL;

    return queue.tail;
}

/**
 * Returns the token of the tail.
 * 
 * @param queue {Queue} The queue.
 * @return {Token} The tail's token.
*/
Token getTailToken(Queue queue) {
    return queue.tail->token;
}

/**
 * Returns a pointer to the head.
 * 
 * @param queue {Queue} The queue.
 * @return {QueueEntry *} A pointer to the head.
*/
QueueEntry *getHeadEntry(Queue queue) {

    // Returns NULL if the queue is empty.
    if(isQueueEmpty(queue))
        return NULL;

    return queue.head;
}

/**
 * Returns the token of the head.
 * 
 * @param queue {Queue} The queue.
 * @return {Token} The head's token.
*/
Token getHeadToken(Queue queue) {
    return queue.head->token;
}

/**
 * Determines the entry's token type (operand/operator).
 * 
 * @param entry {QueueEntry} The entry.
 * @return {TokenType} The entry's token type.
*/
TokenType getQueueEntryType(QueueEntry entry) {
    return entry.type;
}

/**
 * Prints out the tokens of a queue separated by space.
 * 
 * @param this {Queue} The queue to be printed.
*/
void printQueue(Queue *queue) {

    // Saves the head of the queue.
    QueueEntry *head = queue->head;

    // Saves the size of the queue.
    int size = queue->size;

    // Loops while the queue is not empty.
    while(!isQueueEmpty(*queue)) {

        // Prints out operands.
        if(queue->head->type == OPERAND)
            printf("%d", dequeue(queue, 0).operand);

        // Prints out operators.
        else if(queue->head->type == OPERATOR)
            printf("%s", dequeue(queue, 0).operator);
            
        // Prints out a single space if the queue is not yet empty.
        if(!isQueueEmpty(*queue))
            printf(" ");
    }

    // Resets the head of the queue.
    queue->head = head;

    // Resets the size of the queue.
    queue->size = size;
}

#endif
