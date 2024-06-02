void scanOperand (string input, token operand)
{
    int digitChecker;
    int index = 0;
    do
    {
        digitChecker = isdigit(input[0]);
        if (digitChecker)
        {
            operand[index] = input[0];
            strcpy(input, input + 1);
            index++;
        }
    } while (digitChecker);
}

void scanOperator (string input, token operator)
{
    token operatorContainer = "";
    int increment = 1;

    operatorContainer[0] = input[0];
    if (!(input[1] == '(' || input[1] == ')' || input[0] == '(' || input[0] == ')' || isdigit(input[1])))
    {
        operatorContainer[1] = input[1];
        increment++;
    }
    strcpy(operator, operatorContainer);
    strcpy(input, input + increment);
    
}

void splitToTokens(string input, tokenNode ** output)
{
    token container;
    do
    {
        if (isdigit(input[0]))
            scanOperand(input, container);
        else
            scanOperator(input, container);
        queueToken(container, output);
    } while (strcmp(input, "") != 0);
}