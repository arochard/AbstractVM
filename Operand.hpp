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

	public:
		
		Operand<T>(eOperandType type, T& value): _type(type), _value(value)
		{

		}

		~Operand(){}

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
			//temp
			return &rhs;
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