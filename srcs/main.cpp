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
	bool			eof = false;

	try
	{
		if (ac == 2)
		{
			std::ifstream fileName(av[1]);

			while (std::getline(fileName, str) && !eof)
			{
				if (!str.empty())
				{
					listInstruct.push(parser.extract(str));
					if (listInstruct.back()->instruct == EXIT)
						eof = true;
				}
			}
		}
		else if (ac == 1)
		{
			while (std::getline(std::cin, str) && !eof)
			{
				if (!str.empty())
				{
					listInstruct.push(parser.extract(str));
					if (listInstruct.back()->instruct == DSEM)
						eof = true;
				}
			}
		}
		else
			throw Exception("Usage: ./avm 'file' or ./avm");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	while (!listInstruct.empty())
	{
		std::cout << "Instruct: " << listInstruct.front()->instruct << std::endl;
		std::cout << "Operand:" << listInstruct.front()->typeOperand << std::endl;
		std::cout << "Value:" << listInstruct.front()->value << std::endl << std::endl;

		avm.executeLine(listInstruct.front());

		listInstruct.pop();
	}
}