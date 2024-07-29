#include "calculator.hpp"

void Calculator::parser(std::string expr, Node* ptr) {
    if(expr.empty()) {
        return;
    }

    if (expr[0] == '(' && expr[expr.length() - 1] == ')' ) {
        expr = expr.substr(1, expr.length() - 2);
    }

    int op_index = find_op_index(expr, ptr);
    // [1*2+6-3/7]

    if(op_index == -1) {
        ptr -> value = std::stoi(expr);
        return;
    }
    else {
        ptr->op = expr[op_index];
    }

    auto left = expr.substr(0, op_index);
    auto right = expr.substr(op_index + 1, expr.length() - op_index - 1);


    ptr -> left = new Node;
    parser(left, ptr->left);

    ptr -> right = new Node;
    parser(right, ptr->right);
}

int Calculator::find_op_index(std::string expr, Node *ptr) {
    int op_index = -1;
    int brackets_level = 0;

    for(int i = 0; i < expr.length(); ++i){
        if (expr[i] == '(') {
            brackets_level++;
        }
        else if (expr[i] == ')') {
            brackets_level--;
        }

        if(brackets_level == 0) {
            if (is_sum_or_sub(expr[i])){
                ptr->op = expr[i];
                op_index = i;
                break;
            }
            else if (is_div_or_mul(expr[i]) && !ptr->op) {
                ptr->op = expr[i];
                op_index = i;
            }
        }
    }

    return op_index;
}

void Calculator::calculate_expr(Node *ptr) {
    if (ptr -> left) {
        if(ptr -> left -> op) {
            calculate_expr(ptr -> left);
        }
    }

    if (ptr -> right) {
        if(ptr -> right -> op) {
            calculate_expr(ptr -> right);
        }
    }

    ptr -> value = compute_value(ptr->left->value, ptr->right->value, ptr->op);
    ptr ->op = NULL;

}

double Calculator::compute_value(double left_value, double right_value, char op) {
    double result = 0;
    switch (op) {
        case '+':
            result = left_value + right_value;
        break;
        case '-':
            result = left_value - right_value;
        break;
        case '*':
            result = left_value * right_value;
        break;
        case '/':
            result = left_value / right_value;
        break;
        default:
            result = -1;
    }

    return result;
}

double Calculator::calculate(std::string expr) {
    expr = erase_remove_spaces(expr);
    head = new Node;
    parser(expr, head);

    calculate_expr(head);
    return head->value;
}



std::string Calculator::erase_remove_spaces(std::string expr) {
    expr.erase(std::remove(expr.begin(), expr.end(), ' '), expr.end());
    return expr;
}

bool Calculator::is_sum_or_sub(const char &c) {
    bool result = false;
    if(c == '+' || c == '-'){
        result = true;
    }
    return result;
}

bool Calculator::is_div_or_mul(const char &c) {
    bool result = false;
    if(c == '*' || c == '/'){
        result = true;
    }
    return result;
}
