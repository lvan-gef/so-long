#!/usr/bin/env python3

from pathlib import Path

def walk(path: Path):
    for item in path.iterdir():
        if not item.is_file():
            yield from walk(item)
        else:
            yield item


if __name__ == '__main__':
    new_email = 'lvan-gef@student.codam.nl'
    root = Path().cwd()
    project_map = root.parent
    for p in walk(project_map):
        if str(root) in str(p):
            continue

        if p.suffix not in ['.c', '.h']:
            continue

        with open(p, 'r') as f:
            lines = [line for line in f.readlines() if line]

        for line in lines[:11]:
            if new_email in line:
                break
        else:
            line_size = 0
            for i, line in enumerate(lines[:11]):
                if len(line) > line_size:
                    line_size = len(line)
                if '@' in line:
                    print(f'Rename email in file: {p}')
                    begin, tussen = line.split('<')
                    email, einde = tussen.split('>')
                    newline = f'{begin}<{new_email}>{einde}'
                    if len(newline) > line_size:
                        newline = f'{begin}<{new_email}>{einde[len(newline) - line_size:]}'
                    lines.pop(i)
                    lines.insert(i, newline)
                    with open(p, 'w') as f:
                        f.write(''.join(lines))
                    break
