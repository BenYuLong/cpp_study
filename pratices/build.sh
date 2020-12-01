#!/bin/bash

set -e

script_dir=$(cd `dirname $0` ; pwd)
source_dir="${script_dir}"
build_dir="${script_dir}/build"

echo script_dir: ${script_dir}
echo source_dir: ${source_dir}
echo build_dir: ${build_dir}

if [ ! -d "${source_dir}" ]; then
    echo [ERROR] src directory ${source_dir} not found!
    # exit 1
fi

PROJECT_NAME="CPP_Pratices"
VERSION="V0.1"
CMAKE_OPTION=""

echo Project: ${PROJECT_NAME}, Version: ${VERSION}


# usage
function usage()
{
cat << EOT
    usage : $0 [options] [--]

    Options:
EOT
}

function build()
{
    echo "building..."

    mkdir $build_dir -p
    cd $build_dir

    cmake $CMAKE_OPTION $source_dir
    make -j | tee build.log

    echo "build done"
}



while getopts "cdhr" opt
do
    case $opt in

        h|help)
            usage
            exit 0
            ;;
        \?)
            usage
            exit 0
            ;;
    esac
done

build

cd $script_dir
