# include "main.hpp"

int		main(int ac, char **av)
{
	AbstractVM		avm;
	Parser			parser;
	std::string		str;

	try
	{
		if (ac == 2)
		{
			std::ifstream fileName(av[1]);

			while (std::getline(fileName, str))
				avm.executeLine(parser.extract(str));
		}
		else if (ac == 1)
		{
			while (std::getline(std::cin, str))
				avm.executeLine(parser.extract(str));
		}
		else
			throw Exception("Usage: ./avm 'file' or ./avm");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}