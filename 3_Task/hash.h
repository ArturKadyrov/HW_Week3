#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

////hash begin
template < typename T >
void hash_combine(std::size_t & seed, const T & value) noexcept
{
	seed ^= std::hash < T > ()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
/*
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


template <>
void hash_combine<std::string>(std::size_t & seed, const std::string & str) noexcept
{
    unsigned int hash_ = 5381;
    unsigned int i    = 0;

   for (i = 0; i < str.size();  ++i)
   {
      hash_ = (str[i]) + ((hash_ << 5) + hash_);
   }

	seed ^= hash_ ;
}

template <>
void hash_combine<std::string>(std::size_t & seed, const std::string & str) noexcept
{

    unsigned int hash_ = 1315423911;
    unsigned int i    = 0;

   for (i = 0; i < str.size();  ++i)
   {
      hash_ ^= ((hash_ << 5) + (str[i]) + (hash_ >> 2));

   }

	seed ^= hash_ ;
}


template <>
void hash_combine<std::string>(std::size_t & seed, const std::string & str) noexcept
{
    const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    const unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
    const unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
    const unsigned int HighBits          =
                      (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
    unsigned int hash_ = 0;
    unsigned int test = 0;
    unsigned int i    = 0;


   for (i = 0; i < str.size();  ++i)
   {
      hash_ = (hash_ << OneEighth) + (str[i]);

      if ((test = hash_ & HighBits) != 0)
      {
         hash_ = (( hash_ ^ (test >> ThreeQuarters)) & (~HighBits));
      }

   }

	seed ^= hash_ ;


}


template <>
void hash_combine<std::string>(std::size_t & seed, const std::string & str) noexcept
{
    unsigned int hash_ = 0;
   unsigned int x    = 0;
   unsigned int i    = 0;

   for (i = 0; i < str.size(); ++i)
   {
      hash_ = (hash_ << 4) + (str[i]);

      if ((x = hash_ & 0xF0000000L) != 0)
      {
         hash_ ^= (x >> 24);
      }

      hash_ &= ~x;
   }
    seed ^= hash_ ;
}


template <>
void hash_combine<std::string>(std::size_t & seed, const std::string & str) noexcept
{
    unsigned int seed_ = 131;
   unsigned int hash_ = 0;
   unsigned int i    = 0;


   for (i = 0; i < str.size(); ++i)
   {
      hash_ = (hash_ * seed_) + (str[i]);
   }
    seed ^= hash_ ;
}


template <>
void hash_combine<std::string>(std::size_t & seed, const std::string & str) noexcept
{
   unsigned int hash_ = str.size();
   unsigned int i    = 0;


   for (i = 0; i < str.size(); ++i)
   {
     hash_ = ((hash_ << 5) ^ (hash_ >> 27)) ^ (str[i]);
   }
    seed ^= hash_ ;
}

*/


template <>
void hash_combine<std::string>(std::size_t & seed, const std::string & str) noexcept
{
   unsigned int hash_ = 0xAAAAAAAA;
   unsigned int i    = 0;


   for (i = 0; i < str.size(); ++i)
   {
     hash_ ^= ((i & 1) == 0) ? (  (hash_ <<  7) ^ (str[i]) * (hash_ >> 3)) :
                               (~((hash_ << 11) + ((str[i]) ^ (hash_ >> 5))));
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
