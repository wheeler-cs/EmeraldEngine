# Emerald Engine

This is a modification of the default Pokemon Emerald repo geared towards easier and more portable development. To
accomplish this, a number of changes to the base game and the toolchain itself have been made.

| *Table of Contents* |
|---------------------|
| [Non-Docker Build](#non-docker-build) |
| [Docker Build](#docker-build) |
| [SSH Keys](#ssh-keys) |
| [Distribution](#distribution) |
| [Legal](#legal) |
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

After system packages are installed, [agbcc](https://github.com/pret/agbcc) can be cloned and built. From the directory
that `EmeraldEngine` was cloned into, run the following commands.

```
git clone https://github.com/pret/agbcc
cd agbcc
./build.sh
./install.sh ../EmeraldEngine
```

The final step is to build the ROM. This is done by running the `make` utility inside the `EmeraldEngine` directory.

```
cd EmeraldEngine
make
```

This can be sped up by providing the `-j#` along with `make`, substituting `#` with any number. The number should
generally be less than or equal to the number of threads your CPU has.

```
make -j4
```


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

Building a Docker container handles most of the backend infrastructure, setting up all of the components of the
toolchain for building. The final step of building the ROM requires issuing the `make` command. See the section on
[non-Docker installations](#nondocker-install) for a brief explanation on best practices when using `make`.


## <a id=ssh-keys>SSH Keys</a>
If you wish to use VCS with the development repository, a SSH key is required. In order to install it on the Docker
container, it must have the file name of `github` and be placed in `docker/.ssh/` at the time of building the image.

## <a id=distribution>Distribution</a>
From a legal standpoint, distributing ROM hacks is a grey area at best. If you plan on distributing a ROM hack, it is
recommended to do this in the form of a patch file that can be applied to the original ROM to get the new game.
Several tools exist to do this, with [RomPatcher.js](https://github.com/marcrobledo/RomPatcher.js) being easy to use and
web-based.

## <a id=legal>Legal</a>
This section is intended to inform anyone interested in the project of the legal terms and requirements of the project.
It does not and should not act as a substitute for legal counsel, and it does not cover the full extent of legal terms.

All code is provided as-is with absolutely no warranty of any kind. There is no guarantee of fitness for this code in
any application. Use it at your own risk.

No code in this repository is intended to facilitate the act of piracy. As much code as possible is based on open source
works, and the primary bulk of the project is derived from a decompilation project. No ROMs, BIOSes, or any other
copyrighted digital works are able to be downloaded illegally through the use of this repository. The repository does
not provide compiled ROMs or patch files in order to err on the side of caution.

## <a id=references>References</a>
[Original Decompilation Project Repository](https://github.com/pret/pokeemerald)

[AGBCC Build Tool Repository](https://github.com/pret/agbcc)

[RomPatcher.js](https://github.com/marcrobledo/RomPatcher.js)
