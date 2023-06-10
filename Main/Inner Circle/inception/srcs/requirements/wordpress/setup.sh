#!/bin/bash

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

chown -R www-data:www-data /var/www/*
chown -R 755 /var/www/*

mkdir -p /run/php/
touch /run/php/php7.3-fpm.sock

wp core download --path=${WP_PATH} --allow-root

wp config create --dbname=${MARIADB_DB_NAME} --dbuser=${MARIADB_DB_USER} --dbpass=${MARIADB_DB_PASS} --dbhost=${MARIADB_DB_HOST} --path=${WP_PATH} --allow-root --skip-check

wp core install --url=${WP_URL} --title=${WP_TITLE} --admin_user=${WP_ADMIN_NAME} --admin_password=${WP_ADMIN_PASS} --admin_email=${WP_ADMIN_EMAIL} --allow-root --path=${WP_PATH}

wp user create ${WP_USER_NAME} ${WP_USER_EMAIL} --user_pass=${WP_USER_PASS} --allow-root --path=${WP_PATH}

mv /www.conf /etc/php/7.3/fpm/pool.d/

exec "$@"