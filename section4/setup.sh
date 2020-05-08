#!/bin/bash

set -e

linux_distribution() {
    if [ -f /etc/redhat-release ] ; then
        if cat /etc/redhat-release | grep -qi "fedora release" ; then
            echo f$(cat /etc/redhat-release | cut -d " " -f 3)
        elif cat /etc/redhat-release | grep -qi "centos linux release" ; then
            echo c$(cat /etc/redhat-release | cut -d " " -f 4 | cut -d . -f 1)
        fi
    elif grep -qi ubuntu /etc/issue ; then
        echo u$(cat /etc/issue | cut -d " " -f 2 | cut -d . -f 1)
    fi
}

os="$(linux_distribution)"

SUDO=sudo

if [ "$(id -u)" -eq 0 ] ; then
    # some enviroument like in container may missing sudo tools, but already using root
    SUDO=
fi

case $os in
f32|f31|f30|c8)
    # fedora, centos8
    if [ $os == "c8" ] ; then
	$SUDO dnf -y install epel-release
	$SUDO dnf -y install dnf-plugins-core
	$SUDO dnf config-manager --set-enabled PowerTools
    fi
    $SUDO dnf -y install \
        wget make cmake \
        msgpack-devel \
        protobuf-compiler protobuf-devel \
        libcurl-devel openssl-devel \
        czmq-devel cppzmq-devel \
        gperftools-devel \
        pprof \
        pybind11-devel python3-devel python3-pybind11
    ;;
u20|u18|u16|u*)
    # ubuntu
    $SUDO apt-get update
    $SUDO apt-get remove libcurl4 -y
    $SUDO apt-get install -y \
        wget cmake \
        libmsgpack-dev \
        protobuf-compiler \
        libprotobuf-dev \
        libcurl4-openssl-dev \
        libzmq3-dev \
        libgoogle-perftools-dev
    ;;
*)
    echo os not supported
    exit 1
esac


# json
md5sum_json_hpp=39b754f6834e64406d7eae9dfb9e5d9e
checksum=""

if [ -f json.hpp ] ; then
    checksum=$(md5sum json.hpp | awk '{print $1}')
fi

if [ "$checksum" != "$md5sum_json_hpp" ] ; then
    wget https://github.com/nlohmann/json/releases/download/v3.7.3/json.hpp -O json.hpp
fi


# install cpr
if [ ! -f cpr/include/cpr/cpr.h -o ! -f cpr/lib/libcpr.a ] ; then
    rm -fr cpr
    git clone https://github.com/whoshuu/cpr.git cpr
    cd cpr
    cmake . -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF
    make -j
    cd ..
fi

# install luajit
if [ ! -f /usr/local//include/luajit-2.1/luajit.h ] ; then
    rm -fr luajit2
    # git clone https://github.com/openresty/luajit2.git luajit2
    git clone https://gitee.com/mirrors/luajit2.git luajit2
    cd luajit2
    make && make install
    cd ..
fi

if [ ! -f LuaBridge/Source/LuaBridge/LuaBridge.h ] ; then
    rm -fr LuaBridge
    git clone https://github.com/vinniefalco/LuaBridge.git LuaBridge
fi

touch setup.done

