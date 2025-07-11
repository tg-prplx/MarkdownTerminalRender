#include "string_buffer.h"
#include <stdlib.h>
#include <string.h>

StringBuffer *string_buffer_create(size_t initial_capacity) {
    StringBuffer *sb = malloc(sizeof(StringBuffer));
    sb->data = malloc(initial_capacity);
    sb->data[0] = '\0';
    sb->size = 0;
    sb->capacity = initial_capacity;
    return sb;
}

static void string_buffer_grow(StringBuffer *sb, size_t min_capacity) {
    while (sb->capacity < min_capacity) {
        sb->capacity = (size_t)(sb->capacity * 1.5);
    }
    sb->data = realloc(sb->data, sb->capacity);
}

void string_buffer_append_char(StringBuffer *sb, char ch) {
    if (sb->size + 1 >= sb->capacity) {
        string_buffer_grow(sb, sb->size + 2);
    }
    sb->data[sb->size++] = ch;
    sb->data[sb->size] = '\0';
}

void string_buffer_append_string(StringBuffer *sb, const char *str) {
    size_t len = strlen(str);
    if (sb->size + len >= sb->capacity) {
        string_buffer_grow(sb, sb->size + len + 1);
    }
    memcpy(sb->data + sb->size, str, len);
    sb->size += len;
    sb->data[sb->size] = '\0';
}

char *string_buffer_to_string(StringBuffer *sb) {
    return strdup(sb->data);
}

size_t string_buffer_length(StringBuffer *sb) {
    return sb->size;
}

void string_buffer_free(StringBuffer *sb) {
    free(sb->data);
    free(sb);
}

