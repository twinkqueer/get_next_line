_This project has been created as part of the 42 curriculum by mpankrat._

# get_next_line

## Description

**get_next_line** is a project from the 42 curriculum that involves creating a function capable of reading a file descriptor line by line.

The goal is to implement a function that returns one line at a time from a file descriptor, including the newline character (`\n`) when present, without reading the entire file into memory at once.

The project introduces several important concepts in C programming:

- File descriptor management.
- Reading files using the `read()` system call.
- Static variables and persistent data.
- Dynamic memory allocation and deallocation.
- String manipulation and buffer management.

### How it works

The implementation uses a static buffer to preserve unread characters between function calls.

1. Read data from the file descriptor using `read()`.
2. Search the buffer for a newline character.
3. If a newline is found, extract and return the line.
4. Shift the remaining characters in the buffer to the beginning.
5. If no newline is found, continue reading and joining the data until a complete line is available.
6. Return the remaining content when the end of the file is reached.

### Project structure

| File | Description |
|---|---|
| `get_next_line.c` | Main function responsible for reading and returning lines. |
| `get_next_line_utils.c` | Helper functions for string manipulation and buffer management. |
| `get_next_line.h` | Header file containing includes, definitions and function prototypes. |

## Instructions

### Requirements

- A C compiler (GCC or Clang).
- Make sure `BUFFER_SIZE` is defined.
- A Unix-like operating system.

### Compilation

Clone the repository:

```bash
git clone https://github.com/twinkqueer/get_next_line.git
cd get_next_line
```

Compile the project together with your own `main.c`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c -o gnl
```

You can change `BUFFER_SIZE` to test different reading sizes:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 \
get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Usage

Include the header in your C file:

```c
#include "get_next_line.h"
```

The function prototype is:

```c
char *get_next_line(int fd);
```

Example:

```c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Return value

- Returns a dynamically allocated string containing the next line.
- Includes `\n` if a newline character is present.
- Returns the remaining content if EOF is reached without a trailing newline.
- Returns `NULL` when there is nothing left to read or when an error occurs.

**Important:** The returned string must be freed by the caller to avoid memory leaks.

## Resources

### Documentation

- [read() — Linux Manual Page](https://man7.org/linux/man-pages/man2/read.2.html)
- [open() — Linux Manual Page](https://man7.org/linux/man-pages/man2/open.2.html)
- [close() — Linux Manual Page](https://man7.org/linux/man-pages/man2/close.2.html)
- [malloc() — Linux Manual Page](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Static Variables in C](https://en.cppreference.com/w/c/language/static_storage_duration.html)

### Learning resources

- Geeks4Geeks
- YouTube
- Google
- Manual pages

### AI Usage

AI tools were used as a supplementary learning resource to help understand concepts, troubleshoot implementation issues and improve documentation. The implementation and code were developed as part of the 42 curriculum.
