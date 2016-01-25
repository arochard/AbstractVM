# include <fstream>
# include <queue>
# include "../includes/AbstractVM.hpp"
# include "../includes/Parser.hpp"
# include "../includes/Exception.hpp"

int		main(int ac, char **av)
{
	AbstractVM		avm;
	Parser			parser;
	std::string		str;
	std::queue<t_line*>	listInstruct;

	try
	{
		if (ac == 2)
		{
			std::ifstream fileName(av[1]);

			while (std::getline(fileName, str))
			{
				parser.epurComments(&str, false);
				if (!str.empty())
				{
					listInstruct.push(parser.extract(str));
					if (listInstruct.back()->instruct == EXIT)
						break;
				}
			}
			if (listInstruct.empty() || (listInstruct.back()->instruct != EXIT))
				throw Exception("The program must have an EXIT instruction");
		}
		else if (ac == 1)
		{
			while (std::getline(std::cin, str))
			{
				parser.epurComments(&str, true);
				if (!str.empty())
				{
					listInstruct.push(parser.extract(str));
					if (listInstruct.back()->instruct == DSEM)
						break;
				}
			}
		}
		else
			throw Exception("Usage: ./avm 'file' or ./avm");

		while (!listInstruct.empty())
		{
			avm.executeLine(listInstruct.front());
			listInstruct.pop();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}