#ifndef IOPERAND_HPP
#define IOPERAND_HPP

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

typedef struct 			s_operand
{
	eOperandType		type;
	int 				index;
	std::string 		str;
	double 				minLimit;
	double 				maxLimit;
	int 				precision;

}						t_operand;

static t_operand		op[] =
{
	{INT8, 0, "int8", std::numeric_limits<int8_t>::min(), std::numeric_limits<int8_t>::max(), std::numeric_limits<int8_t>::digits + 2},
	{INT16, 1, "int16", std::numeric_limits<int16_t>::min(), std::numeric_limits<int16_t>::max(), std::numeric_limits<int16_t>::digits + 2},
	{INT32, 2, "int32", std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::digits + 2},
	{FLOAT, 3, "float", -std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max_digits10 + 2},
	{DOUBLE, 4, "double", -std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), std::numeric_limits<double>::max_digits10 + 2}
};


class IOperand
{
	public:
		virtual int 			getPrecision( void ) const = 0; // Precision of the type of the instance
		virtual eOperandType 		getType( void ) const = 0; // Type of the instance

		virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

		virtual std::string const & toString( void ) const = 0; // String representation of the instance
		
		virtual ~IOperand( void ) {}
};

#endif