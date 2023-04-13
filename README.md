# PTable

[![code ql](https://github.com/rdavid/ptable/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/rdavid/ptable/actions/workflows/codeql-analysis.yml)
[![linters](https://github.com/rdavid/ptable/actions/workflows/lint.yml/badge.svg)](https://github.com/rdavid/ptable/actions/workflows/lint.yml)
[![hits of code](https://hitsofcode.com/github/rdavid/ptable?branch=master&label=hits%20of%20code)](https://hitsofcode.com/view/github/rdavid/ptable?branch=master)
[![license](https://img.shields.io/github/license/rdavid/shellbase?color=blue&labelColor=gray&logo=freebsd&logoColor=lightgray&style=flat)](https://github.com/rdavid/ptable/blob/master/LICENSE)

* [About](#about)
* [Build](#build)
* [License](#license)

## About

The C++ template prints data in formatted table. It calculates indentations
after all fields are known. There is an example code:

```c++
CPrettyTable<int, const char*, double> tbl("num", "name", "score");
for (int i = 0; i < 5; ++i) {
  tbl.Add(i+1, "FooBar", 2.5*(i+1));
}
tbl.SetCaption("FooBar");
tbl.Dump(std::cerr);
```

The code prints following line to standard error stream:

```sh
+-----+[ FooBar ]------+
| num | name   | score |
+-----+--------+-------+
|   1 | FooBar |   2.5 |
|   2 | FooBar |     5 |
|   3 | FooBar |   7.5 |
|   4 | FooBar |    10 |
|   5 | FooBar |  12.5 |
+-----+--------+-------+
```

## Build

The project uses Daniel J. Bernstein's (aka, djb) build system
[`redo`](http://cr.yp.to/redo.html). You can install Sergey Matveev's
[`goredo`](http://www.goredo.cypherpunks.ru/Install.html) implementation.

`redo lint` runs the following linters on the source files:

* [`checkmake`](https://github.com/mrtazz/checkmake)
* [`markdownlint`](https://github.com/igorshubovych/markdownlint-cli)
* [`shellcheck`](https://github.com/koalaman/shellcheck)
* [`shfmt`](https://github.com/mvdan/sh)
* [`yamllint`](https://github.com/adrienverge/yamllint)

`redo test` runs unit tests.

## License

`ptable` is copyright [David Rabkin](http://cv.rabkin.co.il) and available
under a
[Zero-Clause BSD license](https://github.com/rdavid/ptable/blob/master/LICENSE).
