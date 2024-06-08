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

    char *input = calloc((1 << 8), sizeof(char));   // Allocates memory for the user's input.
    Queue *infix, *postfix;                         // Queues for the infix and postfix expressions.

    // Continues while the user hasn't quit.
    
    while(strcmp(input, "QUIT") != 0) {

        scanf(" %s", input); // Scans the user's input.

        if(strcmp(input, "QUIT") != 0) {
            
            infix = createQueue();              // Creates the infix queue.
            postfix = createQueue();            // Creates the postfix queue.

            storeInfix(infix, input);           // Stores the infix expression in a queue.
            convertToPostfix(postfix, infix);    // Converts the infix expression to postfix.
            printQueue(postfix);                // Prints out the postfix expression.
            evaluatePostfix(postfix);           // Evaluates the postfix expression.

            free(infix);                        // Frees the infix queue from memory.
            free(postfix);                      // Frees the postfix queue from memory.

            printf("\n\n");
        }
    }

    return 0;
}