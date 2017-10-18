bool hasMatchingParantheses(string strExpression) {
    size_t size = strExpression.size();
    stack <char> paranStack;
    bool result = true;

    char temp_char;
    size_t i;
    for (i = 0; i < size && result == true; i++) {
        char c = strExpression[i];
        if (c == '(' || c == '[' || c == '{') {
                paranStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (paranStack.empty()) {
                result = false;
                break;
            }
            temp_char = paranStack.top();
                switch (c) {    
                    case ')':
                        if (temp_char != '(') {
                            result = false;
                        }
                        break;
                    case ']':
                        if (temp_char != '[') {
                            result = false;
                        }
                        break;
                    case '}':
                        if (temp_char != '{') {
                            result = false;
                        }
                        break;
                }
            paranStack.pop();
        }
    }
    return result && paranStack.empty();
}
