#include <iostream>
#include <string>
#include "clsExpressionEvaluator.h"
#include"clsUtil.h"

using namespace std;


void Start() {
    string expression;
    clsExpressionEvaluator<long double> evaluator;

    cout << "\t\t\tCalcletar\n\n";

    for (int i = 0; i < 15; i++) {
            cout << endl << clsUtil::GetTestExpression(i) << endl;
            long double result = evaluator.Evaluate(clsUtil::GetTestExpression(i));
            cout << "Result: " << result << endl; 
    }

    char Anser = 'y'; 
    while (Anser == 'y')  { 
        
          cout << "\nEnter a math expression: ";
        getline(cin, expression);

        try {
            long double result = evaluator.Evaluate(expression);
            cout << "\nResult: " << result << endl;
        }
        catch (const exception& ex) {
            cout << "\nError: " << ex.what() << endl;
        }
        cout << "\nDo you want to continue? y/n ";
        cin >> Anser;
        cin.ignore();
    }
        
}
    

int main() {
    Start();
    return 0;
}

