# include <iomanip>
# include "../includes/AbstractVM.hpp"
# include "../includes/OperandFactory.hpp"
# include "../includes/Exception.hpp"

AbstractVM::AbstractVM()
{
	this->_arrayOperationPtr[1] = &AbstractVM::pop;
	this->_arrayOperationPtr[3] = &AbstractVM::dump;
	this->_arrayOperationPtr[4] = &AbstractVM::add;
	this->_arrayOperationPtr[5] = &AbstractVM::sub;
	this->_arrayOperationPtr[6] = &AbstractVM::mul;
	this->_arrayOperationPtr[7] = &AbstractVM::div;
	this->_arrayOperationPtr[8] = &AbstractVM::mod;
	this->_arrayOperationPtr[9] = &AbstractVM::print;
}

AbstractVM::~AbstractVM()
{

}


void		AbstractVM::executeLine(t_line *line)
{
	if (line->instruct == 0)
		this->push(OperandFactory::getInstance()->createOperand(line->typeOperand, (const std::string)line->value));
	else if (line->instruct == 2)
		this->assert(OperandFactory::getInstance()->createOperand(line->typeOperand, (const std::string)line->value));
	else if (line->instruct < 10)
		(this->*_arrayOperationPtr[line->instruct])();
}

void		AbstractVM::push(IOperand const * value)
{
	this->_stack.push_back(value);
}

void		AbstractVM::assert(IOperand const * value)
{
	if (this->_stack.empty())
		throw Exception("Error : Assert on a empty stack");
	else
	{
		IOperand const *	tmp = this->_stack.back();
		double 			assertValue = std::stod(value->toString());
		double			topStackValue = std::stod(tmp->toString());

		if ((assertValue != topStackValue) || (value->getPrecision() != tmp->getPrecision()))
			throw Exception("Assert: Not equal");
	}
}

void		AbstractVM::pop()
{
	if (!this->_stack.empty())
	{
		this->_stack.pop_back();
	}
	else
		throw Exception("Error : Pop on a empty stack");
}

void		AbstractVM::dump()
{
	if (this->_stack.empty())
		throw Exception("Error : Dump on a empty stack");
	else
	{
		for (listeOp::reverse_iterator rit = this->_stack.rbegin(); rit != this->_stack.rend(); ++rit)
			std::cout << (*rit)->toString() << " "  << (*rit)->getType() << std::endl;
	}
}

void		AbstractVM::add()
{
	if (this->_stack.size() < 2)
		throw Exception("Add: Number of values on stack < 2");
	else
	{
		IOperand const * v2 = this->_stack.back();
		this->_stack.pop_back();
		IOperand const * v1  = this->_stack.back();
		this->_stack.pop_back();
		this->push(*v2 + *v1);
	}
}

void		AbstractVM::sub()
{
	if (this->_stack.size() < 2)
		throw Exception("Sub: Number of values on stack < 2");
	else
	{
		IOperand const * v1 = this->_stack.back();
		this->_stack.pop_back();
		IOperand const * v2  = this->_stack.back();
		this->_stack.pop_back();
		this->push(*v2 - *v1);
	}
}

void		AbstractVM::mul()
{
	if (this->_stack.size() < 2)
		throw Exception("Mul: Number of values on stack < 2");
	else
	{
		IOperand const * v1 = this->_stack.back();
		this->_stack.pop_back();
		IOperand const * v2  = this->_stack.back();
		this->_stack.pop_back();
		this->push((*v2) * (*v1));
	}
}

void		AbstractVM::div()
{
	if (this->_stack.size() < 2)
		throw Exception("Div: Number of values on stack < 2");
	else
	{
		IOperand const * v1 = this->_stack.back();
		this->_stack.pop_back();
		IOperand const * v2  = this->_stack.back();
		this->_stack.pop_back();
		this->push(*v2 / *v1);
	}
}

void		AbstractVM::mod()
{
	if (this->_stack.size() < 2)
		throw Exception("Mod: Number of values on stack < 2");
	else
	{
		IOperand const * v1 = this->_stack.back();
		this->_stack.pop_back();
		IOperand const * v2  = this->_stack.back();
		this->_stack.pop_back();
		this->push(*v2 % *v1);
	}
}

void		AbstractVM::print()
{
	if (this->_stack.empty())
		throw Exception("Print: Number of values on stack = 0");
	else
	{
		IOperand const *	tmp = this->_stack.back();

		if (tmp->getPrecision() != 0)
			throw Exception("Print: Type must be 'int8'");
		else
		{
			char 		c = std::stoi(tmp->toString());
			std::cout << c << std::endl;
		}
	}
}