#ifndef OPERAND_H
#define OPERAND_H

# include <sstream>
# include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
	private:
		
		eOperandType	_type;
		int				_precision;
		T 				_value;

		Operand&		operator=(const Operand& src){
			//temp
			return src;
		}
		Operand(const Operand&){}
		Operand(){}

		eOperandType	getHighPrecision(eOperandType op1, eOperandType op2)
		{
			if (op1 > op2)
				return op1;
			else
				return op2;
		}

		IOperand const * 	createOperand(eOperandType type, double value)
		{
			switch (type)
			{
				case 0:
					Operand<char> const * data = new Operand<char>(type, (char)value);
					break;
				case 1:
					Operand<short int> const * data = new Operand<short int>(type, (short int)value);
					break;
				case 2:
					Operand<int> const * data = new Operand<int>(type, (int)value);
					break;
				case 3:
					Operand<float> const * data = new Operand<float>(type, (float)value);
					break;
				case 4:
					Operand<double> const * data = new Operand<double>(type, value);
					break;
			}

			return data;
		}

	public:
		
		Operand<T>(eOperandType type, T& value): _type(type), _value(value)
		{

		}

		~Operand(){}

		T 				getValue()
		{
			return this->_value;
		}

		int 			getPrecision( void ) const
		{
			return this->_precision;
		}
		
		eOperandType 	getType( void ) const
		{
			return this->_type;
		}

		IOperand const * operator+( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType	type;
			double 			result;

			precison = this->getHighPrecision(this->_precision, rhs->getPrecision());
			type = op[precison].type;
			result = this->_value + rhs->getValue();

			return (createOperand(type, result));
		}
		
		IOperand const * operator-( IOperand const & rhs ) const
		{
			//temp
			return &rhs;
		}

		IOperand const * operator*( IOperand const & rhs ) const
		{
			//temp
			return &rhs;
		}
		
		IOperand const * operator/( IOperand const & rhs ) const
		{
			//temp
			return &rhs;
		}

		IOperand const * operator%( IOperand const & rhs ) const
		{
			//temp
			return &rhs;
		}

		std::string const & toString( void ) const
		{

			// A revoir
			std::string *str = new std::string();
			std::ostringstream ss;

			if (_type == INT8)
				ss << (int) _value;
			else
				ss << _value;

			str->append(ss.str());
			return (*str);
		}
	
};

#endif