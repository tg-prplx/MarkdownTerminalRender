import ctypes

mdrender = ctypes.CDLL("./libmdrender.so")
mdrender.get_terminal_markdown_string.restype = ctypes.c_void_p
mdrender.free_rendered_string.argtypes = [ctypes.c_void_p]
mdrender.free_rendered_string.restype = None


def get_terminal_markdown_string(string: str) -> str:
    ptr = mdrender.get_terminal_markdown_string(string.encode("utf-8"))
    text = ctypes.string_at(ptr).decode("utf-8")
    mdrender.free_rendered_string(ptr)
    return text
