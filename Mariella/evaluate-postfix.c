/**
 * @author Mariella Jeanne A. Dellosa
 * 
 * Evaluates a postfix expression.
*/

#ifndef EVALUATE_POSTFIX_
#define EVALUATE_POSTFIX_

#include <stdlib.h>
#include <string.h>

#include "token.h"
#include "queue.h"
#include "stack.h"

/**
 * Evaluates a postfix expression.
 * 
 * @param postfix {Queue *} A pointer to the postfix expression's queue.
 * @return {int} The evaluated value. Returns -1 if there's a division by 0 error.
*/
void evaluatePostfix(Queue *postfix) {

    Stack *operands = createStack(); // Creates a new stack for the operands.

    int operand_1;  // The first operand to be evaluated.
    int operand_2;  // The second operand to be evaluated.
    char *operator; // The operator to be evaluated.

    // Loops while the postfix expression queue is not empty.
    while(!isQueueEmpty(*postfix)) {

        // Pushes the head of the postfix queue to the operand stack if it's an operand.
        if((*getHeadEntry(*postfix)).type == OPERAND)
            push(operands, dequeue(postfix, 1), OPERAND);
            
        // Evaluates the operator with the last two operands of the stack.
        else if((*getHeadEntry(*postfix)).type == OPERATOR) {

            // Gets the operator from the postfix queue.
            operator = dequeue(postfix, 1).operator;

            /** If the operator is NOT, sets the second operand to 0.
             *  Otherwise, gets the second operand from the operand stack.
             */ 
            if(strlen(operator) == 1 && *operator == '!') 
                operand_2 = 0;
            else
                operand_2 = pop(operands).operand;
            
            operand_1 = pop(operands).operand; // Gets the first operand from the operand stack.

            // Checks if there's a division by zero error.
            if((operand_2 == 0 && (*operator == '/' || *operator == '%')) ||
              (operand_1 == 0 && operand_2 < 0 && (*operator == '^'))) {
                printf("Division by zero error!");
                return;
            }
            
            Token token; // Stores the result.
            token.operand = operate(operand_1, operand_2, operator);

            push(operands, token, OPERAND); // Pushes the evaluated result to the operand stack.
        }
    }

    printf("%d", pop(operands).operand); // Gets the output from the only entry left in the operand stack.
    free(operands); // Frees the operand stack from memory.
}

#endif