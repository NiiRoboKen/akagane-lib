#!/bin/bash

find ./ -iname *.c -o -iname *.cpp -o -iname *.h -o -iname *.hpp | xargs clang-format -i
