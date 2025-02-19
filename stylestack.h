#ifndef STYLESTACK_H
#define STYLESTACK_H

#define MAX_STACK 10

typedef struct {
    const char *style[MAX_STACK];
    const char *reset[MAX_STACK];
    int top;
} StyleStack;

void push_style(StyleStack *stack, const char *style, const char *reset) {
    if (stack->top < MAX_STACK) {
        stack->style[stack->top] = style;
        stack->reset[stack->top] = reset;
        stack->top++;
    }
}

const char *pop_style(StyleStack *stack) {
    return stack->top > 0 ? stack->reset[--stack->top] : "";
}

#endif // STYLESTACK_H
