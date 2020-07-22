// Copyright (c) 2020 by Chrono

#ifndef _SPIN_LOCK_HPP
#define _SPIN_LOCK_HPP

#include "cpplang.hpp"

BEGIN_NAMESPACE(cpp_study)

// atomic spinlock with TAS
class SpinLock final
{
public:
    using this_type   = SpinLock;
    using atomic_type = std::atomic_flag;

public:
    SpinLock() = default;
   ~SpinLock() = default;

    SpinLock(const this_type&) = delete;
    SpinLock& operator=(const this_type&) = delete;
public:
    void lock() noexcept
    {
        for(;;) {
            if (!m_lock.test_and_set()) {
                return;
            }

            std::this_thread::yield();
        }
    }

    bool try_lock() noexcept
    {
        return !m_lock.test_and_set();
    }

    void unlock() noexcept
    {
        m_lock.clear();
    }
private:
    atomic_type m_lock {false};
};

// RAII for lock
// you can change it to a template class
class SpinLockGuard final
{
public:
    using this_type      = SpinLockGuard;
    using spin_lock_type = SpinLock;
public:
    SpinLockGuard(spin_lock_type& lock) noexcept
        : m_lock(lock)
    {
        m_lock.lock();
    }

   ~SpinLockGuard() noexcept
   {
       m_lock.unlock();
   }

public:
    SpinLockGuard(const this_type&) = delete;
    SpinLockGuard& operator=(const this_type&) = delete;
private:
    spin_lock_type& m_lock;
};


END_NAMESPACE(cpp_study)

#endif  //_SPIN_LOCK_HPP

