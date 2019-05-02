# Iniciar un contenedor con InfluxDB

docker run --name influxdb -d -p 8086:8086 -v $PWD:/var/lib/influxdb influxdb

# Compilar y ejecutar el programa para generar el dataset

g++ dataset_generator.cpp

./a.out -k8

# Copiar el dataset al contenedor

docker cp dataset_antartida.txt influxdb:/

# Conectarse al bash del contenedor

docker exec -it influxdb bash

# Importar el dataset en InfluxDB

influx -import -path=dataset_antartida.txt -precision=s

# Conectarse al shell de InfluxDB

influx

# Ejecutar varias consultas

USE ANTARTIC_research_database

SHOW measurements

SHOW SERIES

SHOW TAG KEYS

SHOW TAG VALUES WITH KEY = "randtag"

SHOW FIELD KEYS 

# Para visualizar con interfaz grafica

sudo docker run --name grafana -d -p 3000:3000 grafana/grafana
