#include <stdio.h>
#include "mdrender.h"

int main() {
    const char *md =
        "# 🚀 MDRender - Markdown для Терминала\n"
        "\n"
        "MDRender — это **легковесный и быстрый парсер Markdown**, позволяющий рендерить текст\n"
        "в ANSI-совместимых терминалах с красивым форматированием.\n"
        "\n"
        "## 📌 Возможности\n"
        "\n"
        "- 🔹 **Стилизация текста**:\n"
        "  - **Жирный**, *курсивный*, __подчеркнутый__, ~~зачеркнутый~~\n"
        "  - `inline code` для выделения кода\n"
        "\n"
        "- 🔹 **Форматирование**:\n"
        "  - Заголовки `#`, `##`, `###`\n"
        "  - Списки: `-`, `*` (маркированные), `1.`, `2.` (нумерованные)\n"
        "  - > **Цитаты** с автоматическим выравниванием\n"
        "\n"
        "- 🔹 **Кодовые блоки**:\n"
        "  - ```sh``` и ```c``` с автоматическим выравниванием строк\n"
        "  - Обрамляются рамками для лучшей читаемости\n"
        "\n"
        "- 🔹 **Полная поддержка ANSI-цветов** для лучшего отображения в терминале\n"
        "\n"
        "## 🔥 Демонстрация\n"
        "\n"
        "```c\n"
        "#include \"mdrender.h\"\n"
        "\n"
        "int main() {\n"
        "    const char *md = \"# Привет, MDRender!\\n\\n**Работает!**\";\n"
        "    printf(\"%s\\n\", get_terminal_markdown_string(md));\n"
        "    return 0;\n"
        "}\n"
        "```\n"
        "\n"
        "## ⚡ Установка\n"
        "\n"
        "```sh\n"
        "git clone https://github.com/username/mdrender.git\n"
        "cd mdrender\n"
        "make && sudo make install\n"
        "```\n"
        "\n"
        "## 📜 Лицензия\n"
        "\n"
        "Этот проект распространяется под лицензией MIT. Используй на здоровье! 🖖\n";



    const char *result = get_terminal_markdown_string(md);
    printf("%s\n", result);
    free((void *)result);
    return 0;
}
