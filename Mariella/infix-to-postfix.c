/**
 * @author Mariella Jeanne A. Dellosa
 * 
 * Converts infix notation to postfix notation.
*/
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

    // Determines if the previous character was an operand.
    int wasOperand = 0;

    // Stores the characters of an operand.
    char operand_str[11];

    // Current index of the operand string.
    int operand_count = 0;

    // Length of the infix expression's string.
    int infix_len = strlen(infix);

    // Loops through the infix expression's string.
    for(int i = 0; i < infix_len; i++) {

        // Executes if the current character is a number.
        if(isNumber(infix[i])) {

            // Concatinates the current number to the operand's string.
            operand_str[operand_count] = infix[i];

            // Sets the next character to null.
            operand_str[operand_count + 1] = '\0';

            // Increases the operand digit count.
            operand_count++;

            // An operand has recently been checked.
            wasOperand = 1;

            // Executes if the operand is the last token of the expression.
            if(i == infix_len - 1) {
                
                // Stores the operand.
                Token token = {.operand = atoi(operand_str)};

                // Adds the token to the queue.
                enqueue(queue, token, OPERAND); 

                operand_count = 0;
            }

        // Executes if the current character is a symbol.
        } else {

            // Executes if the previous token was an operand.
            if(wasOperand) {
                
                // Stores the operand.
                Token token = {.operand = atoi(operand_str)};

                // Adds the token to the queue.
                enqueue(queue, token, OPERAND);

                // An operand has already been dealt with.
                wasOperand = 0;

                // Resets the operand digit count.
                operand_count = 0;
            }

            char *operator_str; // String of the operator.

            // Executes if the operator has two characters.
            if(i < infix_len - 1 && hasLengthTwo(infix[i], infix[i + 1])) {
                
                // Allocates memory for the operator string.
                operator_str = calloc(3, sizeof(char));

                // Adds the characters.
                sprintf(operator_str, "%c%c", infix[i], infix[i + 1]); 
                
                i++; // Skips an iteration.

            // Executes if the operator has one character.
            } else {
                
                // Allocates memory for the operator.
                operator_str = calloc(2, sizeof(char));

                // Stores the operator string.
                sprintf(operator_str, "%c", infix[i]);
            }

            // Stores the token.
            Token token = {.operator = operator_str};

            // Adds the token to the queue.
            enqueue(queue, token, OPERATOR);
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

    // Creates a new stack for the operators.
    Stack *operators = createStack();

    // Loops while the infix queue is not empty.
    while(!isQueueEmpty(*infix)) {

        // Adds the token to the postfix queue if it's an operand.
        if(getQueueEntryType(*getHeadEntry(*infix)) == OPERAND)
            enqueue(postfix, dequeue(infix, 1), OPERAND);

        // Executes if the token is an operator.
        else if(getQueueEntryType(*getHeadEntry(*infix)) == OPERATOR) {

            // Pushes opening parentheses to the operator stack.
            if(*getHeadToken(*infix).operator == '(')
                push(operators, dequeue(infix, 1), OPERATOR);

            // Executes if the current operator is a closing parenthesis.
            else if(*getHeadToken(*infix).operator == ')') {

                /** Adds the operators from the operator stack to the postfix
                 *  queue until an opening parenthesis has been reached.
                 */
                while(*getTopToken(*operators).operator != '(') {
                    enqueue(postfix, pop(operators), OPERATOR);
                }
                
                // Removes the opening parenthesis from the operator stack.
                pop(operators); 

                // Removes the closing parenthesis from the infix queue.
                dequeue(infix, 1);

            // Executes if the current operator is not a closing parenthesis.
            } else {

                /** While the priority of the infix queue's head is lesser than
                 *  or equal to that of the operator stack's top, the operator
                 *  in the stack's top is added to the postfix queue.
                 * 
                 *  This excludes ^ because of its right-to-left association.
                */
                if(!(*getHeadToken(*infix).operator == '^' &&
                    *getTopToken(*operators).operator == '^'))
                {
                    while(!isStackEmpty(*operators) &&
                        (getPriority(getHeadToken(*infix).operator) <=
                        getPriority(getTopToken(*operators).operator))) {

                        enqueue(postfix, pop(operators), OPERATOR);
                    }
                }

                // Adds the head of the infix queue to the top of the operator stack.
                push(operators, dequeue(infix, 1), OPERATOR);
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
