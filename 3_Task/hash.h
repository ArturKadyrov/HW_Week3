#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

////hash begin
template < typename T >
void hash_combine(std::size_t & seed, const T & value) noexcept
{
	seed ^= std::hash < T > ()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <>
void hash_combine<std::string>(std::size_t & seed, const std::string & str) noexcept
{
    unsigned int hash_ = 0;
    unsigned int i    = 0;

   for (i = 0; i < str.size();  ++i)
   {
      hash_ = (str[i]) + (hash_ << 6) + (hash_ << 16) - hash_;
   }

	seed ^= hash_ ;
}

template < typename T >
void hash_value(std::size_t & seed, const T & value) noexcept
{
	hash_combine(seed, value);
}

template < typename T, typename ... Types >
void hash_value(std::size_t & seed, const T & value, const Types & ... args) noexcept
{
	hash_combine(seed, value);
	hash_value(seed, args...);
}

template < typename ... Types >
std::size_t hash_value(const Types & ... args) noexcept
{
	std::size_t seed = 0;
	hash_value(seed, args...);
	return seed;
}
///hash end

#endif // HASH_H_INCLUDED
