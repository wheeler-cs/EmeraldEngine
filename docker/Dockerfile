# Base image
FROM debian:latest

# Use bash
SHELL ["/bin/bash", "-c"]

# Install packages
RUN apt update
RUN apt install build-essential binutils-arm-none-eabi git libpng-dev pkgconf -y

# Initialize user
RUN useradd -ms /bin/bash emdev
USER emdev
COPY .ssh/* ~/.ssh/

# Install code for development
WORKDIR "/home/emdev"
RUN git clone https://github.com/wheeler-cs/EmeraldEngine
RUN git clone https://github.com/pret/agbcc
RUN cd agbcc && ./build.sh && ./install.sh ../EmeraldEngine
WORKDIR "/home/emdev/EmeraldEngine"
RUN git remote remove origin

# Build ROM
RUN make -j$(nproc)


CMD ["/bin/bash"]
