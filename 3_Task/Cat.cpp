#include"Cat.h"
#include "hash.h"


std::size_t Cat_Hash::operator() (const Cat & cat) const noexcept
{
    return hash_value(cat.m_name, cat.m_colour);
}


bool Cat_Equal::operator() (const Cat & lhs, const Cat & rhs) const noexcept
{
    return (lhs.m_name == rhs.m_name && lhs.m_colour == rhs.m_colour );
}

