#include<stdio.h>

typedef struct stack_A{
    int top;
    int element[10];
}stack;

void createStack(stack *s)
{
    s->top=-1;
}

int isEmptystack(stack *s)
{
    if (s->top==-1)
        return 1;
    else
        return 0;
}

int isFullstack(stack *s)
{
    if (s->top==9)
        return 1;
    else
        return 0;
}

void pushStack(stack *s, int value)
{
    int res = isFullstack(s);

    if (res==1){
        printf("Stack OVERFLOW !!\n");
        return;
    }
    
    else{
        s->top++;
        s->element[s->top]=value;
        printf("\nValue entered: %d", value);
    }
}

int popStack(stack *s)
{
    int res = isEmptystack(s);

    if (res==1){
        printf("Stack UNDERFLOW !!\n");
    }

    else{
        int val = s->element[s->top];
        --(s->top);
        return val;
    }
}

int peekStack(stack *s)
{
    return s->top;
}

void showMenu()
{
    printf("\nChoose one of the below:\n1. Create stack\n2. Check if stack is empty\n3. Check if stack is full\n4. Insert a value\n5. Delete last value\n6. Peek into a stack\n7. Show stack\n8. Exit\n\n");
}

void traverseStack(stack *s)
{
    for (int i=0; i<=s->top; ++i)
        printf("%d ", s->element[i]);
}

int main()
{
    stack s;
    char ch;

    do{
        A:

        if (ch=='n')
            break;
        
        B:

        showMenu();

        int choice, value, last, index;

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createStack(&s);
                printf("\nStack created!\n");
                break;
            
            case 2:
                if (isEmptystack(&s)==1)
                    printf("Yes, stack is empty!\n\n");
                else
                    printf("No, the stack is not empty!\n\n");
                
                break;
            
            case 3:
                if (isFullstack(&s)==1)
                    printf("Yes, stack is full!\n\n");
                else
                    printf("No, the stack is not full!\n\n");
                
                break;
            
            case 4:
                printf("\nEnter a value: ");
                scanf("%d", &value);

                pushStack(&s, value);

                break;
            
            case 5:
                last = popStack(&s);

                printf("Value removed: %d\n\n", last);

                break;

            case 6:
                index = peekStack(&s);

                printf("Stack pointer is at %d index.", index);

                break;

            case 7:
                if (isEmptystack(&s))
                    printf("\n\nStack is EMPTY!");
                else
                {
                    printf("\n\nArray...\n");
                    traverseStack(&s);
                }

                break;

            case 8:
                printf("Thank You! :)");
                ch='n';

                goto A;
                break;

            default:
                printf("Wrong Choice! Try again...");
                goto B;
        }

        C:

        printf("\n\nDo you want to continue? (y/n) -> ");
        fflush(stdin);
        scanf("%c", &ch);

        if (ch=='n')
            printf("Thank You! See you later :)");

        else if (ch!='y' && ch!='n'){
            printf("Sorry! I didn't understand! Enter again...\n");
            goto C;
        }

    }while(ch=='y');
    
    return 0;
}