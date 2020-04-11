// Copyright (c) 2020 by Chrono

#ifndef _SALES_DATA_HPP
#define _SALES_DATA_HPP

#include "cpplang.hpp"

#include <msgpack.hpp>

#if MSGPACK_VERSION_MAJOR < 2
#   error "msgpack  is too old"
#endif

BEGIN_NAMESPACE(cpp_study)

// demo oop in C++
class SalesData final
{
public:
    using this_type = SalesData;

public:
    using string_type       = std::string;
    using string_view_type  = const std::string&;
    using uint_type         = unsigned int;
    using currency_type     = double;

    STATIC_ASSERT(sizeof(uint_type) >= 4);
    STATIC_ASSERT(sizeof(currency_type) >= 4);
public:
    SalesData(string_view_type id, uint_type s, currency_type r) noexcept
        : m_id(id), m_sold(s), m_revenue(r)
    {}

    SalesData(string_view_type id) noexcept
        : SalesData(id, 0, 0)
    {}

public:
#if 0
    SalesData(SalesData&& s) noexcept
        : m_id(std::move(s.m_id)),
          m_sold(std::move(s.m_sold)),
          m_revenue(std::move(s.m_revenue))
    {}

    SalesData& operator=(SalesData&& s) noexcept
    {
        m_id = std::move(s.m_id);
        m_sold = std::move(s.m_sold);
        m_revenue = std::move(s.m_revenue);

        return *this;
    }
#endif

    SalesData() = default;
   ~SalesData() = default;

    SalesData(const this_type&) = default;
    SalesData& operator=(const this_type&) = default;

    SalesData(this_type&& s) = default;
    SalesData& operator=(this_type&& s) = default;

private:
    string_type m_id        = "";
    uint_type   m_sold      = 0;
    uint_type   m_revenue   = 0;

public:
    MSGPACK_DEFINE(m_id, m_sold, m_revenue);

    msgpack::sbuffer pack() const
    {
        msgpack::sbuffer sbuf;
        msgpack::pack(sbuf, *this);

        return sbuf;
    }

    SalesData(const msgpack::sbuffer& sbuf)
    {
        auto obj = msgpack::unpack(
                    sbuf.data(), sbuf.size()).get();
        obj.convert(*this);
    }

public:
    void inc_sold(uint_type s) noexcept
    {
        m_sold += s;
    }

    void inc_revenue(currency_type r) noexcept
    {
        m_revenue += r;
    }
public:
    string_view_type id() const noexcept
    {
        return m_id;
    }

    uint_type sold() const noexcept
    {
        return m_sold;
    }

    currency_type revenue() const noexcept
    {
        return m_revenue;
    }

    CPP_DEPRECATED
    currency_type average() const
    {
        return m_revenue / m_sold;
    }
};

END_NAMESPACE(cpp_study)

#endif  //_SALES_DATA_HPP

