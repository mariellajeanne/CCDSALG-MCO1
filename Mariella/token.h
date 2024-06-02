/**
 * @author Mariella Jeanne A. Dellosa
 * 
 * Evaluates operators and operands.
*/

#ifndef TOKEN
#define TOKEN

#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef union Token Token;
typedef unsigned char TokenType;

// Token types (operand/operator).
#define UNDEFINED   (unsigned char)'0'
#define OPERAND     (unsigned char)'1'
#define OPERATOR    (unsigned char)'2'

// The token.
union Token {
    int operand;        // Stores an operand.
    char *operator;     // Stores an operator.
};

/**
 * Checks if a character is a number.
 * 
 * @param token {char} A character of a token.
 * @return {int} 1 if the character is a number, 0 otherwise.
*/
int isNumber(char c) {
    return c >= '0' && c <= '9';
}

/**
 * Checks if an operator has a length of 2.
 * 
 * @param first {char} The first character.
 * @param second {char} The second character.
 * @return {int} 1 if the operator's length is 2, 0 otherwise.
*/
int hasLengthTwo(char first, char second) {

    return (first == '>' || first == '<' || first == '!' ||
            first == '=' || first == '&' || first == '|') &&
            (second == '=' || second == '&' || second == '|');
}

/**
 * Returns the priority value of an operator.
 * 
 * @param operator {char *} The string of the operator.
 * @return {int} The operator's priority.
*/
int getPriority(char *operator) {

    if(operator == NULL)
        return 0;

    switch(*operator) {

        case '!':
            if(strlen(operator) == 1)
                return 8;
            else
                return 3;

        case '^':
            return 7;

        case '*':
        case '/':
        case '%':
            return 6;

        case '+':
        case '-':
            return 5;

        case '<':
        case '>':
            return 4;

        case '=':
            return 3;

        case '&':
            return 2;

        case '|':
            return 1;

        default:
            return 0;
    }
}

/**
 * Operates a postfix expression with two operands and one operator.
 * 
 * @param operand_1 {void *} A pointer to the first operand.
 * @param operand_2 {void *} A pointer to the second operand.
 * @param operator {void *} A pointer to the operator.
 * @return {int} The evaluated expression.
*/
int operate(int operand_1, int operand_2, char *operator) {

    if(strlen(operator) == 2) {

        switch(*operator) {
            case '>':
                return operand_1 >= operand_2;
            case '<':
                return operand_1 <= operand_2;
            case '!':
                return operand_1 != operand_2;
            case '=':
                return operand_1 == operand_2;
            case '&':
                return operand_1 && operand_2;
            case '|':
                return operand_1 || operand_2;
        }

    } else {

        switch(*operator) {
            case '+':
                return operand_1 + operand_2;
            case '-':
                return operand_1 - operand_2;
            case '*':   
                return operand_1 * operand_2;
            case '/':
                return operand_1 / operand_2;
            case '%':
                return operand_1 % operand_2;
            case '^':
                return pow(operand_1, operand_2);
            case '>':
                return operand_1 > operand_2;
            case '<':
                return operand_1 < operand_2;
            case '!':
                return !operand_1;
        }
    }

    return -1;
}

#endif