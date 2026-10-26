#!/bin/bash

find ./ \
    \( \
        -iname '*.c' -o \
        -iname '*.cpp' -o \
        -iname '*.h' -o \
        -iname '*.hpp' \
    \) \
    -not -path '.git/*' \
    -print0 | \
    xargs -0 -r clang-format -i
