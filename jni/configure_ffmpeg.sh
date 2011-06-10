#!/bin/bash
pushd `dirname $0`
. settings.sh

if [[ $minimal_featureset == 1 ]]; then
  featureflags="--disable-everything \
--enable-decoder=mjpeg --enable-demuxer=mjpeg --enable-parser=mjpeg \
--enable-muxer=mp4 --enable-encoder=libx264 --enable-libx264 \
--enable-protocol=file \
--enable-hwaccels"
fi

pushd ffmpeg

./configure --enable-cross-compile \
--arch=arm5te \
--enable-armv5te \
--target-os=linux \
--disable-stripping \
--prefix=../output \
--disable-neon \
--enable-version3 \
--disable-shared \
--enable-static \
--enable-gpl \
--enable-memalign-hack \
--cc=arm-linux-androideabi-gcc \
--ld=arm-linux-androideabi-ld \
--extra-cflags="-fPIC -DANDROID -D__thumb__ -mthumb" \
$featureflags \
--disable-ffmpeg \
--disable-ffplay \
--disable-ffprobe \
--disable-ffserver \
--disable-network \
#--disable-mpegaudio-hp \
#--disable-avdevice \
--enable-zlib \
--extra-cflags="-I../x264" \
--extra-ldflags="-L../x264" 

popd; popd
