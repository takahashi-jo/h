# h

## Overview

`h` is a command-line utility that integrates `helmenv` and `helm` with `fzf`, offering a streamlined management experience for Helm.

## Getting Started

To prepare for installation, first, create a `bin` directory in your home folder and include it in your system's PATH. This step ensures you can execute scripts and programs from this directory without the need to specify their full path. Execute the commands below to set this up:

```sh
mkdir -p ~/bin
echo 'export PATH="~/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

This process creates the bin directory if it's missing and adds it to the PATH variable in your `.bashrc` file, which configures the bash shell. To activate the changes, either restart your terminal session or source your `.bashrc` file.

## Prerequisites

You need to have the following tools installed before you can use this project:

- `helmenv`: A version manager for Helm that allows you to manage multiple versions of Helm charts and plugins with ease.
- `helm`: The Kubernetes package manager that enables you to define, install, and upgrade even the most complex Kubernetes applications.
- `fzf`: A command-line utility for fuzzy finding.

Follow the installation instructions provided below if these tools are not already installed on your system.

## Installation

### `helmenv`

For installation instructions, visit: https://github.com/yuya-takeyama/helmenv

```sh
git clone https://github.com/yuya-takeyama/helmenv.git ~/bin/.helmenv
echo 'export PATH="$HOME/bin/.helmenv/bin:$PATH"' >> ~/.bashrc
```

### `helm`

```sh
helmenv install 2.16.3
helmenv install 3.8.2
```

### `fzf`

For more information, visit: https://github.com/junegunn/fzf

```sh
git clone --depth 1 https://github.com/junegunn/fzf.git ~/bin/.fzf
~/bin/.fzf/install
```

### `h`

To install, run the following:

```sh
git clone --depth 1 https://github.com/takahashi-jo/h.git ~/bin/h
chmod +x ~/bin/h
```

## Usage

To use the tool, simply execute:

```sh
k
```

## License

This project incorporates tools that are distributed under various licenses:

- **helmenv**: helmenv: A version manager for Helm, available under the MIT License. You can find the license here: [https://github.com/yuya-takeyama/helmenv/blob/master/LICENSE](https://github.com/yuya-takeyama/helmenv/blob/master/LICENSE)
- **fzf**: Released under the MIT License. The license can be found here: [https://github.com/junegunn/fzf/blob/master/LICENSE](https://github.com/junegunn/fzf/blob/master/LICENSE)

Please review each tool's license for specific terms and conditions.