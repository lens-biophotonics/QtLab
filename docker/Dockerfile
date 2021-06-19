# this image is meant to be used to build wrappers for some hardware libraries

FROM debian:buster-slim

RUN apt-get update && apt-get upgrade -yq && apt-get install -yq --no-install-recommends coccinelle && apt-get clean

WORKDIR /home

ENTRYPOINT [ "/bin/bash" ]
