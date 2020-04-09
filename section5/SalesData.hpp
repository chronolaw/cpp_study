// Copyright (c) 2020 by Chrono

#ifndef _SALES_DATA_HPP
#define _SALES_DATA_HPP

#include "cpplang.hpp"

class SalesData final
{
public:
    using this_type     = SalesData;

public:
    using string_type   = std::string;
    using uint_type     = unsigned int;
    using currency_type = double;

public:
    SalesData() = default;
   ~SalesData() = default;

private:
    string_type m_id        = "";
    uint_type   m_sold      = 0;
    uint_type   m_revenue   = 0;

public:
    const string_type& id() const
    {
        return m_id;
    }

    uint_type sold() const
    {
        return m_sold;
    }

    currency_type revenue() const
    {
        return m_revenue;
    }

    currency_type average() const
    {
        return m_revenue / m_sold;
    }
};


#endif  //_SALES_DATA_HPP

