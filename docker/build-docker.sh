#!/usr/bin/env bash

export LC_ALL=C

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/.. || exit

DOCKER_IMAGE=${DOCKER_IMAGE:-ameropay/amerox-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/amerox docker/bin/
cp $BUILD_DIR/src/amero-cli docker/bin/
cp $BUILD_DIR/src/amero-tx docker/bin/
strip docker/bin/amerox
strip docker/bin/amero-cli
strip docker/bin/amero-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
