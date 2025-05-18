#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "clsExpressionEvaluator.h"
using namespace std;

class clsUtil
{
public:

    static string NumberToText(int Number) {
        if (Number == 0) return "zero ";

        if (Number < 0)
            return "menos " + NumberToText(-Number);

        if (Number >= 1 && Number <= 19) {
            string arr[] = { "", "um","dois","três","quatro","cinco","seis","sete",
                "oito","nove","dez","onze","doze","treze","quatorze",
                "quinze","dezesseis","dezessete","dezoito","dezenove" };
            return arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99) {
            string arr[] = { "", "", "vinte","trinta","quarenta","cinquenta","sessenta",
                "setenta","oitenta","noventa" };
            return arr[Number / 10] + (Number % 10 ? " e " + NumberToText(Number % 10) : " ");
        }

        if (Number == 100)
            return "cem ";

        if (Number >= 100 && Number <= 199)
            return "cento " + NumberToText(Number % 100);

        if (Number >= 200 && Number <= 999)
            return NumberToText(Number / 100) + "centos " + NumberToText(Number % 100);

        if (Number >= 1000 && Number <= 1999)
            return "mil " + NumberToText(Number % 1000);

        if (Number >= 2000 && Number <= 999999)
            return NumberToText(Number / 1000) + "mil " + NumberToText(Number % 1000);

        if (Number >= 1000000 && Number <= 1999999)
            return "um milhão " + NumberToText(Number % 1000000);

        if (Number >= 2000000 && Number <= 999999999)
            return NumberToText(Number / 1000000) + "milhões " + NumberToText(Number % 1000000);

        if (Number >= 1000000000 && Number <= 1999999999)
            return "um bilhão " + NumberToText(Number % 1000000000);

        return NumberToText(Number / 1000000000) + "bilhões " + NumberToText(Number % 1000000000);
    }


    static string NumberToText( long double Number) {
        int intPart = static_cast<long long>(Number);
        double fracPart = Number - intPart;

        string result = NumberToText(intPart);

        if (fracPart > 0.00001) {
            result += "vírgula ";

            // استخراج الأرقام بعد الفاصلة
            string fracStr = to_string(fracPart).substr(2); // بعد "0."

            // إزالة الأصفار الزائدة في النهاية
            while (!fracStr.empty() && fracStr.back() == '0')
                fracStr.pop_back();

            for (char c : fracStr)
                result += NumberToText(static_cast<int>(c - '0'));

        }

        return result;
    }


    static string GetTestExpression(int index) {
        string expressions[19] = {
            "2 + 3 * 4",
            "10 / 2 + 7",
            "(8 + 2) * 5",
            "5 * (6 - 2)",
            "100 / (4 * 5)",
            "2 ^ 3",
            "10 + 20 * 30",
            "100 / (2 + 3)",
            "3 + 4 * 2 / (1 - 5) ^ 2",
            "(2 + 3) * 4 ^ 2",
            "5 + 7 * (8 - 6)",
            "(20 + 5) / 5",
            "9 * (3 + 7) - 50",
            "2 + 3 * (4 ^ 2 - 1)",
            "((10 * 5 / 2 + 5 ) / 10) ^ 2",
            " 5 * -3",
            "7 + -2",    
            "(4 + -1) * 5",
            "- 5 + 3"
        };

        return expressions[index];

    }
    static void Start() {
        string expression;
        clsExpressionEvaluator<long double> evaluator;

        cout << "\t\t\tCalcletar\n\n";

        for (int i = 0; i < 15; i++) {
            cout << endl << GetTestExpression(i) << endl;
            long double result = evaluator.Evaluate(GetTestExpression(i));
            cout << "Result: " << result << endl;
            cout << NumberToText(result) << endl;
        }

        char Anser = 'y';
        while (Anser == 'y') {

            cout << "\nEnter a math expression: ";
            getline(cin, expression);

            try {
                long double result = evaluator.Evaluate(expression);
                cout << "\nResult: " << result << endl;
                cout << NumberToText(result) << endl;
            }
            catch (const exception& ex) {
                cout << "\nError: " << ex.what() << endl;
            }
            cout << "\nDo you want to continue? y/n ";
            cin >> Anser;
            cin.ignore();
        }

    }
};

