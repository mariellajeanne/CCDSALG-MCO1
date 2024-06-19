/**
 * @author Mariella Jeanne A. Dellosa
 * 
 * Evaluates operators and operands.
*/

#ifndef TOKEN_
#define TOKEN_

#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef union Token Token;
typedef unsigned char TokenType;
typedef unsigned char PriorityType;

// Token types (operand/operator).
#define UNDEFINED   (unsigned char)'0'
#define OPERAND     (unsigned char)'1'
#define OPERATOR    (unsigned char)'2'

// Priority types (in-coming priority / in-stack priority)
#define ICP (unsigned char)'0'
#define ISP (unsigned char)'1'

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
 * @param type {PriorityType} The type of priority being evaluated.
 * @return {int} The operator's priority.
*/
int getPriority(char *operator, PriorityType type) {

    switch(*operator) {

        case '|': return 2;
        case '&': return 3;
        case '=': return 4;
        case '>': case '<': return 5;
        case '+': case '-': return 6;
        case '*': case '/': case '%': return 7;
        
        case '^':
            if(type == ICP) return 9;
            else return 8;
        
        case '!':
            if(strlen(operator) == 2) return 4;
            else if(type == ICP) return 11;
            else return 10;

        case ')':
            if(type == ICP) return 1;
            else return 12;

        case '(':
            if(type == ICP) return 13;
            else return 0;

        default: return -1;
    }
}

/**
 * Operates a postfix expression with two operands and one operator.
 * 
 * @param operand_1 {int} The first operand.
 * @param operand_2 {int} The second operand.
 * @param operator {char *} The operator.
 * @return {int} The evaluated expression.
*/
int operate(int operand_1, int operand_2, char *operator) {

    // Executes if the operator has a length of 2.

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

    // Executes if the operator has a length of 1.

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
