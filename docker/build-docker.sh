#!/usr/bin/env bash

export LC_ALL=C

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/.. || exit

DOCKER_IMAGE=${DOCKER_IMAGE:-dashpay/amerod-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/amerod docker/bin/
cp $BUILD_DIR/src/dash-cli docker/bin/
cp $BUILD_DIR/src/dash-tx docker/bin/
strip docker/bin/amerod
strip docker/bin/dash-cli
strip docker/bin/dash-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
