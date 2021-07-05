FROM phusion/baseimage:bionic-1.0.0
LABEL maintainer="Amero Developers <dev@amero.org>"
LABEL description="Dockerised AmeroCore, built from Travis"

ARG USER_ID
ARG GROUP_ID

ENV HOME /amero

# add user with specified (or default) user/group ids
ENV USER_ID ${USER_ID:-1000}
ENV GROUP_ID ${GROUP_ID:-1000}
RUN groupadd -g ${GROUP_ID} amero
RUN useradd -u ${USER_ID} -g amero -s /bin/bash -m -d /amero amero
RUN mkdir /amero/.amerocore
RUN chown amero:amero -R /amero

COPY bin/* /usr/local/bin/

RUN chmod a+x /usr/local/bin/*

USER amero

VOLUME ["/amero"]

EXPOSE 9998 9999 19998 19999

WORKDIR /amero
