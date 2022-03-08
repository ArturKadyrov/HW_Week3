#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

#include <iostream>
#include <string>


class Cat
{
public:

    explicit Cat (const std::string & name , std::size_t year , const std::string & colour ) : m_name(name), m_year(year) , m_colour(colour)
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
	std::size_t operator() (const Cat & cat) const noexcept;
};

struct Cat_Equal
{
	bool operator() (const Cat & lhs, const Cat & rhs) const noexcept;
};


#endif // CAT_H_INCLUDED
