CREATE DATABASE mariadb_db;
CREATE USER 'seojin'@'%' IDENTIFIED BY 'alsdl12';
GRANT ALL PRIVILEGES ON mariadb_db.* TO 'seojin'@'%';
FLUSH PRIVILEGES;