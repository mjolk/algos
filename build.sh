#!/bin/sh

DIR="build/$1"
BUILD_TYPE="$2"

rm -rf "$DIR"
mkdir -p "$DIR"
cmake -S. -B"$DIR" -DCMAKE_BUILD_TYPE="$BUILD_TYPE" -GNinja
