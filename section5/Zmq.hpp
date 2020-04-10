// Copyright (c) 2020 by Chrono

#ifndef _SPIN_LOCK_HPP
#define _SPIN_LOCK_HPP

#include "cpplang.hpp"

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
    zmq_socket_type socket(int mode, size_t hwm = 1000) const
    {
        zmq_socket_type sock(context(), mode);

        sock.setsockopt(
            mode == ZMQ_PULL ? ZMQ_RCVHWM : ZMQ_SNDHWM,
            hwm);

        return sock;
    }
};

END_NAMESPACE(cpp_study)

#endif  //_SPIN_LOCK_HPP

