#include "PbnBoardAnalyzer.h"
#include "hands.h"

#include <cstring>

namespace manipulators
{

    void PbnBoardAnalyzer::analyze(PbnFile &pbnFile)
    {

        ddTableDealPBN tableDealPBN;
        ddTableResults table;

        int res;
        char line[80];
        bool match;


        strcpy (tableDealPBN.cards, PBN[0]);

        res = CalcDDtablePBN(tableDealPBN, &table);

        if (res != RETURN_NO_FAULT)
        {
            ErrorMessage(res, line);
            printf("DDS error: %s\n", line);
        }

        match = CompareTable(&table, 0);

        sprintf(line,
                "CalcDDtable, hand %d: %s\n",
                1, (match ? "OK" : "ERROR"));

        PrintPBNHand(line, tableDealPBN.cards);

        PrintTable(&table);
    }
}