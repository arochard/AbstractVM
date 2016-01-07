# include "AbstractVM.hpp"

AbstractVM::AbstractVM()
{
	this->_arrayPtr[0] = &AbstractVM::createInt8;
	this->_arrayPtr[1] = &AbstractVM::createInt16;
	this->_arrayPtr[2] = &AbstractVM::createInt32;
	this->_arrayPtr[3] = &AbstractVM::createFloat;
	this->_arrayPtr[4] = &AbstractVM::createDouble;

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

IOperand const * AbstractVM::createInt8( std::string const & value ) const
{
	eOperandType	type;
	char			tmp;

	type = INT8;
	tmp = std::stoi(value);

	Operand<char> const *	data = new Operand<char>(type, tmp);

	return data;
}

IOperand const * AbstractVM::createInt16( std::string const & value ) const
{
	eOperandType	type;
	short int			tmp;

	type = INT16;
	tmp = std::stoi(value);

	Operand<short int> const *	data = new Operand<short int>(type, tmp);

	return data;
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
		throw Exception("Intern error");

	return (this->*_arrayPtr[i])(value);
}

void		AbstractVM::executeLine(t_line *line)
{
	//temporaire
	std::cout << "Instruct :" << line->instruct << std::endl;
	std::cout << "Operand type :" << line->typeOperand << std::endl;
	std::cout << "Value :" << line->value << std::endl;
	// fin temp

	if (line->instruct == 0)
		this->push(createOperand(line->typeOperand, (const std::string)line->value));
	else
		this->*_arrayOperationPtr[line->instruct];
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
	IOperand const * v1;
	IOperand const * v2;

	if (listeOp.size() < 2)
		throw Exception("Add: Number of values on stack < 2");
	else
	{
		v2 = listeOp.back();
		listeOp.pop_back();
		v1 = listeOp.back();
		listeOp.pop_back();
		listeOp.push_back(v2 + v1);
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