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

RUN DEBIAN_FRONTEND=noninteractive apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        cmake pstack strace linux-tools-common \
        linux-tools-4.4.0-31-generic linux-cloud-tools-4.4.0-31-generic linux-tools-generic linux-cloud-tools-generic \
        libmsgpack-dev protobuf-compiler libprotobuf-dev libprotoc-dev \
        libcurl4-openssl-dev libzmq3-dev \
        python3-dev python3-pip \
        google-perftools libgoogle-perftools-dev \
    && pip3 install pybind11 \
    && cd \
    && git clone https://github.com/chronolaw/cpp_study \
    && mkdir github \
    && cd github \
    && git clone https://github.com/nlohmann/json.git \
    && git clone https://github.com/whoshuu/cpr.git \
    && git clone https://github.com/openresty/luajit2.git \
    && git clone https://github.com/vinniefalco/LuaBridge.git \
    && DEBIAN_FRONTEND=noninteractive apt-get autoremove -y


CMD ["/bin/bash"]
#CMD ["/bin/bash", "-c", "cat /root/cpp_study/hosts >> /etc/hosts;cd /root/cpp_study/www;./run.sh start;/bin/bash"]
