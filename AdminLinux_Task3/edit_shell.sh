#!/bin/bash

if [ -f ~/.zshrc ]; then
    echo "export HELLO=\$(hostname)" >> ~/.zshrc
    echo "LOCAL=\$(whoami)" >> ~/.zshrc
    gnome-terminal
else
    echo "file does NOT exist, creating one..."
    touch ~/.zshrc
fi
