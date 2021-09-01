#!/opt/bin/lv_micropython
import uos as os
import uerrno as errno
iter = os.ilistdir()
IS_DIR = 0x4000
IS_REGULAR = 0x8000
index = 0

try:
    while True:
        entry = next(iter)
        filename = entry[0]
        file_type = entry[1]
        if filename == 'main.py':
            continue
        else:
            if file_type == IS_DIR:
                continue
            else:
                exec(open(filename).read(), globals())
        if index == 100:
            break
        index += 1
except StopIteration:
    pass