#ifndef STYLESTACK_H
#define STYLESTACK_H

#define MAX_STACK 10

typedef struct {
    const char *style[MAX_STACK];
    const char *reset[MAX_STACK];
    int top;
} StyleStack;

void push_style(StyleStack *stack, const char *style, const char *reset);
const char *pop_style(StyleStack *stack);

#endif // STYLESTACK_H
