#!/usr/bin/env sh

# Local → source ./Repos/str/tests/run_valgrind.sh
# Container → cd /shared && make && cd build && valgrind ./str <command>
# Container → exit
# Local → rm -rf /Users/gui/Repos/str/tests/shared

mkdir -p "/Users/gui/Repos/str/tests/shared"
cp "/Users/gui/Repos/str/Makefile" "/Users/gui/Repos/str/tests/shared/Makefile"
cp -a "/Users/gui/Repos/str/src/" "/Users/gui/Repos/str/tests/shared/src/"
cp -a "/Users/gui/Repos/str/include/" "/Users/gui/Repos/str/tests/shared/include/"

docker build -f /Users/gui/Repos/str/tests/Dockerfile -t valgrind /Users/gui/Repos/shellconf >/dev/null 2>&1

docker run --rm -it -v "/Users/gui/Repos/str/tests/shared:/shared" valgrind bash

# TODO: create script to automatically run UNIT TESTS inside container
# TODO: create script to automatically run VALGRIND TESTS inside container

# TODO: Local unit tests → Docker unit tests → Docker valgrind tests

# // str width
# str width "hello"
# str width "héllo"
# str width "🔥"
# str width "hello\033[31mworld"

# // str height
# str height "$(printf "1\n2\n3")"
# str height "1"
# str height ""

# // str clean
# str clean "$(printf "hello")"
# str clean "$(printf "red:\033[31mtext\033[0m")"
# str clean "$(printf "\033[32mOK\033[0m")"

# // str split
# str split "a,b,c" ","
# str split "a--b--c--" "--"
# str split "" ","

# // str repeat
# str repeat 3 "ha" "-"
# str repeat 1 "yo" "_"
# str repeat 0 "yo" "-"

# // str count
# str count "\n" in "$(printf "a\nb\nc")"
# str count "aa" in "aaaaa"
# str count "x" in "abc"
# str count "" in "abc"