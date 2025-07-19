# Base image
FROM debian:latest

# Use bash
SHELL ["/bin/bash", "-c"]

# Install packages
RUN apt update
RUN apt install build-essential binutils-arm-none-eabi git libpng-dev pkgconf vim -y

# Add new user
RUN useradd -ms /bin/bash emdev

# Setup SSH for GitHub
RUN mkdir .ssh
COPY .ssh/* .ssh/
RUN chown -R emdev:emdev .ssh/*
RUN chmod 700 .ssh
RUN chmod 600 .ssh/github
RUN chmod 755 .ssh/config

# Initialize user
USER emdev
WORKDIR "/home/emdev"

# Build tools for project
RUN git clone https://github.com/wheeler-cs/EmeraldEngine
RUN git clone https://github.com/pret/agbcc
RUN cd agbcc && ./build.sh && ./install.sh ../EmeraldEngine

# Setup repo git
WORKDIR "/home/emdev/EmeraldEngine"
RUN git remote remove origin
RUN git remote add engine https://github.com/wheeler-cs/EmeraldEngine
RUN git remote add decomp https://github.com/pret/pokeemerald

# Set command to use on start
CMD ["/bin/bash"]
