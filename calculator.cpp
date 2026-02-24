#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

class calculator
{
private:
    double num1 = 0.0;
    double num2 = 0.0;

    char operation = '\n';
    double answer = 0.0;

    bool converter = false;

public:
    void show_calculator()
    {
        cout << "|------------------------------------|" << endl;
        cout << "|            SCIENTIFIC              |" << endl;
        cout << "|            CALCULATOR              |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     +     |      -     |     *     |" << endl;
        cout << "|    Add    |  Subtract  |  Multiply |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     /      |     %       |    L    |" << endl;
        cout << "|  Divide    |   Modulus   |   Log   |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     S      |      C      |    P    |" << endl;
        cout << "|   Square   |     Cube    |  Power  |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     s      |      c      |    t    |" << endl;
        cout << "|    Sin     |     Cos     |   Tan   |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     r      |      k      |    .    |" << endl;
        cout << "|  Sq root   |    Clear    |  Close  |" << endl;
        cout << "|------------------------------------|" << endl;
    }

    void display_output(double answer)
    {
        cout << "|------------------------------------|" << endl;
        cout << "| CURRENT OUTPUT IS  :    | " << answer << " | " << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     +     |      -     |     *     |" << endl;
        cout << "|    Add    |  Subtract  |  Multiply |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     /      |     %       |    L    |" << endl;
        cout << "|  Divide    |   Modulus   |   Log   |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     S      |      C      |    P    |" << endl;
        cout << "|   Square   |     Cube    |  Power  |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     s      |      c      |    t    |" << endl;
        cout << "|    Sin     |     Cos     |   Tan   |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|     r      |      k      |    .    |" << endl;
        cout << "|  Sq root   |    Clear    |  Close  |" << endl;
        cout << "|------------------------------------|" << endl;
    }

    void enter_values()
    {
        while (operation != '.')
        {

            if (converter)
            {
                cout << "Enter the Operation You want to perfom :" << endl;
                cin >> operation;

                if (!(operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%' || operation == 'L' || operation == 'S' || operation == 'C' || operation == 'P' || operation == 's' || operation == 'c' || operation == 't' || operation == 'r' || operation == 'k' || operation == '.'))
                {
                    cout << "Error ! You Entered Wrong operation " << endl;
                    answer = 0;
                    continue;
                }

                if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%' || operation == 'P')
                {
                    num1 = answer;
                    cout << "Enter the Second number :" << endl;
                    cin >> num2;
                }
                else if (operation == 'k' || operation == '.')
                {
                }
                else
                {
                    num1 = answer;
                }
            }

            else
            {
                cout << "Enter the Operation You want to perfom :" << endl;
                cin >> operation;

                if (!(operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%' || operation == 'L' || operation == 'S' || operation == 'C' || operation == 'P' || operation == 's' || operation == 'c' || operation == 't' || operation == 'r' || operation == 'k' || operation == '.'))
                {
                    cout << "Error ! You Entered Wrong operation " << endl;
                    answer = 0;
                    continue;
                }
                if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%' || operation == 'P')
                {
                    cout << "Enter the First Number :" << endl;
                    cin >> num1;
                    cout << "Enter the Second number :" << endl;
                    cin >> num2;
                }
                else if (operation == 'k' || operation == '.')
                {
                }
                else
                {
                    cout << "Enter the Number :" << endl;
                    cin >> num1;
                }
                converter = true;
            }
            input_operation();
        }
    }
    void run()
    {
        show_calculator();
        enter_values();
    }

    void input_operation()
    {
        switch (operation)
        {
        case '+':
            answer = num1 + num2;
            break;
        case '-':
            answer = num1 - num2;
            break;
        case '*':
            answer = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                cout << "Error ! Division by Zero is Not possible " << endl;
                answer = 0;
            }
            else
            {
                answer = num1 / num2;
            }
            break;
        case '%':
            if (num2 == 0)
            {
                cout << "Error ! Modulus of Zero is not allowed " << endl;
                answer = 0;
            }
            else if ((num1 != int(num1)) || (num2 != int(num2)))
            {
                cout << "Warning ! Modulus operator works only with integers " << endl;
                answer = 0;
            }

            else
            {
                answer = int(num1) % int(num2);
            }
            break;
        case 'L':
            if (num1 <= 0)
            {
                cout << "Error ! Input Must be greater than Zero " << endl;
                answer = 0;
            }
            else
            {
                answer = log(num1);
            }
            break;
        case 'S':
            answer = num1 * num1;
            break;
        case 'C':
            answer = num1 * num1 * num1;
            break;
        case 'P':
            answer = pow(num1, num2);
            break;
        case 's':
            answer = sin(num1 * M_PI / 180.0);
            break;
        case 'c':
            answer = cos(num1 * M_PI / 180.0);
            break;
        case 't':
            answer = tan(num1 * M_PI / 180.0);
            break;
        case 'r':
            if (num1 < 0)
            {
                cout << "Error ! Square root of Negative number is not posible " << endl;
                answer = 0;
            }
            else
            {

                answer = sqrt(num1);
            }
            break;
        case 'k':
            converter = false;
            num1 = 0.0;
            num2 = 0.0;
            answer = 0.0;
            break;
        case '.':
            cout << "Caculator Closed ! Goodbye " << endl;
            break;

        default:
            cout << "~~~ Oops ! You Entered an Invalid Operation ~~~" << endl;
            break;
        }
        display_output(answer);
    }
};
int main()
{
    calculator obj;
    obj.run();

    return 0;
}