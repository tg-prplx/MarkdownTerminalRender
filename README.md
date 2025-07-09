![image](https://github.com/user-attachments/assets/336e8bcf-7b2f-463a-9202-d6cfb5d7dbce)

# 🚀 MDTRender - Markdown for the Terminal

MDTRender is a **lightweight and fast Markdown parser** that lets you render text  
in ANSI-compatible terminals with beautiful formatting.

## 📌 Features

- 🔹 **Text styling:**
  - **Bold**, _italic_, **underline**, ~strikethrough~
  - `inline code` highlighting
- 🔹 **Formatting:**
  - Headings `#`, `##`, `###`
  - Lists: `-`, `*` (bulleted), `1.`, `2.` (numbered)
  - > **Quotes** with automatic alignment
- 🔹 **Code blocks:**
  - ```sh``` and ```c``` with automatic line alignment
  - Framed for better readability
- 🔹 **Full ANSI color support** for the best terminal display

## 🔥 Demo

```c
#include "mdrender.h"
int main() {
    const char _md = "# Hello, MDRender!\n\n_*It works!**";
    printf("%s\n", get_terminal_markdown_string(md));
    return 0;
}
```

## ⚡ Installation

```sh
git clone https://github.com/username/mdrender.git
cd mdrender
make && sudo make install
```

## 📜 License

This project is distributed under the MIT license. Use it freely! 🖖
