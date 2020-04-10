-- copyright (c) 2020 chrono

-- lua is more flexible than json

config = {

    max_buf_size = 4 * 1024,

    zmq_ipc_addr = "tcp://127.0.0.1:5555",

    http_addr = "http://localhost/cpp_study?token=cpp@2020",

    keyword = "super",

    sold_criteria = 100,

    revenue_criteria = 1000,

    best_n  = 3,

    time_interval = 5,  -- seconds

}

-- debug: luajit conf.lua

--print(config.http_addr)
