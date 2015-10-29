#ifndef OPERAND_H
#define OPERAND_H

# include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
	private:
		
		eOperandType	_type;
		int				_precision;
		T 				_value;

		Operand&		operator=(const Operand& src){}
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

		}
		
		IOperand const * operator-( IOperand const & rhs ) const
		{

		}

		IOperand const * operator*( IOperand const & rhs ) const
		{

		}
		
		IOperand const * operator/( IOperand const & rhs ) const
		{

		}

		IOperand const * operator%( IOperand const & rhs ) const
		{

		}

		std::string const & toString( void ) const
		{

		}
	
};

#endif