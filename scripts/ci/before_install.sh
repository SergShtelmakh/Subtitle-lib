#!/bin/bash
set -ev

# Setup display
export DISPLAY=:99.0
sh -e /etc/init.d/xvfb start

# Install Ubuntu packages
sudo add-apt-repository ppa:ntadej/tano -y
sudo apt-get update -qq

sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
sudo apt-get update -qq
if [ "$CXX" = "g++" ]; then sudo apt-get install -qq g++-4.8; fi
if [ "$CXX" = "g++" ]; then export CXX="g++-4.8" CC="gcc-4.8"; fi

# Install Qt
if [ $QT_VERSION -eq 5 ]
then
    sudo apt-get install qtbase5-dev qtdeclarative5-dev qtdeclarative5-dev-tools qtdeclarative5-qtquick2-plugin qtdeclarative5-test-plugin -y
else
    sudo apt-get install libqt4-dev -y
fi

# Prepare build environment
mkdir build
