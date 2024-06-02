/**
 * @author Mariella Jeanne A. Dellosa
 * 
 * This creates the stack data structure and consists of its corresponding
 * helper functions.
*/

#ifndef STACK
#define STACK

#include <stdlib.h>
#include <string.h>

#include "token.h"

#define STACK_MAX_SIZE (1 << 8) // Max size of the stack.

typedef struct Stack Stack;
typedef struct StackEntry StackEntry;

// The stack structure.
struct Stack {
    int size;           // The current size of the stack.
    StackEntry *top;    // A pointer to the topmost entry of the stack.
};

// An entry of a stack.
struct StackEntry {
    Token token;        // The token of the entry.
    TokenType type;     // The token type (operand/operator).
    StackEntry *prev;   // A pointer to the previous entry.
};

/**
 * Creates an empty stack.
 * 
 * @return {Stack *} A pointer to an empty stack.
*/
Stack *createStack() {

    // Allocates memory for the stack.
    Stack *stack = calloc(1, sizeof(*stack));

    stack->size = 0; // Sets the stack's size to 0.
    stack->top = NULL; // Sets the top's pointer to NULL.

    return stack;
}

/**
 * Creates a new entry given the token.
 * 
 * @param token {Token} The token to be stored in the entry.
 * @param type {TokenType} The token type (operand/operator).
 * @return {StackEntry *} A pointer to the newly created entry.
*/
StackEntry *createStackEntry(Token token, TokenType type) {

    // Allocates memory for the entry.
    StackEntry *entry = calloc(1, sizeof(*entry));

    entry->token = token; // Sets the entry's token.
    entry->type = type; // Sets the entry's token type.
    entry->prev = NULL; // Sets the the previous entry's pointer to NULL.

    return entry;
}

/**
 * Checks if a stack is empty.
 * 
 * @param stack {Stack} The stack.
 * @return {int} 1 if the stack is empty, 0 otherwise.
*/
int isStackEmpty(Stack stack) {
    return stack.size == 0;
}

/**
 * Checks if a stack is full.
 * 
 * @param stack {Stack} The stack.
 * @return {int} 1 if the stack is full, 0 otherwise.
*/
int isStackFull(Stack stack) {
    return stack.size == STACK_MAX_SIZE;
}

/**
 * Frees a stack entry from the heap.
 * 
 * @param entry {StackEntry *} A pointer to the stack entry.
*/
void freeStackEntry(StackEntry *entry) {
    free(entry); // Frees the entry's pointer.
}

/**
 * Inserts an entry into the stack.
 * 
 * @param stack {Stack *} A pointer to the stack.
 * @param token {Token} The token to be inserted in the stack.
 * @param type {TokenType} The token type (operand/operator).
*/
void push(Stack *stack, Token token, TokenType type) {
    
    // Creates a new stack entry.
    StackEntry *entry = createStackEntry(token, type);

    // Re-assigns the top.
    entry->prev = stack->top;
    stack->top = entry;

    stack->size++; // Updates the size of the stack.
}

/**
 * Removes an entry from the stack and returns its token.
 * 
 * @param stack {Stack *} A pointer to the stack.
 * @return {Token} The token to be removed.
*/
Token pop(Stack *stack) {

    Token token; // Stores the token to be removed.

    // Stores operands.
    if(stack->top->type == OPERAND)
        token.operand = stack->top->token.operand;
    
    // Stores operators.
    else token.operator = stack->top->token.operator;
    
    // Frees the top's memory from the heap.
    freeStackEntry(stack->top);

    // Updates the stack's size.
    stack->size--;

    // The current top's pointer is now the former's.
    if(!isStackEmpty(*stack))
        stack->top = stack->top->prev;
    
    // Returns the pointer to the deleted entry.
    return token;
}

/**
 * Returns a pointer to the stack's top.
 * 
 * @param stack {Stack} The stack.
 * @return {StackEntry *} A pointer to the top.
*/
StackEntry *getTopEntry(Stack stack) {

    // Returns NULL if the queue is empty.
    if(isStackEmpty(stack))
        return NULL;

    return stack.top;
}

/**
 * Returns the token of the stack's top.
 * 
 * @param stack {Stack} The stack.
 * @return {Token} The stack.'s token.
*/
Token getTopToken(Stack stack) {
    return stack.top->token;
}

/**
 * Determines the entry's token type (operand/operator).
 * 
 * @param entry {StackEntry} The entry.
 * @return {TokenType} The entry's token type.
*/
TokenType getStackEntryType(StackEntry entry) {
    return entry.type;
}

#endif
