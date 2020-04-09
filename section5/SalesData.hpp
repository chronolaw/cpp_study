// Copyright (c) 2020 by Chrono

#ifndef _SALES_DATA_HPP
#define _SALES_DATA_HPP

#include "cpplang.hpp"

BEGIN_NAMESPACE(cpp_study)

class SalesData final
{
public:
    using this_type     = SalesData;

public:
    using string_type   = std::string;
    using uint_type     = unsigned int;
    using currency_type = double;

    static_assert(
        sizeof(uint_type) >= 4, "uint is too small");
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

    CPP_DEPRECATED
    currency_type average() const
    {
        return m_revenue / m_sold;
    }
};

END_NAMESPACE(cpp_study)

#endif  //_SALES_DATA_HPP

