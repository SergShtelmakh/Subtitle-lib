#!/bin/bash
set -ev

# Configure and build
pushd build
cmake ..
make
popd
