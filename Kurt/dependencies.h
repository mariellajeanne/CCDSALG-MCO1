#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN   "\x1B[38;5;120m\x1B[48;5;0m"
#define RED     "\x1B[38;5;203m\x1B[48;5;0m"
#define BLUE    "\x1B[38;5;81m\x1B[48;5;0m"
#define RESET   "\x1B[0m"

typedef char string[256]; 

typedef char token[11];

typedef struct intNode
{
    int number;
    struct intNode * next;
} intNode;

typedef struct tokenNode
{
    token tokens;
    struct tokenNode * next;
}tokenNode;

//input
void scanOperand (string input, token operand);
void scanOperator (string input, token operator);
void splitToTokens(string input, tokenNode ** output);

//stackqueues
void pushToken (token tokens, tokenNode ** outputStack);
void pushInt (int operand, intNode ** operandStack);
tokenNode * locateLast (tokenNode * outputQueue);
void popToken (token output, tokenNode ** tokenList);
int popInt (intNode ** tokenList);
void queueToken (token token, tokenNode ** outputQueue);
void printQueue (tokenNode * output);

//inftopostf
void convertInToPost (tokenNode ** input, tokenNode ** output);
int precedenceOf (token operator);

//postfeval
int computeBinOperation (int firstOperand, token operator, int secondOperand);
int computeUnOperation (int operand, token operator);
void evaluatePostfix(tokenNode ** source);