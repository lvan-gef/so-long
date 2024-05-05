#!/usr/bin/env python3

from pathlib import Path

def walk(path: Path):
    for item in path.iterdir():
        if not item.is_file():
            yield from walk(item)
        else:
            yield item

def gen_c_files(path: Path):
    for p in walk(path):
        if str(root) in str(p):
            continue

        if p.suffix != '.c':
            continue

        with open(p, 'r') as f:
            lines = [line for line in f.readlines() if line]

        yield p, lines

def multi_instruct(p: Path, lines: list[str]):
    for i, line in enumerate(lines, start=1):
        if 'while' in line:
            if '--' in line:
                print(f'In file: {p} there is a -- on line: {i}, this can be a norm problem')
            if '++' in line:
                print(f'In file: {p} there is a ++ on line: {i}, this can be a norm problem')
    
    

if __name__ == '__main__':
    root = Path().cwd()
    project_map = root.parent
    
    for p, lines in gen_c_files(project_map):
        multi_instruct(p, lines)
