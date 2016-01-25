# include "../includes/Parser.hpp"
# include "../includes/Exception.hpp"

Parser::Parser()
{

}

Parser::~Parser()
{

}

void		Parser::checkInstruct(std::string str, t_line *line)
{
	bool	find = false;
	int 	index = 0;

	while (!find && index < 12)
	{
		if (str.compare(in[index].instructStr) == 0)
			find = true;
		else
			index++;
	}

	if (find)
		line->instruct = in[index].type;
	else
		throw Exception("Instruction not found");
}

void		Parser::checkOperand(std::string str, t_line *line)
{
	bool		find = false;
	int 		index = 0;
	size_t 		pos = 0;
	std::string	operand;
	std::string	value;

	if ((pos = str.find("(")) != std::string::npos)
	{
		while (!find && index < 5)
		{
			if (str.substr(0, pos).compare(op[index].str) == 0)
				find = true;
			else
				index++;
		}

		if (find)
			line->typeOperand = op[index].type;
		else
			throw Exception("Operand not found");
	}
	else
		throw Exception("Syntax error");

	str.erase(0, pos + 1);

	if ((pos = str.find(")")) != std::string::npos)
		line->value = str.substr(0, pos);
	else
		throw Exception("Syntax error on operand value");	
}

void		Parser::epurComments(std::string *str, bool isStandInput)
{
	std::string 	del = ";";
	size_t		pos;

	pos = (*str).find(del);

	if (pos != std::string::npos)
	{
		//DEBUG
		//std::cout << *str->end() << std::endl;
		if (isStandInput)
		{
			if ((*str)[pos + 1] != ';')
			{
				//DEBUG
				//std::cout << "pos: " << (*str)[pos + 1] << std::endl;	
				(*str).erase(pos, (*str).size());
			}
			else
				(*str).erase(pos + 2, (*str).size());
		}
		else
			(*str).erase(pos, (*str).size());
	}
	//DEBUG
	//std::cout << "End epur : " << *str << std::endl;
}

t_line 		*Parser::extract(std::string str)
{
	t_line 		*lineExtract = new t_line;
	std::string 	delimiter = " ";
	size_t		pos;

	pos = str.find(delimiter);
	if (pos != std::string::npos)
	{
		checkInstruct(str.substr(0, pos), lineExtract);
		if (!in[lineExtract->instruct].value)
			throw Exception("Syntax error");
		else
			checkOperand(str.substr(pos + 1, str.length()), lineExtract);
	}
	else
	{
		checkInstruct(str, lineExtract);
		if (in[lineExtract->instruct].value)
			throw Exception("Syntax error");
	}

	return (lineExtract);
}	