#!/bin/bash

# Imprime el número de CPUs físicas
echo "CPUs físicas: $(grep -c "^physical id" /proc/cpuinfo)"

# Imprime el número de CPUs lógicas
echo "CPUs lógicas: $(nproc --all)"
