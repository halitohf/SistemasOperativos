#!/bin/bash

# Imprime el número de CPUs físicas
echo "CPUs físicas: $(grep -c "^physical id" /proc/cpuinfo)"

# Imprime el número de CPUs lógicas
echo "CPUs lógicas: $(nproc --all)"

# Imprime la cantidad de memoria en Gb
echo "Uso de Memoria:"
    free -h | grep "Mem:" | awk '{print $3 " usado de " $2}'
