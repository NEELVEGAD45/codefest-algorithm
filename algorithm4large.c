#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FORMULA_LEN 100001

typedef long long int ll;

int main() {
    int T;
    scanf("%d", &T); // Number of test cases
    for(int i=1; i<=T; i++) {
        char formula[MAX_FORMULA_LEN];
        scanf("%s", formula); // Read the formula as a string
        int answer;
        scanf("%d", &answer); // Read the expected answer
        ll result = 0;
        ll num = 0;
        char op = '+';
        bool has_mul_or_div = false;
        ll mul_or_div_result = 1;
        for(int j=0; j<strlen(formula); j++) {
            if(formula[j] >= '0' && formula[j] <= '9') {
                num = num*10 + formula[j]-'0';
            }
            if(formula[j] == '+' || formula[j] == '-') {
                if(has_mul_or_div) {
                    if(op == '*') mul_or_div_result *= num;
                    else mul_or_div_result /= num;
                    num = mul_or_div_result;
                    has_mul_or_div = false;
                }
                if(op == '+') result += num;
                else if(op == '-') result -= num;
                op = formula[j];
                num = 0;
            }
            if(formula[j] == '*' || formula[j] == '/') {
                if(has_mul_or_div) {
                    if(op == '*') mul_or_div_result *= num;
                    else mul_or_div_result /= num;
                }
                else {
                    has_mul_or_div = true;
                    mul_or_div_result = num;
                }
                op = formula[j];
                num = 0;
            }
        }
        if(has_mul_or_div) {
            if(op == '*') mul_or_div_result *= num;
            else mul_or_div_result /= num;
            num = mul_or_div_result;
        }
        if(op == '+') result += num;
        else if(op == '-') result -= num;
        if(result == answer) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
}