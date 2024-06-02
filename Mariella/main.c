/**
 * @author Mariella Jeanne A. Dellosa
 * 
 * The main method.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"
#include "queue.h"
#include "stack.h"

#include "infix-to-postfix.c"
#include "evaluate-postfix.c"

int main() {

    // Allocates memory for the user's input.
    char *input = calloc((1 << 8), sizeof(char));

    // Queues for the infix and postfix expressions.
    Queue *infix, *postfix;

    // Continues while the user hasn't quit.
    while(strcmp(input, "QUIT") != 0) {

        // Scans the user's input.
        scanf(" %s", input);

        if(strcmp(input, "QUIT") != 0) {

            // Creates queues for the infix and postfix expressions.
            infix = createQueue();
            postfix = createQueue();

            // Stores the infix expression in a queue.
            storeInfix(infix, input);

            // Converts the infix expression to postfix.
            convertToPostix(postfix, infix);

            // Prints out the postfix expression.
            printQueue(postfix);
            
            // Evaluates the postfix expression.
            evaluatePostfix(postfix);

            // Frees the queues from memory.
            free(infix);
            free(postfix);

            printf("\n\n");
        }
    }

    return 0;
}