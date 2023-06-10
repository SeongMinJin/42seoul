FROM debian:buster

MAINTAINER seojin <seojin@student.42seoul.kr>

LABEL purpose = 'Database for wordpress' \
	version = '1.0' \
	description = 'Database for wordpress user and data'

RUN apt-get update && apt-get upgrade -y && apt-get install -y mariadb-server vim procps

COPY ./setup.sql /setup.sql
COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN service mysql start && mariadb < /setup.sql

CMD mysqld
