# set to path of your NDK

NDK=~/Apps/android-ndk-r5c
# i use only a small number of formats - set this to 0 if you want everything.
minimal_featureset=1

## stop editing

if [[ ! -d $NDK ]]; then
  echo "$NDK is not a directory. Exiting."
  exit 1
fi

function current_dir {
  echo "$(cd "$(dirname $0)"; pwd)"
}

export PATH=$PATH:$NDK:$(current_dir)/toolchain/bin

echo $PATH

