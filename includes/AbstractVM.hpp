#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

# include <list>
# include <iostream>
# include "IOperand.hpp"

enum eInstructType
{
	PUSH,
	POP,
	ASSERT,
	DUMP,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	PRINT,
	EXIT,
	DSEM
};

typedef struct 		s_instruct
{
	eInstructType	type;
	std::string	instructStr;
	bool		value;
}			t_instruct;

static 	t_instruct	in[]
{
	{PUSH, "push", true},
	{POP, "pop", false},
	{ASSERT, "assert", true},
	{DUMP, "dump", false},
	{ADD, "add", false},
	{SUB, "sub", false},
	{MUL, "mul", false},
	{DIV, "div", false},
	{MOD, "mod", false},
	{PRINT, "print", false},
	{EXIT, "exit", false},
	{DSEM, ";;", false}
};

typedef	struct 		s_line
{
	eInstructType	instruct;
	eOperandType	typeOperand;
	std::string		value;
}					t_line;

typedef std::list<IOperand const*> listeOp;



class AbstractVM
{

	private:
		typedef void	(AbstractVM::*GenericOperation)();
		
		listeOp				_stack;
		
		GenericOperation 	_arrayOperationPtr[12];

		AbstractVM&		operator=(const AbstractVM& src);
		AbstractVM(const AbstractVM&);

		

	public:
		AbstractVM();
		~AbstractVM();

		void		executeLine(t_line*);

		void		push(IOperand const *);
		void		pop();
		void		dump();
		void		add();
		void		sub();
		void		mul();
		void		div();
		void		mod();
		void		print();

	
};

#endif