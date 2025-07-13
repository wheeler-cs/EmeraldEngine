# Base image
FROM debian:latest

# Use bash
SHELL ["/bin/bash", "-c"]

# Install packages
RUN apt update
RUN apt install build-essential binutils-arm-none-eabi git libpng-dev pkgconf vim -y

# Initialize user
RUN useradd -ms /bin/bash emdev
USER emdev
WORKDIR "/home/emdev"

# Build tools for project
RUN git clone https://github.com/wheeler-cs/EmeraldEngine
RUN git clone https://github.com/pret/agbcc
RUN cd agbcc && ./build.sh && ./install.sh ../EmeraldEngine

# Copy SSH
RUN mkdir .ssh
COPY .ssh/* .ssh/

# Setup repo git
WORKDIR "/home/emdev/EmeraldEngine"
RUN git remote remove origin
RUN git remote add engine https://github.com/wheeler-cs/EmeraldEngine
RUN git remote add decomp https://github.com/pret/pokeemerald

# Set command to use on start
CMD ["/bin/bash"]
