#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

#include <functional>
#include <string>

template < typename T >
void hash_combine(std::size_t & seed, const T & value) noexcept;

template < typename T >
void hash_value(std::size_t & seed, const T & value) noexcept;

template < typename T, typename ... Types >
void hash_value(std::size_t & seed, const T & value, const Types & ... args) noexcept;

template < typename ... Types >
std::size_t hash_value(const Types & ... args) noexcept;





#endif // CAT_H_INCLUDED
