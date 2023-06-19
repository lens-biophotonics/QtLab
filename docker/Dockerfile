# this image is meant to be used to build wrappers for some hardware libraries

FROM ubuntu:jammy

RUN apt-get update && apt-get upgrade -yq && apt-get install -yq coccinelle libpython3.10 && apt-get clean

WORKDIR /home

ENTRYPOINT [ "/bin/bash" ]
