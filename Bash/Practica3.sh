#!/bin/bash

REMOTE_USER="so24p"
REMOTE_HOST="pacifico.izt.uam.mx"
SSH_KEY="~/.ssh/id_rsa_jlqf"
OUTPUT_FILE="resultado3.txt"
INTERVALO_MINUTOS=1

monitorear_recursos() {
    echo "Monitoreando CPU y memoria en $REMOTE_HOST" >> $OUTPUT_FILE
    
    ssh -i $SSH_KEY $REMOTE_USER@$REMOTE_HOST << 'EOF' >> $OUTPUT_FILE
    
    # Monitorear uso de CPU
    echo "Uso de CPU:"
    top -bn1 | grep "Cpu(s)" | awk '{print 100 - $8 "% utilizado"}'
    
    # Monitorear uso de memoria
    echo "Uso de Memoria:"
    free -h | grep "Mem:" | awk '{print $3 " usado de " $2}'
EOF

    echo "-------------------------" >> $OUTPUT_FILE
}

while true; do
    monitorear_recursos
    sleep $((INTERVALO_MINUTOS * 60))  # Convierte los minutos a segundos
done
