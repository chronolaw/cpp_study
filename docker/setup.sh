#!/bin/sh

# chrono @ 2021-03

# apt-get
DEBIAN_FRONTEND=noninteractive apt-get install -y \
        vim cmake gdb pstack strace  \
        libmsgpack-dev protobuf-compiler libprotobuf-dev libprotoc-dev \
        libcurl4-openssl-dev libzmq3-dev \
        python3-dev python3-pip \
        google-perftools libgoogle-perftools-dev

DEBIAN_FRONTEND=noninteractive apt-get autoremove -y

# python3 pybind11
pip3 install pybind11

#WORKDIR='/root/'
#HOME='/root'

# git source code
git clone https://github.com/chronolaw/cpp_study --depth=1

# setup env
cp ${HOME}/cpp_study/env/vimrc     ${HOME}/.vimrc \
cp ${HOME}/cpp_study/env/bashrc    ${HOME}/.bashrc \
cp ${HOME}/cpp_study/env/gitconfig ${HOME}/.gitconfig \

# source

JSON_VERSION="3.9.1"
CPR_VERSION="1.4.0"
LUAJIT_VERSION="2.1-20200102"
LUABRIDAGE_VERSION="2.6"
GPERF_VERSION="2.8"

#echo ${JSON_VERSION}
#echo ${HOME}

mkdir ${HOME}/github
cd ${HOME}/github

# test
#exit

# json
curl -fsL https://github.com/nlohmann/json/releases/download/v${JSON_VERSION}/json.hpp -o json.hpp
ln -s ~/github/json.hpp ~/cpp_study/common/

# curl/cpr
curl -fsL https://github.com/whoshuu/cpr/archive/${CPR_VERSION}.tar.gz -o cpr.tgz
tar xfz cpr.tgz
cd cpr-${CPR_VERSION}
cmake . -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF
make && make install && make clean
cd ..

# luajit
curl -fsL https://github.com/openresty/luajit2/archive/v${LUAJIT_VERSION}.tar.gz -o luajit.tgz
tar xfz luajit.tgz
cd luajit2-${LUAJIT_VERSION}
make && make install && make clean
ln -s /usr/local/lib/libluajit-5.1.so.2 /lib/x86_64-linux-gnu/
cd ..

# luabridge
curl -fsL https://github.com/vinniefalco/LuaBridge/archive/${LUABRIDAGE_VERSION}.tar.gz -o LuaBridge.tgz
tar xfz LuaBridge.tgz
ln -s ~/github/LuaBridge-${LUABRIDAGE_VERSION}/Source/LuaBridge/  ~/cpp_study/common/

# gperftools
curl -fsL https://github.com/gperftools/gperftools/releases/download/gperftools-${GPERF_VERSION}/gperftools-${GPERF_VERSION}.tar.gz -o gperf.tgz
tar xfz gperf.tgz
ln -s ~/github/gperftools-${GPERF_VERSION}/pprof-symbolize /bin/pprof

# flame graph
git clone https://github.com/brendangregg/FlameGraph.git --depth=1
ln -s ~/github/FlameGraph/flamegraph.pl ~/cpp_study/section4/

# clean
rm *.tgz

