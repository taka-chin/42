FROM	debian:bullseye 
RUN apt-get update \
		&& apt-get install -y \
				vim \
				curl 

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
RUN useradd -ms /bin/bash wpuser
RUN chown -R wpuser:wpuser /var/www/html
USER wpuser
RUN wp core download --locale=ja --path=/var/www/html

