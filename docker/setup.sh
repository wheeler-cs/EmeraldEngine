#!/bin/bash

git clone https://github.com/wheeler-cs/EmeraldEngine
git clone https://github.com/pret/agbcc
cd agbcc && ./build.sh && ./install.sh ../EmeraldEngine
cd EmeraldEngine && make -j$(nproc)
cd EmeraldEngine && git remote remove origin
