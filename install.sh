#!/usr/bin/env bash

DIR_ROOT="$(dirname "$(realpath -e $0)")"
DIR_BACKUP="$DIR_ROOT/../backup"
PROJ_NAME="$(basename "$DIR_ROOT")"

DIR_SRC_NVIM="$DIR_ROOT"
DIR_DST_NVIM="/mnt/data/opt/nvim/config/nvim/pack/nvim/start/$PROJ_NAME"

cd "$DIR_ROOT"

if [[ -e "$DIR_DST_NVIM" ]]; then
    printf "\n\033[33mCreating Backup:\033[0m\n"
    if [[ -d "$DIR_BACKUP" ]]; then
        rm -rv "$DIR_BACKUP"
    fi
    cp -rv "$DIR_DST_NVIM" "$DIR_BACKUP"

    printf "\n\033[33mCleaning Previous..\033[0m\n"
    rm -rv "$DIR_DST_NVIM"
fi

printf "\n\033[33mInstalling for NeoVim:\033[0m\n"
mkdir -v "$DIR_DST_NVIM"
cp -rv lua/ colors/ "$DIR_DST_NVIM"

printf "\n\033[33mInstall Finished!\033[0m\n"
