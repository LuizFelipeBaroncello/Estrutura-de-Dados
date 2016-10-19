#include <iostream>
#include <string>

#include "user_interaction.h"

using namespace std;

UserInteraction::UserInteraction()
{
    //ctor
}

UserInteraction::~UserInteraction()
{
    //dtor
}

bool UserInteraction::select_entry_with_file()
{
    unsigned int entry;

    cout << "Como deseja iniciar os parâmetros do programa?" << "\n\n"
         << "1. Os parâmetros serão pegos pelo arquivo input.dat." << "\n"
         << "2. Os parâmetros serão escolhidos manualmente." << "\n\n";

    cin >> entry;

    if (entry < 1 || entry > 2) {
        do {
            cout << "/nPor favor, selecione ou o número 1 ou o número 2." << "\n\n";

            cout << "Como deseja iniciar os parâmetros do programa?" << "\n\n"
                 << "1. Os parâmetros serão pegos pelo arquivo input.dat." << "\n"
                 << "2. Os parâmetros serão escolhidos manualmente.";

            cin >> entry;
        } while (entry < 1 || entry > 2);
    }

    if (entry == 1)
        return true;
    else
        return false;
}

string UserInteraction::get_string(string msg)
{
    string input;
    cout << "Caso necessário, utilize (_) ou (-) ao invés de (espaços) \npara espaçamentos entre duas palavas.\n\n";
    cout << msg;
    cin >> input;
    return input;
}

unsigned int UserInteraction::get_unsigned_int(string msg)
{
    unsigned int input;
    cout << msg;
    cin >> input;
    return input;
}

string UserInteraction::get_string_with_index(string msg, int index)
{
    string input;
    cout << msg << " [" << index << "]: ";
    cin >> input;
    return input;
}

unsigned int UserInteraction::get_unsigned_int_with_index(string msg, int index)
{
    unsigned int input;
    cout << msg << " [" << index << "]: ";
    cin >> input;
    return input;
}

double UserInteraction::get_double_with_index(string msg, int index)
{
    double input;
    cout << msg << " [" << index << "]: ";
    cin >> input;
    return input;
}
