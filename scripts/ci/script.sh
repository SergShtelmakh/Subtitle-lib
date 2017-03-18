#!/bin/bash
set -ev

# Configure and build
pushd build
cmake ..
make
# Run tests (Qt5 only) - temporarily removed due to Travis issues
# if [ $QT_VERSION -eq 5 ]
# then
#     make test
# fi
make install
popd