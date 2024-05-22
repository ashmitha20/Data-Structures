#include <stdio.h>
#include <math.h>

void main(){

    char n[100];
    printf("Enter in the infix expression : ");
    scanf("%s", &n);

    char stack[100];
    char ans[100];

    int counter1 = 0, counter2 = 0, counter3 = 0;
    
    while(n[counter1] != NULL){
        if(n[counter1] >= 'A' && n[counter1] <= 'Z'){
            ans[counter2] = n[counter1];
            counter2++;
        }
        else if(n[counter1] == '(' || n[counter1] == ')'){
            if(n[counter1] == '('){
                counter3++;
                stack[counter3] = n[counter1];
            }
            else{
                while(stack[counter3] != '('){
                    ans[counter2] = stack[counter3];
                    counter3--;
                    counter2++;
                }
                counter3--;
            }
        }
        else{
            if(n[counter1] == '+' || n[counter1] == '-'){
                if(stack[counter3] == '+' || stack[counter3] == '-' || stack[counter3] == '/' || stack[counter3] == '*' || stack[counter3] == '^'){
                    ans[counter2] = stack[counter3];
                    counter2++;
                    stack[counter3] = n[counter1];
                }
                else{
                    counter3++;
                    stack[counter3] = n[counter1];
                }
            }
            else if(n[counter1] == '/' || n[counter1] == '*'){
                if(stack[counter3] == '/' || stack[counter3] == '*'|| stack[counter3] == '^'){
                    ans[counter2] = stack[counter3];
                    counter2++;
                    stack[counter3] = n[counter1];
                }
                else{
                    counter3++;
                    stack[counter3] = n[counter1];
                }
            }
            else{
                if(stack[counter3] == '^'){
                    ans[counter2] = stack[counter3];
                    counter2++;
                    stack[counter3] = n[counter1];
                }
                else{
                    counter3++;
                    stack[counter3] = n[counter1];
                }
            }
        }
        counter1++;
    }
    printf("%s", ans);

    int stack2[100];
    int counter4 = -1, counter5 = 0;
    int finalans;

    while(ans[counter5] != NULL){

        if(ans[counter5] >= 'A' && ans[counter5] <= 'Z'){
            printf("Enter in the value of %c", ans[counter5]);
            counter4++;
            scanf("%d", &stack2[counter4]);
        }
        else{
            if(ans[counter5] == '+'){
                finalans = stack2[counter4] + stack2[counter4-1];
                counter4 --;
                stack2[counter4] = finalans;
            }
            else if(ans[counter5] == '-'){
                finalans = stack2[counter4] - stack2[counter4-1];
                counter4 --;
                stack2[counter4] = finalans;
            }
            else if(ans[counter5] == '/'){
                finalans = stack2[counter4] / stack2[counter4-1];
                counter4 --;
                stack2[counter4] = finalans;
            }
            else if(ans[counter5] == '*'){
                finalans = stack2[counter4] * stack2[counter4-1];
                counter4 --;
                stack2[counter4] = finalans;
            }
            else{
                finalans = pow(stack2[counter4], stack2[counter4-1]);
                counter4 --;
                stack2[counter4] = finalans;
            }
            printf("%d", stack2[counter4]);
        }
        counter5++;
    }
    printf("%d", stack2[counter4]);

}