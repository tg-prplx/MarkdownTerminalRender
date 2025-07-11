import mdtr

print(mdtr.get_terminal_markdown_string("""### 🚀 MDTRender - Markdown для Терминала (Русская версия)

MDTRender — это **легковесный и быстрый парсер Markdown**, позволяющий рендерить текст  
в ANSI-совместимых терминалах с красивым форматированием.

## 📌 Возможности

- 🔹 **Стилизация текста**:
  - **Жирный**, *курсивный*, __подчеркнутый__, ~~зачеркнутый~~
  - `inline code` для выделения кода

- 🔹 **Форматирование**:
  - Заголовки `#`, `##`, `###`
  - Списки: `-`, `*` (маркированные), `1.`, `2.` (нумерованные)
  - > **Цитаты** с автоматическим выравниванием

- 🔹 **Кодовые блоки**:
  - ```sh``` и ```c``` с автоматическим выравниванием строк
  - Обрамляются рамками для лучшей читаемости

- 🔹 **Полная поддержка ANSI-цветов** для лучшего отображения в терминале

## 🔥 Демонстрация

```c
#include "mdrender.h"
int main() {
    const char *md = "# Привет, MDRender!\n\n**Работает!**";
    printf("%s\n", get_terminal_markdown_string(md));
    return 0;
}
```

## ⚡ Установка

```sh
git clone https://github.com/username/mdrender.git
cd mdrender
make && sudo make install
```

## 📜 Лицензия

Этот проект распространяется под лицензией MIT. Используй на здоровье! 🖖
"""))
