/**
 * @author Mariella Jeanne A. Dellosa
 * 
 * Converts infix notation to postfix notation.
*/

#ifndef INFIX_TO_POSTFIX_
#define INFIX_TO_POSTFIX_

#include <stdlib.h>
#include <string.h>

#include "token.h"
#include "queue.h"
#include "stack.h"

/**
 * Stores the tokens of an infix expression in a queue.
 * 
 * @param queue {Queue *} A pointer to the infix queue.
 * @param infix {char *} A string of the infix expression.
*/
void storeInfix(Queue *queue, char *infix) {
    
    int wasOperand = 0;             // Determines if the previous character was an operand.
    char operand_str[11];           // Stores the characters of an operand.
    int operand_count = 0;          // Current index of the operand string.
    int infix_len = strlen(infix);  // Length of the infix expression's string.
    
    // Loops through the infix expression's string.
    for(int i = 0; i < infix_len; i++) {

        // Executes if the current character is a number.
        if(isNumber(infix[i])) {

            
            operand_str[operand_count] = infix[i]; // Concatinates the current number to the operand's string.            
            operand_str[operand_count + 1] = '\0'; // Sets the next character to null.

            operand_count++;    // Increases the operand digit count.
            wasOperand = 1;     // An operand has recently been checked.

            // Executes if the operand is the last token of the expression.
            if(i == infix_len - 1) {
                
                Token token = {.operand = atoi(operand_str)}; // Stores the operand.
                enqueue(queue, token, OPERAND);               // Adds the token to the queue.

                operand_count = 0;  // Resets the operand digit count.
            }

        // Executes if the current character is a symbol.
        } else {

            // Executes if the previous token was an operand.
            if(wasOperand) {

                Token token = {.operand = atoi(operand_str)};   // Stores the operand.
                enqueue(queue, token, OPERAND);                 // Adds the token to the queue.
                
                wasOperand = 0;     // An operand has already been dealt with.
                operand_count = 0;  // Resets the operand digit count.
            }

            char *operator_str; // String of the operator.

            // Executes if the operator has two characters.
            if(i < infix_len - 1 && hasLengthTwo(infix[i], infix[i + 1])) {
                
                operator_str = calloc(3, sizeof(char)); // Allocates memory for the operator string.
                sprintf(operator_str, "%c%c", infix[i], infix[i + 1]);  // Adds the characters to the buffer.
                
                i++; // Skips an iteration.

            // Executes if the operator has one character.
            } else {
                operator_str = calloc(2, sizeof(char)); // Allocates memory for the operator.
                sprintf(operator_str, "%c", infix[i]);  // Stores the operator string.
            }
            
            Token token = {.operator = operator_str};   // Stores the token.
            enqueue(queue, token, OPERATOR);            // Adds the token to the queue.
        }
    }
}

/**
 * Converts an infix expression to postfix.
 * 
 * @param postfix {Queue *} A pointer to the postfix queue.
 * @param infix {Queue *} A pointer to the infix queue.
*/
void convertToPostix(Queue *postfix, Queue *infix) {

    Stack *operators = createStack();   // Creates a new stack for the operators.

    // Loops while the infix queue is not empty.
    while(!isQueueEmpty(*infix)) {

        // Adds the token to the postfix queue if it's an operand.
        if(getQueueEntryType(*getHeadEntry(*infix)) == OPERAND)
            enqueue(postfix, dequeue(infix, 1), OPERAND);

        // Executes if the token is an operator.
        else if(getQueueEntryType(*getHeadEntry(*infix)) == OPERATOR) {

            /** While the priority of the infix queue's head is lesser than
             *  or equal to that of the operator stack's top, the operator
             *  in the stack's top is added to the postfix queue.
             */
            while(!isStackEmpty(*operators) &&
                  getPriority(getHeadToken(*infix).operator, ICP) <=
                  getPriority(getTopToken(*operators).operator, ISP)) {

                enqueue(postfix, pop(operators), OPERATOR);
            }

            // Adds the head of the infix queue to the top of the operator stack.
            push(operators, dequeue(infix, 1), OPERATOR);

            /** If the top of the operator stack is a closing parenthesis,
             *  pops the closing parenthesis and nearest opening parenthesis.
             */ 
            if(!isStackEmpty(*operators)) {
                if(*getTopToken(*operators).operator == ')') {
                    pop(operators);
                    pop(operators);
                }
            }
        }
    }

    // Adds the remaining operators to the queue except open parentheses.
    while(!isStackEmpty(*operators)) {

        // Discards open parentheses.
        if(*getTopToken(*operators).operator == '(')
            pop(operators);
        else enqueue(postfix, pop(operators), OPERATOR);
    }

    free(operators); // Frees the operator stack from memory.
}

#endif