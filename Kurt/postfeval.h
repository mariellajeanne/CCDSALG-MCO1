int computeBinOperation (int firstOperand, token operator, int secondOperand)
{
    switch (operator[0])
    {
        case '+':
            return firstOperand + secondOperand;
        case '-':
            return firstOperand - secondOperand;
        case '*':
            return firstOperand * secondOperand;
        case '/':
            return firstOperand / secondOperand;
        case '%':
            return firstOperand / secondOperand;
        case '^':
            return (int)pow(firstOperand, secondOperand);
        case '<':
            if (operator[1] == '=')
                return firstOperand <= secondOperand;
            else
                return firstOperand < secondOperand;
        case '>':
            if (operator[1] == '=')
                return firstOperand >= secondOperand;
            else
                return firstOperand > secondOperand;
        case '=':
            return firstOperand == secondOperand;
        case '&':
            return firstOperand && secondOperand;
        case '|':
            return firstOperand || secondOperand;
        case '!':
            return firstOperand != secondOperand; 
        default:
            return 0;
    }
}

int computeUnOperation (int operand, token operator)
{
    switch (operator[0])
    {
        case '!':
            return !operand;
        default:
            return 0;
    }
}


void evaluatePostfix(tokenNode ** source)
{
    intNode * outputStack = NULL;
    token currentToken;
    int operand[2];
    int placeholder;
    while (*source != NULL)
    {
        popToken(currentToken, source); 
        if (isdigit(currentToken[0]))
            pushInt(atoi(currentToken), &outputStack);
        else if (strcmp(currentToken, "!") == 0)
        {
            placeholder = computeUnOperation(popInt(&outputStack), currentToken);
            pushInt(placeholder, &outputStack);
        }
        else
        {

            operand[1] = popInt(&outputStack);
            operand[0] = popInt(&outputStack);
            if (operand[1] == 0 && strcmp(currentToken, "/") == 0)
            {
                printf(RED"Division by zero error!"RESET"\n");
                return;
            }
            placeholder = computeBinOperation(operand[0], currentToken, operand[1]);
            pushInt(placeholder, &outputStack);
        }
    }
    placeholder = outputStack->number;
    free(outputStack);
    printf(GREEN"%i"RESET"\n", placeholder);
}