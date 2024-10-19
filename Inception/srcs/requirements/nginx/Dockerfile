FROM	debian:bullseye 
RUN apt-get update \
		&& apt-get install -y \
				vim \
				nginx 

ENTRYPOINT ["nginx", "-g", "daemon off;"]
