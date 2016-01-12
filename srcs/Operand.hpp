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

		eOperandType	getHighPrecision(eOperandType op1, eOperandType op2) const
		{
			if (op1 > op2)
				return op1;
			else
				return op2;
		}

		virtual IOperand  * 	createOperand(eOperandType type, double value)
		{
			IOperand	*data = NULL;

			switch (type)
			{
				case 0:
					data = new Operand<char>(type, value);
					break;
				case 1:
					data = new Operand<short int>(type, value);
					break;
				case 2:
					data = new Operand<int>(type, value);
					break;
				case 3:
					data = new Operand<float>(type, value);
					break;
				case 4:
					data = new Operand<double>(type, value);
					break;
			}

			return data;
		}


	public:
		
		Operand<T>(eOperandType type, T& value): _type(type), _value(value)
		{

		}

		virtual ~Operand(){}

		T 				getValue() const
		{
			return this->_value;
		}

		
		virtual int 			getPrecision( void ) const
		{
			return this->_precision;
		}
		
		virtual eOperandType 	getType( void ) const
		{
			return this->_type;
		}

		virtual IOperand const * operator+( IOperand const & rhs ) const
		{
			int 			precison;
			eOperandType	type;
			double 			result;

			precison = this->getHighPrecision(this->_precision, rhs.getPrecision());
			type = op[precison].type;
			result = this->_value + rhs.getValue();

			return (createOperand(type, result));
		}
		
		virtual IOperand const * operator-( IOperand const & rhs ) const
		{
			//temp
			return &rhs;
		}

		virtual IOperand const * operator*( IOperand const & rhs ) const
		{
			//temp
			return &rhs;
		}
		
		virtual IOperand const * operator/( IOperand const & rhs ) const
		{
			//temp
			return &rhs;
		}

		virtual IOperand const * operator%( IOperand const & rhs ) const
		{
			//temp
			return &rhs;
		}

		virtual std::string const & toString( void ) const
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