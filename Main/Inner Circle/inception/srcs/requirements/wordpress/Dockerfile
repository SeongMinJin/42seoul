FROM debian:buster

MAINTAINER seojin <seojin@student.42seoul.kr>

LABEL purpose = 'wordpress' \
	version = '1.0' \
	description = 'wordpress'

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y wget vim procps curl php7.3 php-fpm php7.3-mysql

COPY ./www.conf /
COPY ./setup.sh /

ENTRYPOINT ["bash", "/setup.sh"]
CMD /usr/sbin/php-fpm7.3 --nodaemonize
