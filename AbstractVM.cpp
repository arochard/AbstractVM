# include "AbstractVm.hpp"

AbstractVM::AbstractVM()
{
	this->_arrayPtr[0] = &AbstractVM::createInt8;
	this->_arrayPtr[1] = &AbstractVM::createInt16;
	this->_arrayPtr[2] = &AbstractVM::createInt32;
	this->_arrayPtr[3] = &AbstractVM::createFloat;
	this->_arrayPtr[4] = &AbstractVM::createDouble;

	this->_stackSize = 0;
}

AbstractVM::~AbstractVM()
{

}

IOperand const * AbstractVM::createInt8( std::string const & value ) const
{

}

IOperand const * AbstractVM::createInt16( std::string const & value ) const
{
	
}

IOperand const * AbstractVM::createInt32( std::string const & value ) const
{
	eOperandType	type;
	int 			tmp;

	type = INT32;
	tmp = std::stoi(value);

	Operand<int> const *	data = new Operand<int>(type, tmp);

	return data;
}

IOperand const * AbstractVM::createFloat( std::string const & value ) const
{
	eOperandType	type;
	float 			tmp;

	type = FLOAT;
	tmp = std::stof(value);

	Operand<float> const *	data = new Operand<float>(type, tmp);

	return data;	
}

IOperand const * AbstractVM::createDouble( std::string const & value ) const
{
	eOperandType	type;
	double 			tmp;

	type = DOUBLE;
	tmp = std::stod(value);

	Operand<double> const *	data = new Operand<double>(type, tmp);

	return data;
}


IOperand const * AbstractVM::createOperand( eOperandType type, std::string const & value ) const
{
	int 		i;

	i = 0;
	while (i <= 5 && op[i].type != type)
		i++;

	if (i == 5)
	{
		//error
	}

	return (this->*_arrayPtr[i])(value);
}
/*
void		AbstractVM::executeLine(t_line)
{
	//
}
*/
void		AbstractVM::push(IOperand* value)
{
	this->_stack.push_back(value);
	this->_stackSize++;
}

void		AbstractVM::pop()
{
	if (this->_stackSize > 0)
	{
		this->_stack.pop_back();
		this->_stackSize--;
	}
	else
		//error
}

void		AbstractVM::dump()
{
	for (listeOp::iterator it = this->_stack.end(); it != this->_stack.begin(); it--)
		std::cout << *it << std::endl;
}
/*
void		AbstractVM::add()
{

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