// Copyright (c) 2020 by Chrono

#ifndef _SPIN_LOCK_HPP
#define _SPIN_LOCK_HPP

#include "cpplang.hpp"

#include <zmq.hpp>

BEGIN_NAMESPACE(cpp_study)

template<int thread_num = 1>
class ZmqContext final
{
public:
    using zmq_context_type  = zmq::context_t;
    using zmq_socket_type   = zmq::socket_t;
    using zmq_message_type  = zmq::message_t;
public:
    static
    zmq_context_type& context()
    {
        static zmq_context_type ctx(thread_num);
        return ctx;
    }
public:
    zmq_socket_type socket(int mode) const
    {
        return zmq_socket_type(context(), mode);
    }
};

END_NAMESPACE(cpp_study)

#endif  //_SPIN_LOCK_HPP

