# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.202.5/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version (use bullseye or stretch on local arm64/Apple Silicon): bullseye, buster, stretch
ARG VARIANT="bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

#** [Optional] Uncomment this section to install additional packages. **
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends build-essential libboost-dev cmake netcat gdb

RUN wget -O /tmp/asio.tar.gz https://sourceforge.net/projects/asio/files/asio/1.28.0%20%28Stable%29/asio-1.28.0.tar.gz/download \
     && mkdir -p /usr/local/lib/asio                                                                                            \ 
     && tar -xvzf  /tmp/asio.tar.gz --directory /usr/local/lib/asio --strip-components=1