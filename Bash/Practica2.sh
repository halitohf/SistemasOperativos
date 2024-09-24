#!/bin/bash

# Variables proporcionadas
REMOTE_USER="so24p"
REMOTE_HOST="pacifico.izt.uam.mx"
SSH_KEY="~/.ssh/id_rsa_jlqf"
OUTPUT_FILE="resultado2.txt"
INTERVALO_MINUTOS=1  # Cambia esto al intervalo en minutos que desees

# Función para monitorear usuarios en el servidor remoto
monitorear_usuarios() {
    # Guardar la hora de monitoreo
    echo "Usuarios conectados en $REMOTE_HOST:" >> $OUTPUT_FILE
    
    # Ejecutar el comando remoto para listar usuarios conectados y guardar en el archivo
    ssh -i $SSH_KEY $REMOTE_USER@$REMOTE_HOST "who" >> $OUTPUT_FILE
    
    echo "-------------------------" >> $OUTPUT_FILE
    
}

# Monitoreo continuo cada X minutos
while true; do
    monitorear_usuarios
    sleep $((INTERVALO_MINUTOS * 60))  # Convierte los minutos a segundos
done
