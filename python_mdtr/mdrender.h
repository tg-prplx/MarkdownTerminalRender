#ifndef MDRENDER_H
#define MDRENDER_H
#define _CRT_SECURE_NO_WARNINGS

extern const char *get_terminal_markdown_string(const char *string);
extern void free_rendered_string(const char *string);

#endif // MDRENDER_H
