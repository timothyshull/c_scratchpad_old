#include <iostream>

// Use for large objects
// Use for returning data members from a class
// Use when the returned object will not go out of scope, i.e. was passed in as a reference
// or is not created on the stack within the function
// Reference-return types can also be useful when the function must evaluate to an l-value. Most overloaded operators
// fall into this category, particularly the assignment operator.
