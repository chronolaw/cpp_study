# Dockerfile
# chrono@2020-09

# curl -fsSL https://get.docker.com | bash -s docker --mirror Aliyun
# sudo service docker start
# sudo usermod -aG docker ${USER}

# docker image build -t chronolaw/cpp_study .

# docker run -it chronolaw/cpp_study bash
# docker run -it --rm chronolaw/cpp_study bash

# docker login
# docker image push chronolaw/cpp_study
# docker image pull chronolaw/cpp_study

ARG SRC_IMAGE="chronolaw/http_study"

FROM ${SRC_IMAGE}

#LABEL version="2020-09"
#        linux-tools-4.4.0-31-generic linux-cloud-tools-4.4.0-31-generic linux-tools-generic linux-cloud-tools-generic 
#        python3-dev python3-pip 
#        google-perftools libgoogle-perftools-dev 
#        graphviz 
#    && pip3 install pybind11 
#    && DEBIAN_FRONTEND=noninteractive apt-get autoremove -y

RUN DEBIAN_FRONTEND=noninteractive apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        gcc-multilib g++-multilib \
        cmake pstack strace linux-tools-common \
        libmsgpack-dev protobuf-compiler libprotobuf-dev \
        libcurl4-openssl-dev libzmq3-dev \
    && cd \
    && git clone https://github.com/chronolaw/cpp_study \
    && mkdir github \
    && cd github \
    && curl -fsL https://github.com/nlohmann/json/releases/download/v3.9.1/json.hpp -o json.hpp \
    && cp json.hpp ~/cpp_study/common \
    && curl -fsL https://github.com/whoshuu/cpr/archive/v1.5.1.tar.gz -o cpr.tgz \
    && curl -fsL https://github.com/openresty/luajit2/archive/v2.1-20200102.tar.gz -o luajit.tgz \
    && curl -fsL https://github.com/vinniefalco/LuaBridge/archive/2.6.tar.gz -o LuaBridge.tgz \
    && git clone https://github.com/brendangregg/FlameGraph.git 


CMD ["/bin/bash"]
#CMD ["/bin/bash", "-c", "cat /root/cpp_study/hosts >> /etc/hosts;cd /root/cpp_study/www;./run.sh start;/bin/bash"]
