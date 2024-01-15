#include <iostream>
#include <cctype>

using namespace std;

// Structure that represents a node in the AST.
struct Node {
    char op1;      // Stores operators.
    double value;  // Stores a numeric value if it is a parent node. It is also possible to use a "float" type variable to use less memory but you would be sacrificing precision in the calculations.
    Node* izq;     // Pointer to the left child node.
    Node* der;     // Pointer to the right child node.

    // Constructor for operators nodes.
    Node(char op2, Node* _izq, Node* _der)
        : op1(op2), value(0.0), izq(_izq), der(_der) {}     // The "value" parameter is 0.0 to indicate that this node represents an operator, not a number.

    // Constructor for numerics nodes.
    Node(double _value)
        : op1('0'), value(_value), izq(nullptr), der(nullptr) {}    // The "izq" and "der" parameters uses the "nullptr" because they´re child nodes. The "op1" parameter is '0' because it represents a number, not an operator.
};

// Function to create a parent node for an operator with two child nodes.
Node* createNode(char op1, Node* left, Node* right) {
    return new Node(op1, left, right);
}

// Function to create a node that represents a number.
Node* createNode(double value) {
    return new Node(value);
}

/*
The two functions above have the same name.
This is possible in C++ because the compiler can identify what node to create depending on the parameters it receives.
*/

// Function to build the AST.
Node* createAST(const string& expression, size_t& pos) {
    Node* left = nullptr;       // Initialize left pointer to "nullptr" as a good practice.

    // Parsing a number or a left parenthesis.
    if (isdigit(expression[pos]) || expression[pos] == '(') {
        if (isdigit(expression[pos])) {
            // Parsing a number.
            double value = 0.0;
            while (pos < expression.size() && isdigit(expression[pos])) {
                value = value * 10 + (expression[pos] - '0');
                pos++;
            }
            left = createNode(value);
        } else if (expression[pos] == '(') {
            // Paring an expression inside parenthesis.
            pos++;
            left = createAST(expression, pos);      // Recursive call to the 'createAST' function.
            pos++;
        }
    } else {
        cerr << "Error: Se esperaba un número o paréntesis izquierdo." << endl;
        exit(EXIT_FAILURE);
    }

    // Parsing of operators and additional operands.
    while (pos < expression.size() && (expression[pos] == '+' || expression[pos] == '-' || expression[pos] == '*' || expression[pos] == '/')) {
        char op1 = expression[pos];
        pos++;
        Node* right = createAST(expression, pos);
        left = createNode(op1, left, right);
    }

    return left; // Returns the constructed subtree.
}

// Function to free the AST memory once the program execution has finished.
void freeAST(Node* root) {
    if (root == nullptr) {
        return;
    }
    freeAST(root->izq);     //Recursive call to the function to free the memory of the left subtree.
    freeAST(root->der);     //Recursive call to the function to free the memory of the right subtree.
    delete root;            // Delete the current node to free its memory.
}

// Function to evaluate the AST recursively.
double evaluateAST(Node* root) {
    // If the node is a leaf (numeric value), return the numeric value.
    if (root->op1 == '0') {
        return root->value;
    }

    // Recursively evaluate the left and right subtrees.
    double left_result = evaluateAST(root->izq);
    double right_result = evaluateAST(root->der);

    // Perform the arithmetic operation based on the operator in the current node. Se utilizó el condicional "case" para ahorrar líneas de código.
    switch (root->op1) {
        case '+': return left_result + right_result;
        case '-': return left_result - right_result;
        case '*': return left_result * right_result;
        case '/': return left_result / right_result;
        default:
            cerr << "Error: Operador desconocido." << endl;
            exit(EXIT_FAILURE);
    }
}

int main() {
    // Request the user to enter a mathematical expression.
    string expression;
    cout << "Ingrese una expresion matematica: ";
    getline(cin, expression);

    size_t pos = 0;
    // Create the AST from the entered expression.
    Node* ast = createAST(expression, pos);

    // Evaluates the AST y displays the result.
    double result = evaluateAST(ast);
    cout << "Resultado: " << result << endl;

    // Free the AST memory.
    freeAST(ast);

    return 0;
}