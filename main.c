#include <stdio.h>

int main()
{
    char line[500];
    fgets(line, 500, stdin);
    unsigned char memory[30000];
    for (int i = 0; i <= 30000; i++)
    {
        memory[i] = 0;
    }
    int current_ptr = 0;
    int context_stack[30000];
    int context_stack_size = 0;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line
                [i] == '+')
        {
            memory[current_ptr]++;
        }
        else if (line[i] == '-')
        {
            memory[current_ptr]--;
        }
        else if (line[i] == '>')
        {
            if (current_ptr == 29999)
            {
                current_ptr = 0;
            }
            else
            {
                current_ptr++;
            }
        }
        else if (line[i] == '<')
        {
            if (current_ptr == 0)
            {
                current_ptr = 29999;
            }
            else
            {
                current_ptr--;
            }
        }
        else if (line[i] == '.')
        {
            putchar('c');
            printf("%c", memory[current_ptr]);
        }
        else if (line[i] == ',')
        {
            memory[current_ptr] = getchar();
        }
        else if (line[i] == '[')
        {
            context_stack[context_stack_size + 1] = current_ptr;
        }
        else if (line[i] == ']')
        {
            if (memory[current_ptr] != 0)
            {
                current_ptr = context_stack[context_stack_size];
            }
            else
            {
                context_stack_size--;
            }
        }
    }
}