# PTable
C++ realization of CPrettyTable template class

[![Hits-of-Code](https://hitsofcode.com/github/rdavid/ptable?branch=master)](https://hitsofcode.com/view/github/rdavid/ptable?branch=master)
[![License](https://img.shields.io/badge/license-0BSD-green)](https://github.com/rdavid/ptable/blob/master/LICENSE)

* [About](#about)
* [License](#license)

## About
Hi, I'm [David Rabkin](http://davi.drabk.in). This C++ template prints data in
formatted table. It calculates indentations after all fields are known. There is
example code:

    CPrettyTable<int, const char*, double> tbl("num", "name", "score");
    for (int i = 0; i < 5; ++i) {
      tbl.Add(i + 1, "FooBar", 2.5 * (i + 1));
    }
    tbl.SetCaption("FooBar");
    tbl.Dump(std::cerr);

The code prints following line to standard error stream:

    +-----+[ FooBar ]------+
    | num | name   | score |
    +-----+--------+-------+
    |   1 | FooBar |   2.5 |
    |   2 | FooBar |     5 |
    |   3 | FooBar |   7.5 |
    |   4 | FooBar |    10 |
    |   5 | FooBar |  12.5 |
    +-----+--------+-------+

Build and run test application: `redo ptable && ./ptable`. Install
[Daniel J. Bernstein's redo build system](http://cr.yp.to/redo.html) program by: `brew install redo`.
## License
PTable is copyright [David Rabkin](http://davi.drabk.in) and
available under a [Zero-Claus BSD license](https://github.com/rdavid/ptable/blob/master/LICENSE).
