# 🎨 **`stringui` v1.0.0** – minimal Unicode‑ & ANSI‑aware string CLI

[![C++](https://img.shields.io/badge/language-C%2B%2B17-blue)](https://en.cppreference.com/)
[![Build](https://img.shields.io/badge/build-clang%2B%2B-orange)](https://clang.llvm.org/)
[![Terminal CLI](https://img.shields.io/badge/type-CLI-lightgrey)](https://en.wikipedia.org/wiki/Command-line_interface)
[![Platform: Unix](https://img.shields.io/badge/platform-Unix-darkgreen)](https://en.wikipedia.org/wiki/Unix)
[![Status: v1.0.0](https://img.shields.io/badge/status-v1.0.0-brightgreen)](https://github.com/guillaumeast/stringui/releases/tag/v1.0.0)

> **`stringui`** is a terminal‑friendly, Unicode‑ & ANSI‑aware **string manipulation CLI** — tiny like `cut` or `sed`, but powered by modern **C++17**, escape‑safe, and fully **UTF‑8‑capable** (incl. wide & combined emojis).

---

## ✨ Features

- **UTF‑8 aware** (via [`libunistring`](https://www.gnu.org/software/libunistring/))
- **ANSI / escape‑safe** cleaning & width detection
- **Visual width** handling (CJK, wide & combined emojis)
- **Line height** calculation
- **Substring occurrence counting**
- **Split** & **repeat** helpers
- **POSIX pipe & shell friendly**
- Fast, portable & single‑binary – *no runtime dependencies*

---

## 🚀 Available commands

| Command                                    | Description                                             |
|--------------------------------------------|---------------------------------------------------------|
| `stringui width  <string>`                 | Display *visual* width (columns) of `string`           |
| `stringui height <string>`                 | Display number of *lines* (`\n` count + 1)            |
| `stringui clean  <string>`                 | Strip all ANSI *escape sequences*                      |
| `stringui split  <string> <sep>`           | Split `string` on `sep`, output one part per line      |
| `stringui repeat <count> <string> [sep]`   | Repeat `string` `count` times with optional `sep`      |
| `stringui count  <value> in <string>`      | Count occurrences of `value` inside `string`           |

> `Display width` is measured in `columns`, of `characters` or `strings`, when output to a device that uses `non-proportional fonts`.

> Note that for some rarely used characters the actual `fonts` or `terminal emulators` can use a different `width`. There is no mechanism for communicating the `display width` of `characters` across a Unix pseudo-terminal (`tty`).
> Also, there are scripts with complex rendering, like the `Indic` scripts. For these scripts, there is no such concept as `non-proportional fonts`. Therefore the results of these functions usually work fine on most scripts and on most `characters` but can fail to represent the actual `display width`.

> 📚 See [libunistring documentation – Display width <uniwidth.h>](https://www.gnu.org/software/libunistring/manual/libunistring.html#uniwidth_002eh) for details on how display width is computed.

---

## 🛠️ Build & Install

Clone this repo then run:

```bash
# compile
make

# install library + headers + pkg‑config and CLI binary in ~/.local/bin
sudo make install
```

> ⚠️ Ensure `~/.local/bin` is in your `$PATH` to run `stringui` everywhere.

<details>
  <summary>Install only stringui lib</summary>

```bash
# compile
make

# install library + headers + pkg‑config
sudo make install-lib
```

</details>

<details>
  <summary>Install only stringui cli</summary>

```bash
# compile
make

# install CLI binary in ~/.local/bin
make install-cli
```

</details>

---

## 🧪 Examples


<details>
    <summary>stringui width</summary>
    
```bash
red="$(printf "\033[31m")"                        # ANSI escape code for red
reset="$(printf "\033[0m")"                       # ANSI escape code to reset colors

stringui width "1234"                             # output → "4"
stringui width "1🛑4"                             # output → "4"
stringui width "$(printf "${red}1${reset}🛑4")"   # output → "4"
```

</details>

<details>
    <summary>stringui height</summary>
    
```sh
stringui height "$(printf "1\n2\n3")"             # output → "3"
```

</details>

<details>
    <summary>stringui clean</summary>
    
```sh
red="$(printf "\033[31m")"                   # ANSI escape code for red
reset="$(printf "\033[0m")"                  # ANSI escape code to reset colors

stringui clean "$(printf "${red}Red${reset}")"   # output → "Red"
```

</details>

<details>
    <summary>stringui split</summary>
    
```sh
stringui split "a-b-c" "-"            # output → "a\nb\nc"
```

</details>

<details>
    <summary>stringui repeat</summary>
    
```sh
stringui repeat 3 "foo" "-"           # output → "foo-foo-foo"
```

</details>

---

## 📁 Project structure

```
stringui/
├── include/
│   └── StringUI.hpp
├── src/
│   ├── StringUI.cpp
│   └── main.cpp
├── build/            # autogenerated
├── Makefile
└── README.md
```

---

## 📦 Dependencies

- [`libunistring`](https://www.gnu.org/software/libunistring/) ≥ 1.1
- Any **C++17** compiler (`clang++`, `g++`, …)

---

## 👤 Author

Made with ❤️ by [@guillaumeast](https://github.com/guillaumeast)
