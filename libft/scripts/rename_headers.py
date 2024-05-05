#!/usr/bin/env python3

from pathlib import Path
from pprint import pprint

def walk(path: Path):
    for item in path.iterdir():
        if not item.is_file():
            yield from walk(item)
        else:
            yield item

if __name__ == '__main__':
    # old_headers = ['#include "headers/libft.h"', '#include "headers/get_next_line.h"', '#include "headers/get_next_line_bonus.h"', '#include "ft_printf.h"']
    # new_headers = ['#include "../headers/libft.h"', '#include "../headers/get_next_line.h"', '#include "../headers/get_next_line_bonus.h"', '#include "../headers/ft_printf.h"']
    old_headers = ['#include "../headers/libft.h"', '#include "../headers/get_next_line.h"', '#include "../headers/get_next_line_bonus.h"', '#include "../headers/ft_printf.h"']
    new_headers = ['#include "../headers/libft.h"', '#include "../headers/libft.h"', '#include "../headers/libft.h"', '#include "../headers/libft.h"']

    root = Path().cwd()
    project_map = root.parent
    for file in walk(project_map):
        if str(root) in str(file):
            continue

        if file.suffix != '.c':
            continue

        with open(file, 'r') as f:
            lines = [line for line in f.readlines() if line]
        for i, header in enumerate(old_headers):
            for index, line in enumerate(lines):
                if header in line:
                    print('file:', file, 'replace:', header, new_headers[i])
                    lines.pop(index)
                    lines.insert(index, f'{new_headers[i]}\n')
                    with open(file, 'w') as f:
                        f.write(''.join(lines).strip())
                    break

