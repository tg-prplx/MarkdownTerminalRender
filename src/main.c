#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mdrender.h"

int main() {
    char md[1024];

    if (!fgets(md, sizeof(md), stdin)) {
        fprintf(stderr, "Ошибка ввода\n");
        return 1;
    }

    md[strcspn(md, "\n")] = 0;

    const char *result = get_terminal_markdown_string(md);

    if (!result) {
        fprintf(stderr, "Ошибка обработки Markdown\n");
        return 1;
    }

    printf("%s\n", result);

    if (result != md) {
        free((void *)result);
    }

    return 0;
}
