#ifndef STYLES_H
#define STYLES_H

// ANSI Codes

char bold[] = "\033[1m";
char reset_bold[] = "\033[22m";

char cursive[] = "\033[3m";
char reset_cursive[] = "\033[23m";

char underline[] = "\033[4m";
char reset_underline[] = "\033[24m";

char crossed[] = "\033[9m";
char reset_crossed[] = "\033[29m";

char inline_code[] = "\033[48;5;240m\033[38;5;15m";
char reset_inline_code[] = "\033[0m";

char quote_style[] = "\033[90m";
char reset_quote[] = "\033[0m";

char header1[] = "\033[1;34m";
char reset_header1[] = "\033[0m";

char header2[] = "\033[1;32m";
char reset_header2[] = "\033[0m";

char header3[] = "\033[1;36m";
char reset_header3[] = "\033[0m";

char code_block[] = "\033[48;5;240m\033[30m";
char reset_code_block[] = "\033[0m";



#endif // STYLES_H
