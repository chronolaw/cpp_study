#!/bin/bash

# json
wget https://github.com/nlohmann/json/releases/download/v3.7.3/json.hpp

# sudo apt-get update

# msgpack
sudo apt-get install libmsgpack-dev -y

# protobuf
sudo apt-get install protobuf-compiler -y
sudo apt-get install libprotobuf-dev -y

# curl
sudo apt-get remove libcurl4 -y
sudo apt-get install libcurl4-openssl-dev -y

# zmq
sudo apt-get install libzmq3-dev -y


