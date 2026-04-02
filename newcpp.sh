#!/usr/bin/env bash

set -e

NAME=$1

if [ -z "$NAME" ]; then
    echo "Usage: newcpp <project_name>"
    exit 1
fi

# Create structure
mkdir -p "$NAME/src"

# meson.build
cat > "$NAME/meson.build" <<EOF
project('$NAME', 'cpp')

executable('$NAME', ['src/main.cpp'])
EOF

# main.cpp
cat > "$NAME/src/main.cpp" <<EOF
#include <iostream>

int main() {
    std::cout << "Hello, $NAME!\\n";
    return 0;
}
EOF

# .clang-format
cat > "$NAME/.clang-format" <<EOF
BasedOnStyle: LLVM
IndentWidth: 4
TabWidth: 4
UseTab: Never
EOF

echo "✨ Project '$NAME' created."
