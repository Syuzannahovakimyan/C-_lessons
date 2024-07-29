#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class Calculator{
private:
    class Node{
        public:    
            double value;
            char op = NULL;
            Node* left  = nullptr;
            Node* right = nullptr;
    };

    Node* head;

private:
    void parser(std::string expr, Node* ptr);
    std::string erase_remove_spaces(std::string expr);
    bool is_sum_or_sub(const char& c);
    bool is_div_or_mul(const char& c);
    int find_op_index(std::string expr, Node* ptr);
    void calculate_expr(Node* ptr);
    double compute_value(double left_value, double right_value, char op);

public:
    Calculator(){}
    ~Calculator(){}

    double calculate(std::string expr);

};