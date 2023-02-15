## PTable [![hits of code](https://hitsofcode.com/github/rdavid/ptable?branch=master&label=hits%20of%20code)](https://hitsofcode.com/view/github/rdavid/ptable?branch=master) [![license](https://img.shields.io/github/license/rdavid/shellbase?color=blue&labelColor=gray&logo=freebsd&logoColor=lightgray&style=flat)](https://github.com/rdavid/ptable/blob/master/LICENSE)
C++ realization of `CPrettyTable` template class.

* [About](#about)
* [License](#license)

### About
Hi, I'm [David Rabkin](http://cv.rabkin.co.il). This C++ template prints data in
formatted table. It calculates indentations after all fields are known. There is
example code:
```c++
CPrettyTable<int, const char*, double> tbl("num", "name", "score");
for (int i = 0; i < 5; ++i) {
	tbl.Add(i+1, "FooBar", 2.5*(i+1));
}
tbl.SetCaption("FooBar");
tbl.Dump(std::cerr);
```
The code prints following line to standard error stream:
```
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
### Build and run
The project uses Daniel J. Bernstein's (aka, djb)
[build system](http://cr.yp.to/redo.html). You can install Sergey Matveev's
[`goredo`](http://www.goredo.cypherpunks.ru/Install.html) implementation.
```sh
redo ptable &&
	ptable
```
### License
`ptable` is copyright [David Rabkin](http://cv.rabkin.co.il) and
available under a [Zero-Claus BSD license](https://github.com/rdavid/ptable/blob/master/LICENSE).
