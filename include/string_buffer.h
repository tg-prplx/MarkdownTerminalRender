#ifndef STRING_BUFFER_H
#define STRING_BUFFER_H
#include <stddef.h>

typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} StringBuffer;

StringBuffer *string_buffer_create(size_t initial_capacity);
void string_buffer_append_char(StringBuffer *sb, char ch);
void string_buffer_append_string(StringBuffer *sb, const char *str);
char *string_buffer_to_string(StringBuffer *sb);
size_t string_buffer_length(StringBuffer *sb);
void string_buffer_free(StringBuffer *sb);

#endif // STRING_BUFFER_H
