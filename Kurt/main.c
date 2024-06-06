#include "dependencies.h"
#include "input.h"
#include "stackqueues.h"
#include "inftopostf.h"
#include "postfeval.h"


int main (void)
{
    string input;
    do
    {
        scanf(" %s", input);
        if (strcmp(input, "QUIT") != 0)
        {
            tokenNode * infix = NULL;
            tokenNode * postfix = NULL;
            
            splitToTokens(input, &infix);
            convertInToPost(&infix, &postfix);

            printQueue(postfix);

            evaluatePostfix(&postfix);
            printf("\n");
        }
    } while (strcmp(input, "QUIT") != 0);
    return 0;
}