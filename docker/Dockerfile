# this image is meant to be used to build wrappers for some hardware libraries

FROM ubuntu:bionic

RUN apt-get update && apt-get upgrade -yq && apt-get install -yq --no-install-recommends software-properties-common
RUN add-apt-repository -y ppa:npalix/coccinelle && apt-get install -yq --no-install-recommends coccinelle

WORKDIR /home

ENTRYPOINT [ "/bin/bash" ]
