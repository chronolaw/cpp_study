// Copyright (c) 2020 by Chrono

#ifndef _ZMQ_HPP
#define _ZMQ_HPP

#include "cpplang.hpp"

// /usr/include/zmq.hpp
#include <zmq.hpp>

BEGIN_NAMESPACE(cpp_study)

using zmq_context_type  = zmq::context_t;
using zmq_socket_type   = zmq::socket_t;
using zmq_message_type  = zmq::message_t;

template<int thread_num = 1>
class ZmqContext final
{
#if 0
public:
    using zmq_context_type  = zmq::context_t;
    using zmq_socket_type   = zmq::socket_t;
    using zmq_message_type  = zmq::message_t;
#endif
public:
    static
    zmq_context_type& context()
    {
        static zmq_context_type ctx(thread_num);
        return ctx;
    }
public:
    zmq_socket_type recv_sock(size_t hwm = 1000) const
    {
        zmq_socket_type sock(context(), ZMQ_PULL);

        sock.setsockopt(ZMQ_RCVHWM, hwm);

        return sock;
    }

    zmq_socket_type send_sock(size_t hwm = 1000) const
    {
        zmq_socket_type sock(context(), ZMQ_PUSH);

        sock.setsockopt(ZMQ_SNDHWM, hwm);

        return sock;
    }
};

END_NAMESPACE(cpp_study)

#endif  //_ZMQ_HPP

