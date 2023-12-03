# Minilib-C 🧮

Welcome to **Minilib-C**.

This project challenges you to create a dynamic ELF library in x86-64 assembly language, aiming to reimplement certain functionalities of the standard C library.

## Language and Tools 🛠️

![Assembly](https://img.shields.io/badge/-Assembly-00599C?style=for-the-badge&logo=assembly&logoColor=white)

- **Language:** x86-64 Assembly
- **Compilation:** Via Makefile, including `re`, `clean`, and `fclean` rules.
- **Binary Name:** libasm.so

## Project Overview 🔎

The objective is to create a dynamic ELF library that can partially replace the standard C library. This involves writing assembly code to implement various common C library functions, adhering closely to their standard behavior.

### Core Functions to Implement

- `strlen`: Calculate the length of a string.
- `strchr`: Locate a character in a string.
- `memset`: Fill a block of memory.
- `memcpy`: Copy memory area.
- `strcmp`: Compare two strings.
- `memmove`: Copy memory area handling overlap.
- `strncmp`: Compare two strings up to n characters.
- `strcasecmp`: Compare two strings ignoring case.
- `rindex`: Locate the last occurrence of a character in a string.
- `strstr`: Locate a substring.
- `strpbrk`: Search a string for any of a set of characters.
- `strcspn`: Get the length of a complemented substring.

## Installation and Usage 💾

1. Clone the repository.
2. Compile the library using the provided Makefile.
3. Use `LD_PRELOAD` to preload `libasm.so` when running programs that rely on the reimplemented functions.
4. For detailed guidelines, refer to `minilibc.pdf`.

## License ⚖️

This project is released under the MIT License. See `LICENSE` for more details.
