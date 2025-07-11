#include "stylestack.h"

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

