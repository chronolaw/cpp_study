# Dockerfile
# chrono@2020-09

# curl -fsSL https://get.docker.com | bash -s docker --mirror Aliyun
# sudo service docker start
# sudo usermod -aG docker ${USER}

# docker build -t chronolaw/cpp_study .

# docker run -it chronolaw/cpp_study bash
# docker run -it --rm chronolaw/cpp_study bash

# docker login
# docker image push chronolaw/cpp_study
# docker image pull chronolaw/cpp_study

ARG SRC_IMAGE="gcc:7"

FROM ${SRC_IMAGE}

#LABEL version="2020-09"

#        gcc-multilib g++-multilib
#        linux-tools-common
#        linux-tools-4.4.0-31-generic linux-cloud-tools-4.4.0-31-generic linux-tools-generic linux-cloud-tools-generic
#        graphviz
#    && mkdir -p cpp_study/common \

ARG JSON_VERSION="3.9.1"
ARG CPR_VERSION="1.4.0"
ARG LUAJIT_VERSION="2.1-20200102"
ARG LUABRIDAGE_VERSION="2.6"
ARG GPERF_VERSION="2.8"

RUN DEBIAN_FRONTEND=noninteractive apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        vim cmake gdb pstack strace  \
        libmsgpack-dev protobuf-compiler libprotobuf-dev libprotoc-dev \
        libcurl4-openssl-dev libzmq3-dev \
        python3-dev python3-pip \
        google-perftools libgoogle-perftools-dev \
    && pip3 install pybind11 \
    && cd \
    && git clone https://github.com/chronolaw/cpp_study \
    && mkdir github \
    && cd github \
    && curl -fsL https://github.com/nlohmann/json/releases/download/v${JSON_VERSION}/json.hpp -o json.hpp \
    && ln -s ~/github/json.hpp ~/cpp_study/common/ \
    && curl -fsL https://github.com/whoshuu/cpr/archive/${CPR_VERSION}.tar.gz -o cpr.tgz \
    && tar xfz cpr.tgz \
    && cd cpr-${CPR_VERSION} \
    && cmake . -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF \
    && make && make install \
    && cd .. \
    && curl -fsL https://github.com/openresty/luajit2/archive/v${LUAJIT_VERSION}.tar.gz -o luajit.tgz \
    && tar xfz luajit.tgz \
    && cd luajit2-${LUAJIT_VERSION} \
    && make && make install \
    && ln -s /usr/local/lib/libluajit-5.1.so.2 /lib/x86_64-linux-gnu/ \
    && cd .. \
    && curl -fsL https://github.com/vinniefalco/LuaBridge/archive/${LUABRIDAGE_VERSION}.tar.gz -o LuaBridge.tgz \
    && tar xfz LuaBridge.tgz \
    && ln -s ~/github/LuaBridge-${LUABRIDAGE_VERSION}/Source/LuaBridge/  ~/cpp_study/common/ \
    && curl -fsL https://github.com/gperftools/gperftools/releases/download/gperftools-${GPERF_VERSION}/gperftools-${GPERF_VERSION}.tar.gz -o gperf.tgz \
    && tar xfz gperf.tgz \
    && ln -s ~/github/gperftools-${GPERF_VERSION}/pprof-symbolize /bin/pprof \
    && git clone https://github.com/brendangregg/FlameGraph.git \
    && ln -s ~/github/FlameGraph/flamegraph.pl ~/cpp_study/section4/ \
    && rm *.tgz \
    && echo "set nu" >> ~/.vimrc \
    && echo "sy on" >> ~/.vimrc \
    && echo "set mouse=" >> ~/.vimrc \
    && echo "set tabstop=4" >> ~/.vimrc \
    && echo "alias ll='ls -l'" >> ~/.bashrc \
    && echo "alias l='ls -lh'" >> ~/.bashrc \
    && echo "alias vi='vim'" >> ~/.bashrc \
    && echo "set -o vi" >> ~/.bashrc \
    && DEBIAN_FRONTEND=noninteractive apt-get autoremove -y


CMD ["/bin/bash"]
#CMD ["/bin/bash", "-c", "cat /root/cpp_study/hosts >> /etc/hosts;cd /root/cpp_study/www;./run.sh start;/bin/bash"]
