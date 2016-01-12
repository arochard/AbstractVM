#ifndef IOPERAND_H
#define IOPERAND_H

# include <string>
# include <limits>


enum eOperandType
{
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE
};

typedef struct 		s_operand
{
	eOperandType	type;
	int 			index;
	std::string 		str;
	double 			minLimit;
	double 			maxLimit;

}					t_operand;

static t_operand		op[] =
{
	{INT8, 0, "int8", std::numeric_limits<signed char>::min(), std::numeric_limits<signed char>::max()},
	{INT16, 1, "int16", std::numeric_limits<short int>::min(), std::numeric_limits<short int>::max()},
	{INT32, 2, "int32", std::numeric_limits<int>::min(), std::numeric_limits<int>::max()},
	{FLOAT, 3, "float", std::numeric_limits<float>::min(), std::numeric_limits<float>::max()},
	{DOUBLE, 4, "double", std::numeric_limits<double>::min(), std::numeric_limits<double>::max()}
};


class IOperand
{
	public:
		virtual int 			getPrecision( void ) const = 0; // Precision of the type of the instance
		virtual eOperandType 	getType( void ) const = 0; // Type of the instance

		virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

		virtual std::string const & toString( void ) const = 0; // String representation of the instance
		
		virtual ~IOperand( void ) {}
};

#endif