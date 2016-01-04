#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

# include "Operand.hpp"
# include "Exception.hpp"
# include <list>
# include <iostream>

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
		typedef IOperand const * (AbstractVM::*GenericCreateOp)(std::string const & value) const;
		
		listeOp			_stack;
		//int 			_stackSize;
		GenericCreateOp	_arrayPtr[5];


		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

		AbstractVM&		operator=(const AbstractVM& src);
		AbstractVM(const AbstractVM&);

		

	public:
		AbstractVM();
		~AbstractVM();

		IOperand const * createOperand( eOperandType type, std::string const & value ) const;

		void		executeLine(t_line*);

		void		push(IOperand*);
		void		pop();
		void		dump();
		void		add();
		void		sub();
		void		mul();
		void		div();
		void		mod();

	
};

#endif