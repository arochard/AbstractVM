# include "main.hpp"


int		main(int ac, char **av)
{
	AbstractVM		avm;
	std::string		str;

	try
	{
		if (ac == 2)
		{
			std::ifstream fileName(av[1]);

			while (std::getline(fileName, str))
			{
				std::cout << str << std::endl;
			}
		}
		else if (ac == 1)
		{
			while (std::getline(std::cin, str))
			{
				std::cout << str << std::endl;
			}
		}
		else
			throw Exception("Usage: ./avm 'file' or ./avm");
	}
	catch (const Exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}