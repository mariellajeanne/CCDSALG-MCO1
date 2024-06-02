
void pushToken (token tokens, tokenNode ** outputStack)
{
    tokenNode * newNode = malloc(sizeof(tokenNode));
    strcpy(newNode->tokens, tokens);
    newNode->next = *outputStack;

    *outputStack = newNode;
}


void pushInt (int operand, intNode ** operandStack)
{
    intNode * newNode = malloc(sizeof(intNode));
    newNode->number = operand;
    newNode->next = *operandStack;

    *operandStack = newNode;
}

tokenNode * locateLast (tokenNode * outputQueue)
{
    if (outputQueue->next != NULL)
        return locateLast(outputQueue->next);
    else
        return outputQueue;
}

void popToken (token output, tokenNode ** tokenList)
{
    if (*tokenList != NULL)
    {
        tokenNode * firstNode = *tokenList;
        *tokenList = firstNode->next;
        strcpy(output, firstNode->tokens);
        free(firstNode);  
    }
}

int popInt (intNode ** tokenList)
{
    int returnVal = 0;
    if (*tokenList != NULL)
    {
        intNode * firstNode = *tokenList;
        *tokenList = firstNode->next;
        returnVal = firstNode->number;
        free(firstNode);  
    }
    return returnVal;
}

void queueToken (token token, tokenNode ** outputQueue)
{
    tokenNode * newNode = malloc(sizeof(tokenNode));
    strcpy(newNode->tokens, token);
    newNode->next = NULL;

    if (*outputQueue == NULL)
    {
        *outputQueue = newNode;
        return;
    }
    
    tokenNode * lastNode = locateLast(*outputQueue);

    lastNode->next = newNode;
}



void printQueue (tokenNode * output)
{
    printf(BLUE"%s "RESET, output->tokens);
    if (output->next != NULL)
        printQueue(output->next);
    else
        printf("\n");    
}
