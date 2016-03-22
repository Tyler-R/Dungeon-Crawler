# Dungeon Crawler

## Library Dependencies

#### Install boost
```bash
$ ./scripts/installBoost.sh
```

#### Install curses
```bash
$ sudo apt-get install libncurses5-dev
```

## Build

```bash
$ git clone https://github.com/Tyler-R/Dungeon-Crawler
$ mkdir build_Dungeon-Crawler
$ cd build_Dungeon-Crawler
$ cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ../Dungeon-Crawler
$ make
```

## Run

#### Server
```bash
./bin/server
```

#### Client
```bash
./bin/client
```
