#ifndef OPERAND_FACTORY_HPP
#define OPERAND_FACTORY_HPP

# include "IOperand.hpp"


class OperandFactory
{
	private:
		typedef IOperand const * (OperandFactory::*GenericCreateOp)(std::string const & value) const;
		GenericCreateOp		_arrayPtr[5];

		static	OperandFactory *	_instance; 


		OperandFactory&	operator=(const OperandFactory& src);
		OperandFactory(const OperandFactory&);


		bool			checkLimitOp(eOperandType type, std::string value) const;

		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

	public:
		OperandFactory();
		~OperandFactory();

		static OperandFactory  *		getInstance();

		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	
};

#endif