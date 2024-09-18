#! /bin/bash

SRCS_DIR="src"
TEST_DIR="test"

function main {
  find . -name "*.cpp" -o -name "*.hpp" -o -name "*.c" |
    xargs clang-format -i || return 1
  return 0
}

main "$@"
