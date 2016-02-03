#include "../includes/OperandFactory.hpp"
#include "../includes/Operand.hpp"
#include "../includes/Exception.hpp"

OperandFactory* 	OperandFactory::_instance = NULL;

OperandFactory::OperandFactory()
{
	this->_arrayPtr[0] = &OperandFactory::createInt8;
	this->_arrayPtr[1] = &OperandFactory::createInt16;
	this->_arrayPtr[2] = &OperandFactory::createInt32;
	this->_arrayPtr[3] = &OperandFactory::createFloat;
	this->_arrayPtr[4] = &OperandFactory::createDouble;
}

OperandFactory::~OperandFactory()
{

}

bool				OperandFactory::checkLimitOp(eOperandType type, std::string value) const
{
	double 			tmp;

	tmp = std::stod(value);

	if (op[type].minLimit > tmp)
		throw Exception("Error : Underflow");
	else if (op[type].maxLimit < tmp)
		throw Exception("Error : Overflow");

	return true;
}

// Singleton
OperandFactory  * OperandFactory::getInstance()
{
	if (!_instance)
		_instance = new OperandFactory(); 
     return _instance;
}


// Factory Method
IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	int 		i;

	i = 0;
	while (i <= 5 && op[i].type != type)
		i++;

	if (i == 5)
		throw Exception("Intern error or type does not exist");

	return (this->*_arrayPtr[i])(value);
}




IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
	eOperandType	type;
	int8_t			tmp;

	type = INT8;
	tmp = std::stoi(value);

	if (checkLimitOp(type, value))
	{
		Operand<int8_t> const *	data = new Operand<int8_t>(type, tmp);
		return data;
	}
	
	return NULL;
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
	eOperandType	type;
	int16_t			tmp;

	type = INT16;
	tmp = std::stoi(value);

	if (checkLimitOp(type, value))
	{
		Operand<int16_t> const *	data = new Operand<int16_t>(type, tmp);
		return data;
	}

	return NULL;
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
	eOperandType	type;
	int32_t 			tmp;

	type = INT32;
	tmp = std::stoi(value);

	if (checkLimitOp(type, value))
	{
		Operand<int32_t> const *	data = new Operand<int32_t>(type, tmp);
		return data;
	}

	return NULL;
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
	eOperandType	type;
	float 			tmp;

	type = FLOAT;
	tmp = std::stof(value);

	if (checkLimitOp(type, value))
	{
		Operand<float> const *	data = new Operand<float>(type, tmp);
		return data;
	}

	return NULL;
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
	eOperandType	type;
	double 			tmp;

	type = DOUBLE;
	tmp = std::stod(value);

	if (checkLimitOp(type, value))
	{
		Operand<double> const *	data = new Operand<double>(type, tmp);
		return data;
	}

	return NULL;
}