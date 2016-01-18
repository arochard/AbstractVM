#ifndef PARSER_HPP
#define PARSER_HPP

# include "AbstractVM.hpp"

class Parser
{
	private:
		void	 	checkInstruct(std::string str, t_line *line);
		void		checkOperand(std::string str, t_line *line);
	public:
		Parser();
		~Parser();

		t_line 		*extract(std::string str);	
};

#endif