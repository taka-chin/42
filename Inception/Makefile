.PHONY: build
build:
	@docker compose -f ./srcs/docker-compose.yml  build

.PHONY: up
up:
	@docker compose -f ./srcs/docker-compose.yml up -d

.PHONY: build-up
build-up: build up
