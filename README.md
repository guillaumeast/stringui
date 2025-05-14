# 🔠 **`unistring` v1.0.0** – stable and minimal Unicode-aware ANSI-aware string CLI

[![C++](https://img.shields.io/badge/language-C%2B%2B17-blue)](https://en.cppreference.com/)
[![Build](https://img.shields.io/badge/build-clang%2B%2B-orange)](https://clang.llvm.org/)
[![Terminal CLI](https://img.shields.io/badge/type-CLI-lightgrey)](https://en.wikipedia.org/wiki/Command-line_interface)
[![Platform: Unix](https://img.shields.io/badge/platform-Unix-darkgreen)](https://en.wikipedia.org/wiki/Unix)
[![Status: v1.0.0](https://img.shields.io/badge/status-v1.0.0-brightgreen)](https://github.com/guillaumeast/unistring/releases/tag/v1.0.0)


> 🧠 **`str`** is a `terminal`‑friendly, `Unicode`‑ & `ANSI`‑aware **string manipulation CLI** — minimal like `cut` or `sed`, but powered by modern **C++17**, `escape`‑safe, and fully `UTF‑8`‑capable (including wide & combined emojis).

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

| Command                                       | Description                                                                 |
|-----------------------------------------------|-----------------------------------------------------------------------------|
| `str width  <string>`                         | Display *visual* width (columns) of `string`                                |
| `str height <string>`                         | Display number of *lines* (`\n` count + 1)                                 |
| `str clean  <string>`                         | Strip all ANSI *escape sequences*                                           |
| `str split  <string> <sep>`                   | Split `string` on `sep`, output one part per line                           |
| `str repeat <count> <string> [sep]`           | Repeat `string` `count` times with optional `sep` between                   |
| `str count  <value> in <string>`              | Count occurrences of `value` inside `string`                                |

> **Display width** is measured in *columns* for terminals that use fixed‑width fonts.
> Some characters (e.g. Indic scripts) or emulators may render differently.

---

## 🛠️ Build & Install

```sh
make            # compile to bin/str
make install    # copy binary to ~/.local/bin/str
make uninstall  # remove binary from ~/.local/bin
```

The binary will be available as `str` anywhere in your shell, provided `~/.local/bin` is in your `$PATH`.

---

## 🧪 Examples

<details>
<summary>str width / height</summary>

```bash
red="[31m"
reset="[0m"

str width  "1🛑4"               # → 4
str height "a
b
c"            # → 3
str width  "${red}1${reset}🛑4" # → 4 (ignores escapes)
```
</details>

<details>
<summary>str clean</summary>

```bash
str clean "${red}Red${reset}"   # → "Red"
```
</details>

<details>
<summary>str split</summary>

```bash
str split "a-b-c" "-"           # → "a
b
c"
```
</details>

<details>
<summary>str repeat</summary>

```bash
str repeat 3 "foo" "-"          # → "foo-foo-foo"
```
</details>

<details>
<summary>str count</summary>

```bash
str count "-" in "a-b-c-d-"     # → 4
```
</details>

---

## 📁 Project structure

```
str/
├── include/
│   ├── UniString.hpp
│   └── types.hpp
├── src/
│   ├── UniString.cpp
│   └── main.cpp
├── tests/
├── bin/              # build output (ignored)
├── Makefile
└── README.md
```

---

## 📦 Dependencies

- [`libunistring`](https://www.gnu.org/software/libunistring/) ≥ 1.1
- Any **C++17** compiler (`clang++`, `g++`, ...)

---

## 🧑 Author

Made with ❤️ by [@guillaumeast](https://github.com/guillaumeast)
