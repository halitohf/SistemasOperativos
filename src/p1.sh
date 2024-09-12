#!/bin/bash
    echo "Hoy es " `date`

    echo "Hola:" $(whoami)

    echo "Tus Nucleos logicos por core" `lscpu | grep -E '^Thread'`

    echo "Tus Nucleos fisico " `lscpu | grep -E '^Core'`