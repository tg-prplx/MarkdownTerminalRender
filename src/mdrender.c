#include <string.h>
#include <stdint.h>
#include "string_buffer.h"
#include "styles.h"
#include "stylestack.h"

static void sv_char(StringBuffer *sb, const char *string, int64_t *i, int64_t len, StyleStack *stack, int is_newline, int *in_code_block) {
    while (*i < len) {
        char ch = string[*i];
        (*i)++;

        if (!(*in_code_block)) {
            if (is_newline && ch == '>' && *i < len && string[*i] == ' ') {
                (*i)++;
                push_style(stack, quote_style, reset_quote);
                string_buffer_append_string(sb, quote_style);
                string_buffer_append_string(sb, "│ ");
                continue;
            }

            if (is_newline && (ch == '-' || ch == '*') && *i < len && string[*i] == ' ') {
                (*i)++;
                string_buffer_append_string(sb, "• ");
                continue;
            }

            if (is_newline && (ch >= '0' && ch <= '9')) {
                int temp_i = *i;
                while (temp_i < len && string[temp_i] >= '0' && string[temp_i] <= '9') temp_i++;
                if (temp_i < len && string[temp_i] == '.') {
                    (*i) = temp_i + 1;
                    string_buffer_append_char(sb, ch);
                    string_buffer_append_char(sb, '.');
                    string_buffer_append_char(sb, ' ');
                    continue;
                }
            }

            switch (ch) {
            case '#':
            {
                int level = 1;
                while (*i < len && string[*i] == '#') {
                    level++;
                    (*i)++;
                }
                if (*i < len && string[*i] == ' ') (*i)++;

                if (level == 1) {
                    push_style(stack, header1, reset_header1);
                    string_buffer_append_string(sb, header1);
                } else if (level == 2) {
                    push_style(stack, header2, reset_header2);
                    string_buffer_append_string(sb, header2);
                } else {
                    push_style(stack, header3, reset_header3);
                    string_buffer_append_string(sb, header3);
                }
            }
            break;

            case '\n':
                while (stack->top > 0) {
                    string_buffer_append_string(sb, pop_style(stack));
                }
                string_buffer_append_char(sb, ch);
                sv_char(sb, string, i, len, stack, 1, in_code_block);
                return;

            case '*':
                if (*i < len && string[*i] == '*') {
                    (*i)++;
                    if (stack->top > 0 && stack->style[stack->top - 1] == bold) {
                        string_buffer_append_string(sb, pop_style(stack));
                    } else {
                        push_style(stack, bold, reset_bold);
                        string_buffer_append_string(sb, bold);
                    }
                } else {
                    if (stack->top > 0 && stack->style[stack->top - 1] == cursive) {
                        string_buffer_append_string(sb, pop_style(stack));
                    } else {
                        push_style(stack, cursive, reset_cursive);
                        string_buffer_append_string(sb, cursive);
                    }
                }
                break;

            case '_':
                if (*i < len && string[*i] == '_') {
                    (*i)++;
                    if (stack->top > 0 && stack->style[stack->top - 1] == underline) {
                        string_buffer_append_string(sb, pop_style(stack));
                    } else {
                        push_style(stack, underline, reset_underline);
                        string_buffer_append_string(sb, underline);
                    }
                }
                break;

            case '~':
                if (*i < len && string[*i] == '~') {
                    (*i)++;
                    if (stack->top > 0 && stack->style[stack->top - 1] == crossed) {
                        string_buffer_append_string(sb, pop_style(stack));
                    } else {
                        push_style(stack, crossed, reset_crossed);
                        string_buffer_append_string(sb, crossed);
                    }
                }
                break;

            case '`':
                if (*i + 1 < len && string[*i] == '`' && string[*i + 1] == '`') {
                    (*i) += 2;
                    if (*in_code_block) {
                        string_buffer_append_string(sb, pop_style(stack));
                        *in_code_block = 0;
                    } else {
                        push_style(stack, inline_code, reset_inline_code);
                        string_buffer_append_string(sb, inline_code);
                        *in_code_block = 1;
                    }
                    continue;
                }
                break;

            default:
                string_buffer_append_char(sb, ch);
                break;
            }

        } else {
            if (ch == '`' && *i + 1 < len && string[*i] == '`' && string[*i + 1] == '`') {
                (*i) += 2;
                string_buffer_append_string(sb, pop_style(stack));
                *in_code_block = 0;
            } else {
                string_buffer_append_char(sb, ch);
            }
        }
    }
}

const char *get_terminal_markdown_string(const char *string) {
    int64_t len = (int64_t)strlen(string);
    StringBuffer *sb = string_buffer_create((size_t)len);

    StyleStack stack = { .top = 0 };
    int64_t i = 0;
    int in_code_block = 0;

    sv_char(sb, string, &i, len, &stack, 1, &in_code_block);

    while (stack.top > 0) {
        string_buffer_append_string(sb, pop_style(&stack));
    }

    char *result = string_buffer_to_string(sb);
    string_buffer_free(sb);

    return result;
}

