# textadventure

## Library Dependencies
---
* **Discalimer!!!: don't run sudo on school computers, IT will be notified.**
* **REQUIRE SUDO access**

#### Install boost

```shell
$ bash sudoBoostInstall.sh
```

#### Install curses
---

```shell
$ sudo apt-get install libncurses5-dev
```

## Build
---
```bash
$ git clone https://csil-git1.cs.surrey.sfu.ca/373-15-3-piragua/textadventure.git
$ cd textadventure
$ mkdir <tmpbuild>
$ cd <tmpbuild>
$ cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ /path/to/project/
```
## Iterations
---
1. **Oct 14**
2. **Nov 4**
3. **Dec 7**