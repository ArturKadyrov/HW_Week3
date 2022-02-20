#include <iostream>
#include <string>
#include <functional>
#include <unordered_set>

////hash begin
template < typename T >
void hash_combine(std::size_t & seed, const T & value) noexcept
{
	seed ^= std::hash < T > ()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
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



class Cat
{
public:

    explicit Cat (const std::string & name , std::size_t year , std::string colour ) : m_name(name), m_year(year) , m_colour(colour)
	{}

	~Cat () noexcept = default;

	friend std::ostream & operator << (std::ostream & stream, const Cat& cat)
	{
		return (stream << cat.m_name << " , " << cat.m_year<<" , " <<cat.m_colour);
	}

private:
    std::string m_name;
    std::size_t m_year;
    std::string m_colour;

    friend struct Cat_Hash;
	friend struct Cat_Equal;

};


struct Cat_Hash
{
	std::size_t operator() (const Cat & cat) const noexcept
	{
		return hash_value(cat.m_name, cat.m_year , cat.m_colour);
	}
};

struct Cat_Equal
{
	bool operator() (const Cat & lhs, const Cat & rhs) const noexcept
	{
		return (lhs.m_name == rhs.m_name);
	}
};

int main(int argc, char ** argv)
{

    std::unordered_set < Cat , Cat_Hash , Cat_Equal > cats;

    cats.insert(Cat("Baris",2,"Black"));
    cats.insert(Cat("Barsik",3,"White"));
    cats.insert(Cat("Cat",4,"Red"));
    cats.insert(Cat("Barsik",1,"White"));


	for (const auto & cat : cats)
	{
		std::cout << cat << std::endl;
	}


	return EXIT_SUCCESS;
}
