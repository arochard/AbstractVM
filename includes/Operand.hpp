#ifndef OPERAND_HPP
#define OPERAND_HPP

# include <sstream>
# include <cstdint>
# include <cmath>
# include <iostream>
# include <iomanip>
# include "IOperand.hpp"
# include "OperandFactory.hpp"
# include "Exception.hpp"


template <typename T>
class Operand : public IOperand
{
	private:
		
		eOperandType	_type;
		int				_precision;
		T 				_value;


		Operand&		operator=(const Operand& src)
		{
			this->_value = src.getValue();
			this->_precision = src.getPrecision();
			this->_type = src.getType();
			return this;
		}
		
		Operand(const Operand&){}
		Operand(){}

		int		getHighPrecision(int op1, int op2) const
		{
			if (op1 > op2)
				return op1;
			else
				return op2;
		}

	public:
		
		Operand<T>(eOperandType type, T& value): _type(type), _value(value)
		{
			int 	precision = type;
			this->_precision = precision;
		}

		virtual 	~Operand(){}

		T 			getValue() const
		{
			return this->_value;
		}

		
		int 			getPrecision( void ) const
		{
			return this->_precision;
		}
		
		eOperandType 		getType( void ) const
		{
			return this->_type;
		}

		IOperand const * operator+( IOperand const & rhs ) const
		{
			int 				precison;
			eOperandType		type;
			double				tmpRes;

			tmpRes = (std::stod(this->toString())) + (std::stod(rhs.toString()));
			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;

			return (OperandFactory::getInstance()->createOperand(type, std::to_string(tmpRes)));
		}
		
		IOperand const * operator-( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType		type;
			double			tmpRes;
			double			leftValue = std::stod(this->toString());
			double			rightValue = std::stod(rhs.toString());

			tmpRes = leftValue - rightValue;
			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;

			return (OperandFactory::getInstance()->createOperand(type, std::to_string(tmpRes)));
		}

		IOperand const * operator/( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType		type;
			double			tmpRes;
			double			leftValue = std::stod(this->toString());
			double			rightValue = std::stod(rhs.toString());

			if (leftValue == 0 || rightValue == 0)
				throw Exception("Division by 0");

			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;
			tmpRes = leftValue / rightValue;

			return (OperandFactory::getInstance()->createOperand(type, std::to_string(tmpRes)));
		}
		
		IOperand const * operator*( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType		type;
			double			tmpRes;

			tmpRes = (std::stod(this->toString())) * (std::stod(rhs.toString()));
			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;

			return (OperandFactory::getInstance()->createOperand(type, std::to_string(tmpRes)));
		}

		IOperand const * operator%( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType		type;
			double			tmpRes;
			double			leftValue = std::stod(this->toString());
			double			rightValue = std::stod(rhs.toString());

			if (leftValue == 0 || rightValue == 0)
				throw Exception("Modulo by 0");

			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;
			tmpRes = fmod(leftValue, rightValue);

			return (OperandFactory::getInstance()->createOperand(type, std::to_string(tmpRes)));
		}

		std::string const & toString( void ) const
		{
			std::string *str = new std::string();
			std::ostringstream ss;

			//std::cout <<  "Str 1: " << _value << std::endl;
			//ss.precision(op[this->_type].precision);
			if (this->_type == INT8)
				ss << (int)_value;
			else
				ss << _value;
			//DEBUG
			//std::cout << "SS : " << ss.str() << std::endl;
			str->append(ss.str());
			//DEBUG
			//std::cout << "Val : " << this->_value << std::endl;
			//std::cout << "toString : " << *str << std::endl;
			return (*str);
		}
};

#endif