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
	//a voir avec exit et autre
}

AbstractVM::~AbstractVM()
{

}


void		AbstractVM::executeLine(t_line *line)
{
	if (line->instruct == 0)
		this->push(OperandFactory::getInstance()->createOperand(line->typeOperand, (const std::string)line->value));
	else
		(this->*_arrayOperationPtr[line->instruct])();
}

void		AbstractVM::push(IOperand const * value)
{
	this->_stack.push_back(value);
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
		for (listeOp::iterator it = this->_stack.end(); it != this->_stack.begin(); it--)
			std::cout << *it << std::endl;
	}
}

void		AbstractVM::add()
{
	

	if (_stack.size() < 2)
		throw Exception("Add: Number of values on stack < 2");
	else
	{
		IOperand const * v2 = _stack.back();
		_stack.pop_back();
		IOperand const * v1  = _stack.back();
		_stack.pop_back();
		_stack.push_back(*v2 + *v1);
	}
}

void		AbstractVM::sub()
{

}

void		AbstractVM::mul()
{

}

void		AbstractVM::div()
{

}

void		AbstractVM::mod()
{

}

void		AbstractVM::print()
{

}