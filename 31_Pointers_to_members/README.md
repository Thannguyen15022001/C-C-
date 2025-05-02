# Function pointer

Note:
1. Non-static function in class.

    Syntax: return_type (className::*ptr) (parameter type, ....); 

    Use: (Obj.*ptr)(arg, ...); OR (Obj->*ptr)(arg, ...);


2. Static and normal functions.

    Syntax: return_type (*FuncPtrName) (parameter type, ....); OR typedef < return_type > ( * < alias_name >)(< parameter_type >,< parameter_type >, .... );

    Use: FuncPtrName(arg, ...)

3. Return function pointer

    Syntax: return_type (*FuncPtrName(argument type, ... )) (parameter type, ....)

Example:
1. Function type

    int Function(char, float);

2. Function pointer type for global function or namespace and static member function in class

    int (*)(char, float);

3. Function pointer type for non-static function in class

    int (ClassName::*)(char, float)

4. Function pointer return

    int (*functionName(arg_function, ...))(char, float)


