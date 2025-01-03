#include "Node.hpp"

int Node::labels = 0;

Node::Node() {
    lexline = Lexer::line;
}

void Node::error(const std::string& s) {
    throw std::runtime_error("near line " + std::to_string(lexline) + ": " + s);
}

int Node::newlabel() {
    return ++labels;
}

void Node::emitlabel(int i) {
    std::cout << "L" << i << ":";
}

void Node::emit(const std::string& s) {
    std::cout << "\t" << s << std::endl;
}
