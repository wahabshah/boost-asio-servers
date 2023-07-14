# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.202.5/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version (use bullseye or stretch on local arm64/Apple Silicon): bullseye, buster, stretch
ARG VARIANT="bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

#** [Optional] Uncomment this section to install additional packages. **
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends build-essential autoconf automake pkg-config quilt libboost-dev cmake netcat gdb

# https://stackoverflow.com/questions/42034606/compiling-standalone-asio-with-makefile-on-linux
ARG ASIO_TEMP_DIR=/tmp/asio
ARG ASIO_TEMP_TAR=/tmp/asio.tar.gz
COPY asio-patches ${ASIO_TEMP_DIR}/patches
RUN wget -O ${ASIO_TEMP_TAR} https://sourceforge.net/projects/asio/files/asio/1.28.0%20%28Stable%29/asio-1.28.0.tar.gz/download \
    && mkdir -p ${ASIO_TEMP_DIR}                                                                                                \
    && tar -xvzf  ${ASIO_TEMP_TAR} --directory ${ASIO_TEMP_DIR} --strip-components=1                                            \
    && cd ${ASIO_TEMP_DIR}                                                                                                      \
    && quilt push                                                                                                               \
    && autoreconf -i                                                                                                            \
    && ./configure                                                                                                              \
    && make                                                                                                                     \
    && make install