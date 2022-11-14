#!/usr/bin/env/bash

set -x

SOURCES=$(find $(git rev-parse --show-toplevel) | egrep "\.[ch]\$")

for file in ${SOURCES};
do
        clang-format-12 -style=file ${file} > expected-format
        diff -u -p --label="${file}" --label ="expected coding style" ${file} expected-format
done

rm expected-format

exit $(clang-format-12 -style=file --output-replacements-xml ${SOURCES} | egrep -c "</replacement>")
