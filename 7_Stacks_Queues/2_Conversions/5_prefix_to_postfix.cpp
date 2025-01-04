// Algorithm for Prefix to Postfix: 
// Read the Prefix expression in reverse order (from right to left)
// If the symbol is an operand, then push it onto the Stack
// If the symbol is an operator, then pop two operands from the Stack 
// Create a string by concatenating the two operands and the operator after them. 
// string = operand1 + operand2 + operator 
// And push the resultant string back to Stack
// Repeat the above steps until end of Prefix expression.