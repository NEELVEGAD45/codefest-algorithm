#include <stdio.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T); // Number of test cases
    for(int i=1; i<=T; i++) {
        char formula[101];
        scanf("%s", formula); // Read the formula as a string
        int answer;
        scanf("%d", &answer); // Read the expected answer
        int result = 0;
        int num = 0;
        char op = '+';
        for(int j=0; formula[j]!='\0'; j++) {
            if(formula[j] >= '0' && formula[j] <= '9') {
                num = num*10 + formula[j]-'0';
            }
            if(formula[j] == '+' || formula[j] == '-' || formula[j] == '*' || formula[j] == '/') {
                if(op == '+') result += num;
                else if(op == '-') result -= num;
                else if(op == '*') result *= num;
                else if(op == '/') result /= num;
                op = formula[j];
                num = 0;
            }
        }
        if(op == '+') result += num;
        else if(op == '-') result -= num;
        else if(op == '*') result *= num;
        else if(op == '/') result /= num;
        if(result == answer) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
} 