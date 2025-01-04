// Algorithm for Prefix to Infix: 

// Read the Prefix expression in reverse order (from right to left)
// If the symbol is an operand, then push it onto the Stack
// If the symbol is an operator, then pop two operands from the Stack 
// Create a string by concatenating the two operands and the operator between them. 
// string = (operand1 + operator + operand2) 
// And push the resultant string back to Stack
// Repeat the above steps until the end of Prefix expression.
// At the end stack will have only 1 string i.e resultant string