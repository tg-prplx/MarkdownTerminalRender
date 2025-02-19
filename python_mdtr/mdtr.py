import ctypes
mdrender = ctypes.CDLL("./libmdrender.so")
mdrender.get_terminal_markdown_string.restype = ctypes.c_char_p

def get_terminal_markdown_string(string: str) -> str:
    result = mdrender.get_terminal_markdown_string(string.encode("utf-8"))
    return result.decode("utf-8")
