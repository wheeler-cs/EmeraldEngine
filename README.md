# Emerald Engine

This is a modification of the default Pokemon Emerald repo geared towards easier and more portable development. To
accomplish this, a number of changes to the base game and the toolchain itself have been made.

| *Table of Contents* |
|---------------------|
| [Non-Docker Build](#non-docker-build) |
| [Docker Build](#docker-build) |
| [SSH Keys](#ssh-keys) |
| [References](#references) |

This repo can be built either on bare metal or in a Docker container. Opting to not build in a container does require a
bit more work, but it is not too terribly involved. For Windows systems, it is recommended to install WSL. Other methods
of installation exist, and a more detailed summary can be found in [INSTALL.md](INSTALL.md).

## <a id=nondocker-install>Non-Docker Build</a>
The first step is to ensure all the needed packages for building are installed on your machine. These are:

```
build-essential
binutils-arm-none-eabi
git
libpng-dev
pkgconf 
```

For systems that use `apt`, the following can be ran to set this up.

```
sudo apt update
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev pkgconf -y
```

After system packages are installed, [setup.sh](setup.sh) can be ran to pull, build, and install the toolchain for
development. It is important to note that this script is intended to work with Linux systems, and it may or may not
work on Windows. At the very least, GNU Make will have to be installed on the system.

After this, the code and built ROM can be found in the `EmeraldEngine` directory.


## <a id=docker-install>Docker Build</a>
Using Docker allows for a self-contained environment for building and development. To build the Docker image, Docker
has to be installed on the host system. For Windows, WSL (preferably WSL2) is also required. After installation, the
image can be built using the following.

```
cd docker
docker build -t emeraldimage .
```

This will run through all of the steps required to create an environment for building. Please note that this may take
some time to complete as this build everything from the ground up. The image that results from this can act as a base
state that can be referenced in the future if a container gets messed up.

After the image is done building, a container has to be spawned using it as a template. This is done using the following
command.

```
docker run --name enginedev -it emeraldimage
```

When this command is ran, a new container is created from the image built earlier and started in the background.
Connecting to it can be done using `docker attach` from the command line, or by using plugins in your IDE. VSCode offers
several extensions that can do this.

At this point, the container should be set up to the point where it can be used for development.


## <a id=ssh-keys>SSH Keys</a>
If you wish to use VCS with the development repository, a SSH key is required. In order to install it on the Docker
container, it must have the file name of `github` and be placed in `docker/.ssh/` at the time of building the image.

## <a id=references>References</a>
[Original Decompilation Project Repository](https://github.com/pret/pokeemerald)

[AGBCC Build Tool Repository](https://github.com/pret/agbcc)
