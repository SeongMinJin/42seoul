DB = /home/seojin/data/mariadb_db
WP = /home/seojin/data/wordpress_db

all: init up

init:
	sudo chmod 666 /var/run/docker.sock
	mkdir -p $(DB)
	mkdir -p $(WP)

up:
	docker compose -f ./srcs/docker-compose.yml up -d
	@command >/dev/null 2>&1
	@cat /hosts > /etc/hosts
	@-echo $$(docker exec nginx hostname -i) seojin.42.fr >> /etc/hosts

down:
	docker compose -f ./srcs/docker-compose.yml down

clean:
	make down
	rm -rf $(DB) $(WP)
	-docker rmi $$(docker images -q)
	-docker volume rm $$(docker volume ls -q)

re:
	make clean
	make all

.PHONY: all init up down clean re
