int precedenceOf (token operator)
{   
    switch (operator[0])
    {
        case '(': case ')': return 9;
        case '!':
            if (operator[1] == '=')
                return 3;
            else
                return 8;
        case '^': return 7;
        case '*': case '/': case '%': return 6;
        case '+': case '-': return 5;
        case '>': case '<': return 4;
        case '=': return 3;
        case '&': return 2;
        case '|': return 1;
        default: return 0;
    }
}

int precedenceNode(tokenNode * tokens)
{
    if (tokens == NULL)
        return 0;
    else
        return precedenceOf(tokens->tokens) - (tokens->tokens[0] == '^' || tokens->tokens[0] == '!');    
}

void convertInToPost (tokenNode ** input, tokenNode ** output)
{
    int index = 0;
    token operatorContainer;
    token currentToken;
    tokenNode * operators = NULL;
    while (*input != NULL)
    {
        popToken(currentToken, input);
         
        if (isdigit(currentToken[0]))
        {
            queueToken(currentToken, output);
        }
        else
        {
            if (currentToken[0] == ')')
            {
                while (strcmp(operators->tokens, "(") != 0)
                {
                    popToken(operatorContainer, &operators);
                    queueToken(operatorContainer, output);
                }
                popToken(operatorContainer, &operators);
                   
            }
            else if (operators != NULL)
            {           
                while (precedenceOf(currentToken) <= precedenceNode(operators)  
                    && strcmp(operators->tokens, "(") != 0)
                {
                    popToken(operatorContainer, &operators);
                    queueToken(operatorContainer, output);
                }
                pushToken(currentToken, &operators);
            }
            else
                pushToken(currentToken, &operators);
        }
        index++;
    }
    while (operators != NULL)
    {
        popToken(operatorContainer, &operators);
        queueToken(operatorContainer, output);
    }
    free(operators);
}
