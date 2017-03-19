#!/bin/bash
set -ev

# Setup display
export DISPLAY=:99.0
sh -e /etc/init.d/xvfb start

# Install Ubuntu packages
sudo add-apt-repository ppa:ntadej/tano -y
sudo apt-get update -qq

# Install Qt
sudo apt-get install qtbase5-dev qtdeclarative5-dev qtdeclarative5-dev-tools qtdeclarative5-qtquick2-plugin qtdeclarative5-test-plugin -y

sudo apt-get install -qq g++-4.8
export CXX="g++-4.8"

# Prepare build environment
mkdir build