#!/bin/bash

if test -f "tools/lipx/lipx"; then
    ./tools/lipx/lipx create pokeemerald.gba pokeberyl.gba pokeberyl.ips
else
    cd tools/lipx && make && cd ../..
    ./tools/lipx/lipx create pokeemerald.gba pokeberyl.gba pokeberyl.ips
fi
