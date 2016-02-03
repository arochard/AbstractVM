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
			return src;
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
			std::ostringstream	result;
			double				tmpRes;

			tmpRes = (std::stod(this->toString())) + (std::stod(rhs.toString()));
			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;
			result << tmpRes;

			return (OperandFactory::getInstance()->createOperand(type, result.str()));
		}
		
		IOperand const * operator-( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType		type;
			std::ostringstream	result;
			double			tmpRes;

			//DEBUG
			std::cout << "This : " << std::stod(this->toString()) << std::endl;
			std::cout << "Rhs : " << std::stod(rhs.toString()) << std::endl;
			/**/
			tmpRes = (std::stod(this->toString())) - (std::stod(rhs.toString()));
			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;
			//DEBUG
			std::cout << "TmpResult : " << tmpRes << std::endl;
			/**/
			result << std::setprecision(op[this->_type].precision) << tmpRes;
			//DEBUG
			//std::cout << "Result : " << result.str() << std::endl;
			/**/
			return (OperandFactory::getInstance()->createOperand(type, result.str()));
		}

		IOperand const * operator/( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType		type;
			std::ostringstream	result;
			double			leftValue = std::stod(this->toString());
			double			rightValue = std::stod(rhs.toString());

			if (leftValue == 0 || rightValue == 0)
				throw Exception("Division by 0");

			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;
			result << (leftValue / rightValue);

			return (OperandFactory::getInstance()->createOperand(type, result.str()));
		}
		
		IOperand const * operator*( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType		type;
			std::ostringstream	result;
			double			tmpRes;

			tmpRes = (std::stod(this->toString())) * (std::stod(rhs.toString()));
			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;
			result << tmpRes;

			return (OperandFactory::getInstance()->createOperand(type, result.str()));
		}

		IOperand const * operator%( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType		type;
			std::ostringstream	result;
			double			leftValue = std::stod(this->toString());
			double			rightValue = std::stod(rhs.toString());

			if (leftValue == 0 || rightValue == 0)
				throw Exception("Modulo by 0");

			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;
			result << fmod(leftValue, rightValue);

			return (OperandFactory::getInstance()->createOperand(type, result.str()));
		}

		std::string const & toString( void ) const
		{
			std::string *str = new std::string();
			std::ostringstream ss;

			if (this->_type == INT8)
				ss << (int)this->_value;
			else
				ss << std::setprecision(op[this->_type].precision) << this->_value;
			//std::cout << "SS : " << ss.str() << std::endl;
			str->append(ss.str());
			//std::cout << "Str : " << *str << std::endl;
			return (*str);
		}
};

#endif