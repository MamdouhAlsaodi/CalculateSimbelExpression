#pragma once
#include <iostream>
using namespace std;


class clsUtil 
{
public:
    
    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }
    static string GetTestExpression(int index) {
        string expressions[15] = {
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
            "((10 * 5 / 2 + 5 ) / 10) ^ 2"
        };

        return expressions[index];
    
    }
};

