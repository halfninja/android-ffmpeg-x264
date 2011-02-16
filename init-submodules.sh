#!/bin/bash

ls -A `dirname $0`/ffmpeg/* 2>&1 1>/dev/null

if [ $? == 0 ]; then
  echo "ffmpeg directory isn't empty. Have you already done this?"
  exit 1
fi

git submodule init
git config -l
git submodule update
