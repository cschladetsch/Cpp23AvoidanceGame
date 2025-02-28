#!/bin/bash

mkdir -p build && cd build && cmake .. && make && ./SDL2Game $@

