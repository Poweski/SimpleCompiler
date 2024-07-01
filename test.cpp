#include <iostream>

class Parser 
{
    static int lookahead;

    public:
        Parser()
        {
            lookahead = std::cin.get();
        }

        void expr()
        {
            term();
            while (true) 
            {
                if (lookahead == '+')
                {
                    match('+');
                    term();
                    std::cout << '+';
                } else if (lookahead == '-')
                {
                    match('-');
                    term();
                    std::cout << '-';
                } else return;
            }
        }

        void term()
        {

        }

        void match(int t)
        {

        }
};

int main() 
{
    printf("Hello, World!\n");
    return 0;
}
