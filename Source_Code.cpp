#include "header.h"

void clearScreen();
void displayHomepage();
int mainmenu();
void displaySubjects1();
void displaySubjects2();
void displaySubjects3();
void displayTasks();
void end();
// Load Data //
bool load(vector<long>&, vector<int>&, vector<int>&, vector<int>&, vector<int>&, int, bool);

// Sort Ascending/Descending //
void sortAsc (vector<long>, vector<int>, vector<int>, vector<int>, vector<int>, int, int, int);
void sortDesc (vector<long>, vector<int>, vector<int>, vector<int>, vector<int>, int, int, int);

// Minimum & Maximum Marks //
int minMarks(int [], int);
int maxMarks(int [], int);

// Mean //
double meanValue(int [], int);

// Median //
int medianValue(int [],int);

// Variance //
double var(int [], int );

// Standard Deviation //
double STD(int [], int);

// Frequency Dist. Marks //
void frequency(int [], int);

// Histogram //
void histogram(int [], int);
void printHist(string*);


// Linear Regression & Pearson Correlation Table //
void LinearPearsonTable (const int [], const int [], int, string, string);

// Pearson Correlation //
int pearsonNumerator (const int [], const int [], int);
double pearsonDenominator(const int [], const int[], int);

// Linear Regression Line //
double slope (const int [], const int [], int);
double intercept (const int [], const int [], int);

// Above & Below Average //
void aboveBelowAvg (int [], int, int, int, bool);

// TXT & HTML //
void makeTXT (string, int, int, int, double, int, double, double);
void makeHTML (string, string, int, int, int, double, int, double, double);
void compareTxtHtml (int [], int [], int, string, string, double, double, int, double, double);
void FreqHistoTxtHtml (int [], int, int);
void AboveBelowAvgTxtHtml(int [], int , int , int , bool);
void sortAscTxtHtml (vector<long>, vector<int>, vector<int>, vector<int>, vector<int>, int, int, int);
void sortDescTxtHtml (vector<long>, vector<int>, vector<int>, vector<int>, vector<int>, int, int, int);

const int SIZE = 100;       //constant size of the data and row(ROWS)
const int COLS = 5;         //constant size of column(COLS)

int main()
{
    char anyKey, choice5, choice7;
    string stuID, stuAge, maths, science, malay, filename, filename2, subjectX, subjectY;
    vector<long> id;
    vector<int> age, sub1, sub2, sub3;
    int sub[SIZE], subx[SIZE], suby[SIZE], min, max, mainchoice, choice1, choice2, choice3, choice4, choice6, subject1, subject2, median, result;
    double mean, variance, std, a, b, rootResult, pearsonCoefficient;
    bool status = false, status2 = false, status3 = false, status4 = false, status5 = false, status6 = false, status7 = false, sts2 = false, status8 = false, status9 = false;

    displayHomepage();
    cin.get (anyKey);
    clearScreen();
    menu:
    do
    {
        clearScreen();
        cout << endl;
        mainchoice = mainmenu();
        if(mainchoice == 1)
        {
            clearScreen();
            if(status4 == false)
                status4 = load(id, age, sub1, sub2, sub3, SIZE, status4);
            do
            {
                cout << endl;
                cout << "--------- Next Screen ---------" << endl << endl;
                cout << "===============================" << endl;
                cout << "|         Sorting Data        |" << endl;
                cout << "===============================" << endl << endl;
                cout << " Do you want to sort the data? " << endl;
                cout << "       Enter (Y/y) : Yes       " << endl;
                cout << "       Enter (N/n) : No        " << endl << endl;
                cout << "-------------------------------" << endl << endl;
                cout << "  Please enter your choice: ";
                cin >> choice5;
                switch (choice5)
                {
                    case 'Y':
                    case 'y': {
                        here:
                        clearScreen();
                        cout << endl;
                        cout << "--------- Next Screen ---------" << endl << endl;
                        AscDesc:
                        cout << "===============================" << endl;
                        cout << "|         Sorting Data        |" << endl;
                        cout << "===============================" << endl << endl;
                        cout << "     1. Ascending              " << endl;
                        cout << "     2. Descending             " << endl;
                        cout << "     0. Go back to main menu   " << endl << endl;
                        cout << "-------------------------------" << endl << endl;
                        status3 = true;
                    }
                        break;
                    case 'N':
                    case 'n': {
                        goto statusTrue;
                    }
                        break;
                    default: {
                        clearScreen();
                        cout << endl;
                        cout << "------------ ERROR ------------" << endl << endl;
                        cout << "        Invalid choice!        " << endl;
                        cout << "       Please enter again      " << endl;
                    }
                        break;
                }
            } while (status3 == false);
            if(choice5 == 'y' || choice5 == 'Y')
            {
                cin >> choice6;
                status3 = true;
            }
            clearScreen();
            if (choice6 == 1)
            {
                do{
                cout << endl;
                cout << "--------- Next Screen ---------" << endl << endl;
                here1:
                cout << "===============================" << endl;
                cout << "|    Sorting Data Ascending   |" << endl;
                cout << "===============================" << endl << endl;
                cout << "       1. Student ID           " << endl;
                cout << "       2. Student Age          " << endl;
                cout << "       3. Maths Marks          " << endl;
                cout << "       4. Science Marks        " << endl;
                cout << "       5. Malay Marks          " << endl;
                cout << "       0. Go back              " << endl << endl;
                cout << "-------------------------------" << endl << endl;
                cout << "   Please choose which column  " << endl;
                cout << " you want to sort in ascending ";
                cin >> choice4;
                if(choice4 > 0 && choice4 <= 5)
                {
                    sortAsc (id, age, sub1, sub2, sub3, choice4, SIZE, COLS);
                    cin.get (anyKey);
                    cin.ignore();
                    clearScreen();
                    do
                    {
                        cout << endl;
                        cout << "------------ Next Screen ------------" << endl << endl;
                        cout << "=====================================" << endl;
                        cout << "|            Save Result            |" << endl;
                        cout << "=====================================" << endl << endl;
                        cout << "   Do you want to save the results?  " << endl;
                        cout << "          Enter (Y/y) : Yes          " << endl;
                        cout << "          Enter (N/n) : No           " << endl << endl;
                        cout << "-------------------------------------" << endl << endl;
                        cout << "    Please enter your choice: ";
                        cin >> choice7;
                        switch (choice7)
                        {
                            case 'Y':
                            case 'y': {
                                clearScreen();
                                cout << endl;
                                cout << "------------ Next Screen ------------" << endl << endl;
                                cout << "=====================================" << endl;
                                cout << "|            Save Result            |" << endl;
                                cout << "=====================================" << endl << endl;
                                cout << "      Results have been saved in     " << endl;
                                cout << "          txt and html file          " << endl << endl;
                                cout << "-------------------------------------" << endl << endl;
                                cout << " Press ENTER to go back to main menu ";
                                cin.get (anyKey);
                                cin.ignore();
                                status9 = true;
                            }
                                break;
                            case 'N':
                            case 'n': {
                                goto statusTrue6;
                            }
                                break;
                            default: {
                                clearScreen();
                                cout << endl;
                                cout << "--------------- ERROR ---------------" << endl << endl;
                                cout << "            Invalid choice!          " << endl;
                                cout << "          Please enter again         " << endl << endl;
                            }
                                break;
                        }
                    }while (status9 == false);
                    if(choice7 == 'y' || choice7 == 'Y')
                        sortAscTxtHtml (id, age, sub1, sub2, sub3, choice4, SIZE, COLS);
                    statusTrue6:
                    status3 = true;
                    goto statusTrue;
                }
                else if(choice4 == 0)
                    goto here;
                else
                {
                    clearScreen();
                    cout << endl;
                    cout << "------------ ERROR ------------" << endl << endl;
                    cout << "         Invalid choice!       " << endl;
                    cout << "       Please enter again      " << endl << endl;
                    goto here1;
                }
                } while (choice4 < 0 || choice4 > 5 );
            }
            else if (choice6 == 2)
            {
                clearScreen();
                cout << endl;
                cout << "--------- Next Screen ---------" << endl << endl;
                here2:
                cout << "===============================" << endl;
                cout << "|   Sorting Data Descending   |" << endl;
                cout << "===============================" << endl << endl;
                cout << "       1. Student ID           " << endl;
                cout << "       2. Student Age          " << endl;
                cout << "       3. Maths Marks          " << endl;
                cout << "       4. Science Marks        " << endl;
                cout << "       5. Malay Marks          " << endl;
                cout << "       0. Go back              " << endl << endl;
                cout << "-------------------------------" << endl << endl;
                cout << "   Please choose which column  " << endl;
                cout << " you want to sort in descending ";
                cin >> choice4;
                if(choice4 > 0 && choice4 <= 5)
                {
                    sortDesc (id, age, sub1, sub2, sub3, choice4, SIZE, COLS);
                    cin.get (anyKey);
                    cin.ignore();
                    clearScreen();
                    do
                    {
                        cout << endl;
                        cout << "------------ Next Screen ------------" << endl << endl;
                        cout << "=====================================" << endl;
                        cout << "|            Save Result            |" << endl;
                        cout << "=====================================" << endl << endl;
                        cout << "   Do you want to save the results?  " << endl;
                        cout << "          Enter (Y/y) : Yes          " << endl;
                        cout << "          Enter (N/n) : No           " << endl << endl;
                        cout << "-------------------------------------" << endl << endl;
                        cout << "    Please enter your choice: ";
                        cin >> choice7;
                        switch (choice7)
                        {
                            case 'Y':
                            case 'y': {
                                clearScreen();
                                cout << endl;
                                cout << "------------ Next Screen ------------" << endl << endl;
                                cout << "=====================================" << endl;
                                cout << "|            Save Result            |" << endl;
                                cout << "=====================================" << endl << endl;
                                cout << "      Results have been saved in     " << endl;
                                cout << "          txt and html file          " << endl << endl;
                                cout << "-------------------------------------" << endl << endl;
                                cout << " Press ENTER to go back to main menu ";
                                cin.get (anyKey);
                                cin.ignore();
                                status8 = true;
                            }
                                break;
                            case 'N':
                            case 'n': {
                                goto statusTrue5;
                            }
                                break;
                            default: {
                                clearScreen();
                                cout << endl;
                                cout << "------------ ERROR ------------" << endl << endl;
                                cout << "         Invalid choice!       " << endl;
                                cout << "        Please enter again     " << endl;
                            }
                                break;
                        }
                    }while (status8 == false);
                    if(choice7 == 'y' || choice7 == 'Y')
                        sortDescTxtHtml (id, age, sub1, sub2, sub3, choice4, SIZE, COLS);

                    statusTrue5:
                    status3 = true;
                    goto statusTrue;
                }
                else if(choice4 == 0)
                    goto here;
                else
                {
                    clearScreen();
                    cout << endl;
                    cout << "------------ ERROR ------------" << endl << endl;
                    cout << "         Invalid choice!       " << endl;
                    cout << "       Please enter again      " << endl << endl;
                    goto here2;
                }
            }
            else if(choice6 == 0)
                goto menu;
            else
            {
                clearScreen();
                cout << endl;
                cout << "------------ ERROR ------------" << endl << endl;
                cout << "         Invalid choice!       " << endl;
                cout << "        Please enter again     " << endl << endl;
                goto AscDesc;
            }
            statusTrue:
            status = true;
            goto menu;
        }
        else if (mainchoice == 2)
        {
            trueStatement:
            clearScreen();
            do
            {
                if (status == true)
                {
                    do
                    {
                        displaySubjects1();
                        cout << "   Please enter your choice: ";
                        cin >> choice1;
                        clearScreen();
                        if (choice1 == 1)
                        {
                            for (int i = 0; i < SIZE; i++)
                                sub[i] = sub1[i];
                        }
                        else if (choice1 == 2)
                        {
                            for (int i = 0; i < SIZE; i++)
                                sub[i] = sub2[i];
                        }
                        else if (choice1 == 3)
                        {
                            for (int i = 0; i < SIZE; i++)
                                sub[i] = sub3[i];
                        }
                        else if (choice1 == 0)
                            clearScreen();
                        else
                        {
                            cout << endl;
                            clearScreen();
                            cout << "------------ ERROR ------------" << endl << endl;
                            cout << "        Invalid choice!        " << endl;
                            cout << "  Please choose choice1 again  " << endl << endl;
                        }
                    } while (choice1 < 0 || choice1 > 3);
                    if (choice1 != 0)
                    {
                        do
                        {
                            displayTasks();
                            cin >> choice2;
                            clearScreen();
                            switch (choice2)
                            {
                                case 1 :
                                {
                                    min = minMarks(sub, SIZE);
                                    max = maxMarks(sub, SIZE);
                                    cout << "--------------------- Next Screen --------------------" << endl << endl;
                                    cout << "     =============================================    " << endl;
                                    cout << "     |\tSubject\t|    Min Marks  |    Max Marks   |   " << endl;
                                    cout << "     =============================================    " << endl;
                                    cout << "     |\t";
                                    if (choice1 == 1)
                                        cout << "Maths";
                                    else if (choice1 == 2)
                                        cout << "Science";
                                    else if (choice1 == 3)
                                        cout << "Malay";
                                    cout << "\t|\t" << min << setw(8) << "|\t" << max << setw(8) << "|" << endl;
                                    cout << "     =============================================    " << endl << endl;
                                    cout << "               Press ENTER to go back.  ";
                                    cin.get (anyKey);
                                    cin.ignore();
                                    clearScreen();
                                }
                                    break;
                                case 2 :
                                {
                                    mean = meanValue(sub, SIZE);
                                    cout << "---------- Next Screen ----------" << endl << endl;
                                    cout << "     =======================        " << endl;
                                    cout << "     |\tSubject\t|   Mean   |       " << endl;
                                    cout << "     =======================        " << endl;
                                    cout << "     |\t";
                                    if (choice1 == 1)
                                        cout << "Maths";
                                    else if (choice1 == 2)
                                        cout << "Science";
                                    else if (choice1 == 3)
                                        cout << "Malay";
                                    cout << "\t|   " << mean << "  |" << endl;
                                    cout << "     =======================        " << endl << endl;
                                    cout << "    Press ENTER to go back.  " << endl;
                                    cin.get (anyKey);
                                    cin.ignore();
                                    clearScreen();
                                }
                                    break;
                                case 3 :
                                    {
                                        clearScreen();
                                        median = medianValue (sub, SIZE);              //Function call to find the median
                                        cout << "---------- Next Screen ----------" << endl << endl;
                                        cout << "     =======================        " << endl;
                                        cout << "     |\tSubject\t|  Median  |       " << endl;
                                        cout << "     =======================        " << endl;
                                        cout << "     |\t";
                                        if (choice1 == 1)
                                            cout << "Maths";
                                        else if (choice1 == 2)
                                            cout << "Science";
                                        else if (choice1 == 3)
                                            cout << "Malay";
                                        cout << "\t|    " << median << "    |" << endl;
                                        cout << "     =======================        " << endl << endl;
                                        cout << "    Press ENTER to go back. " << endl;
                                        cin.get (anyKey);
                                        cin.ignore();
                                        clearScreen();
                                    }
                                        break;
                                case 4 :
                                    {
                                        variance = var(sub, SIZE);
                                        cout << "-------------- Next Screen --------------" << endl << endl;
                                        cout << "     ============================        " << endl;
                                        cout << "     |\tSubject\t|    Variance\t|        " << endl;
                                        cout << "     ============================        " << endl;
                                        cout << "     |\t";
                                        if (choice1 == 1)
                                            cout << "Maths";
                                        else if (choice1 == 2)
                                            cout << "Science";
                                        else if (choice1 == 3)
                                            cout << "Malay";
                                        cout << "\t|    " << variance << "\t|" << endl;
                                        cout << "     ============================        " << endl << endl;
                                        cout << "     Press ENTER to go back.  " << endl;
                                        cin.get (anyKey);
                                        cin.ignore();
                                        clearScreen();
                                    }
                                        break;
                                case 5 :
                                    {
                                        std = STD(sub, SIZE);

                                        cout << "---------- Next Screen ----------" << endl << endl;
                                        cout << "     =======================        " << endl;
                                        cout << "     |\tSubject\t|    STD   |       " << endl;
                                        cout << "     =======================        " << endl;
                                        cout << "     |\t";
                                        if (choice1 == 1)
                                            cout << "Maths";
                                        else if (choice1 == 2)
                                            cout << "Science";
                                        else if (choice1 == 3)
                                            cout << "Malay";
                                        cout << "\t|  " << std << " |" << endl;
                                        cout << "     =======================        " << endl << endl;
                                        cout << "    Press ENTER to go back.  " << endl;
                                        cin.get (anyKey);
                                        cin.ignore();
                                        clearScreen();
                                    }
                                        break;
                                case 6 :
                                    {
                                        cout << "---------- Next Screen ----------" << endl << endl;
                                        cout << "        =================        " << endl;
                                        cout << "        |   Subject\t|        " << endl;
                                        cout << "        =================        " << endl;
                                        cout << "        |   ";
                                        if (choice1 == 1)
                                            cout << "Maths\t|" << endl;
                                        else if (choice1 == 2)
                                            cout << "Science\t|" << endl;
                                        else if (choice1 == 3)
                                            cout << "Malay\t|" << endl;
                                        cout << "        =================        " << endl;

                                        frequency(sub, SIZE);     // frequency function call
                                        histogram(sub, SIZE);           // histogram function call
                                        cout << "  Press ENTER to continue.  " << endl;
                                        cin.get (anyKey);
                                        cin.ignore();
                                        clearScreen();
                                        do
                                        {
                                            cout << endl;
                                            cout << "------------ Next Screen ------------" << endl << endl;
                                            cout << "=====================================" << endl;
                                            cout << "|            Save Result            |" << endl;
                                            cout << "=====================================" << endl << endl;
                                            cout << "   Do you want to save the results?  " << endl;
                                            cout << "          Enter (Y/y) : Yes          " << endl;
                                            cout << "          Enter (N/n) : No           " << endl << endl;
                                            cout << "-------------------------------------" << endl << endl;
                                            cout << "    Please enter your choice: ";
                                            cin >> choice7;
                                            switch (choice7)
                                            {
                                                case 'Y':
                                                case 'y': {
                                                    clearScreen();
                                                    cout << endl;
                                                    cout << "------------ Next Screen ------------" << endl << endl;
                                                    cout << "=====================================" << endl;
                                                    cout << "|            Save Result            |" << endl;
                                                    cout << "=====================================" << endl << endl;
                                                    cout << "      Results have been saved in     " << endl;
                                                    cout << "          txt and html file          " << endl << endl;
                                                    cout << "-------------------------------------" << endl << endl;
                                                    cout << "Press ENTER to go back to Tasks page ";
                                                    cin.get (anyKey);
                                                    cin.ignore();
                                                    status6 = true;
                                                }
                                                    break;
                                                case 'N':
                                                case 'n': {
                                                    goto statusTrue3;
                                                }
                                                    break;
                                                default: {
                                                    clearScreen();
                                                    cout << endl;
                                                    cout << "--------------- ERROR ---------------" << endl << endl;
                                                    cout << "            Invalid choice!          " << endl;
                                                    cout << "           Please enter again        " << endl << endl;
                                                }
                                                    break;
                                            }
                                        } while (status6 == false);
                                        if(choice7 == 'y' || choice7 == 'Y')
                                            FreqHistoTxtHtml (sub, SIZE, choice1);
                                        statusTrue3:
                                        status3 = true;
                                        clearScreen();
                                    }
                                        break;
                                case 7 :
                                    {
                                        mean = meanValue(sub, SIZE);
                                        aboveBelowAvg (sub, choice1, mean, SIZE, status2);
                                        cout << "    Press ENTER to continue.  " << endl;
                                        cin.get (anyKey);
                                        cin.ignore();
                                        clearScreen();
                                        do
                                        {
                                            cout << endl;
                                            cout << "------------ Next Screen ------------" << endl << endl;
                                            cout << "=====================================" << endl;
                                            cout << "|            Save Result            |" << endl;
                                            cout << "=====================================" << endl << endl;
                                            cout << "   Do you want to save the results?  " << endl;
                                            cout << "          Enter (Y/y) : Yes          " << endl;
                                            cout << "          Enter (N/n) : No           " << endl << endl;
                                            cout << "-------------------------------------" << endl << endl;
                                            cout << "    Please enter your choice: ";
                                            cin >> choice7;
                                            switch (choice7)
                                            {
                                                case 'Y':
                                                case 'y': {
                                                    clearScreen();
                                                    cout << endl;
                                                    cout << "------------ Next Screen ------------" << endl << endl;
                                                    cout << "=====================================" << endl;
                                                    cout << "|            Save Result            |" << endl;
                                                    cout << "=====================================" << endl << endl;
                                                    cout << "      Results have been saved in     " << endl;
                                                    cout << "          txt and html file          " << endl << endl;
                                                    cout << "-------------------------------------" << endl << endl;
                                                    cout << "Press ENTER to go back to Tasks page ";
                                                    cin.get (anyKey);
                                                    cin.ignore();
                                                    status7 = true;
                                                }
                                                    break;
                                                case 'N':
                                                case 'n': {
                                                    goto statusTrue4;
                                                }
                                                    break;
                                                default: {
                                                    clearScreen();
                                                    cout << endl;
                                                    cout << "------------ ERROR ------------" << endl << endl;
                                                    cout << "         Invalid choice!       " << endl;
                                                    cout << "        Please enter again     " << endl << endl;
                                                    cout << "-------------------------------" << endl << endl;
                                                }
                                                    break;
                                            }
                                        }while (status7 == false);
                                        if(choice7 == 'y' || choice7 == 'Y')
                                            AboveBelowAvgTxtHtml(sub, choice1, mean, SIZE, sts2);
                                        statusTrue4:
                                        status3 = true;
                                        clearScreen();
                                    }
                                        break;
                                case 0 :
                                        break;
                                default :
                                    {
                                        cout << "------------- ERROR -------------" << endl << endl;
                                        cout << "          Invalid choice!        " << endl;
                                        cout << "        Please enter again       " << endl << endl;
                                    }
                            }
                        } while (choice2 != 0);
                    }
                }
                else
                {
                    cout << endl;
                    clearScreen();
                    cout << "---------------- ERROR ----------------" << endl << endl;
                    cout << "         There are no data found       " << endl;
                    cout << "      Please load data from a file     " << endl << endl;
                    cout << "---------------------------------------" << endl << endl;
                    cout << " Press ENTER to go back to Main Menu ";
                    cin.get (anyKey);
                    cin.ignore();
                    goto menu;
                }
            } while (choice1 != 0);
        }
        else if (mainchoice == 3)
        {
            clearScreen();
            if (status == true)
            {
                do
                {
                    subject1:
                    do
                    {
                        displaySubjects2();
                        cout << "Please choose your 1st subject: ";
                        cin >> subject1;
                        if (subject1 == 1)
                        {
                            for (int i = 0; i < SIZE; i++)
                                subx[i] = sub1[i];
                            subjectX = "SubjectX is Maths";
                        }
                        else if (subject1 == 2)
                        {
                        for (int i = 0; i < SIZE; i++)
                                subx[i] = sub2[i];
                            subjectX = "SubjectX is Science";
                        }
                        else if (subject1 == 3)
                        {
                            for (int i = 0; i < SIZE; i++)
                                subx[i] = sub3[i];
                            subjectX = "SubjectX is Malay";
                        }
                        else if (subject1 == 0)
                            goto menu;
                        else
                        {
                            cout << endl;
                            clearScreen();
                            cout << "------------ ERROR ------------" << endl << endl;
                            cout << "        Invalid choice!        " << endl;
                            cout << " Please choose subject1 again. " << endl << endl;
                        }
                    } while (subject1 < 1 || subject1 > 3);
                    clearScreen();
                    do
                    {
                        displaySubjects2();
                        cout << " Please choose your 2nd subject: ";
                        cin >> subject2;

                        if (subject2 == 1)
                        {
                            for (int i = 0; i < SIZE; i++)
                                suby[i] = sub1[i];
                            subjectY = "SubjectY is Maths";
                        }
                        else if (subject2 == 2)
                        {
                            for (int i = 0; i < SIZE; i++)
                                suby[i] = sub2[i];
                            subjectY = "SubjectY is Science";
                        }
                        else if (subject2 == 3)
                        {
                            for (int i = 0; i < SIZE; i++)
                                suby[i] = sub3[i];
                            subjectY = "SubjectY is Malay";
                        }
                        else if (subject2 == 0)
                            goto subject1;
                        else
                        {
                            cout << endl;
                            clearScreen();
                            cout << "------------ ERROR ------------" << endl << endl;
                            cout << "        Invalid choice!        " << endl;
                            cout << " Please choose subject2 again. " << endl << endl;
                        }
                    } while (subject2 < 1 || subject2 > 3);
                    if (subject1 == subject2)
                    {
                        clearScreen();
                        cout << endl;
                        cout << "------------ ERROR ------------" << endl << endl;
                        cout << "      You can't choose the     " << endl;
                        cout << "          same subject         " << endl;
                        cout << "       Please choose again     " << endl << endl;
                    }
                } while (subject1 == subject2);

                clearScreen();
                LinearPearsonTable (subx, suby, SIZE, subjectX, subjectY);
                cout << endl;
                cout << "----------- Linear Regression Line -----------" << endl << endl;
                a = slope (subx, suby, SIZE);
                cout << "      = " << a << endl << endl;
                b = intercept (subx, suby, SIZE);
                cout << "      = " << b << endl << endl;
                cout << "   y' = " << a << "x + " << b << endl << endl;
                cout << "------------- Pearson Correlation ------------" << endl << endl;
                result = pearsonNumerator(subx, suby, SIZE);
                cout << "\t\t       = " << result << endl << endl;
                rootResult = pearsonDenominator(subx, suby, SIZE);
                cout << "\t\t         = " << rootResult << endl << endl;
                pearsonCoefficient = result / rootResult;
                cout << "   Pearson's Coefficient = " << result << "/" << rootResult << endl;
                cout << "\t\t\t = " << pearsonCoefficient << endl << endl;
                cout << "----------------------------------------------" << endl << endl;
                cout << "        Press ENTER to continue         " << endl;
                cin.get (anyKey);
                cin.ignore();
                clearScreen();
            }
            else
            {
                cout << endl;
                clearScreen();
                cout << "---------------- ERROR ----------------" << endl << endl;
                cout << "         There are no data found       " << endl;
                cout << "      Please load data from a file     " << endl << endl;
                cout << "---------------------------------------" << endl << endl;
                cout << " Press ENTER to go back to Main Menu ";
                cin.get (anyKey);
                cin.ignore();
                goto menu;
            }
            do
            {
                cout << endl;
                cout << "------------ Next Screen ------------" << endl << endl;
                cout << "=====================================" << endl;
                cout << "|            Save Result            |" << endl;
                cout << "=====================================" << endl << endl;
                cout << "   Do you want to save the results?  " << endl;
                cout << "          Enter (Y/y) : Yes          " << endl;
                cout << "          Enter (N/n) : No           " << endl << endl;
                cout << "-------------------------------------" << endl << endl;
                cout << "    Please enter your choice: ";
                cin >> choice7;

                switch (choice7)
                {
                    case 'Y':
                    case 'y': {
                        clearScreen();
                        cout << endl;
                        cout << "------------ Next Screen ------------" << endl << endl;
                        cout << "=====================================" << endl;
                        cout << "|            Save Result            |" << endl;
                        cout << "=====================================" << endl << endl;
                        cout << "      Results have been saved in     " << endl;
                        cout << "          txt and html file          " << endl << endl;
                        cout << "-------------------------------------" << endl << endl;
                        cout << " Press ENTER to go back to main menu ";
                        cin.get (anyKey);
                        cin.ignore();
                        status5 = true;
                    }
                        break;
                    case 'N':
                    case 'n': {
                        goto statusTrue2;
                    }
                        break;
                    default: {
                        clearScreen();
                        cout << endl;
                        cout << "------------ ERROR ------------" << endl << endl;
                        cout << "         Invalid choice!       " << endl;
                        cout << "        Please enter again     " << endl << endl;
                        cout << "-------------------------------" << endl << endl;
                    }
                        break;
                }
            } while (status5 == false);
            if(choice7 == 'y' || choice7 == 'Y')
                compareTxtHtml (subx, suby, SIZE, subjectX, subjectY, a, b, result, rootResult, pearsonCoefficient);      //print the table in txt
            statusTrue2:
            status3 = true;
            goto menu;
        }
        else if (mainchoice == 4)
        {
            clearScreen();
            if (status == true)
            {
                do
                {
                    displaySubjects3();
                    cout << "   Please enter your choice: ";
                    cin >> choice3;
                    clearScreen();
                    if (choice3 == 1)
                    {
                        for (int i = 0; i < SIZE; i++)
                            sub[i] = sub1[i];
                            min = minMarks(sub, SIZE);
                            max = maxMarks(sub, SIZE);
                            mean = meanValue(sub, SIZE);
                            median = medianValue(sub, SIZE);
                            variance = var(sub, SIZE);
                            std = STD(sub, SIZE);
                            filename = "MathsResult.txt";
                            filename2 = "MathsResult.html";
                    }
                    else if (choice3 == 2)
                    {
                        for (int i = 0; i < SIZE; i++)
                            sub[i] = sub2[i];
                            min = minMarks(sub, SIZE);
                            max = maxMarks(sub, SIZE);
                            mean = meanValue(sub, SIZE);
                            median = medianValue(sub, SIZE);
                            variance = var(sub, SIZE);
                            std = STD(sub, SIZE);
                            filename = "ScienceResult.txt";
                            filename2 = "ScienceResult.html";
                    }
                    else if (choice3 == 3)
                    {
                        for (int i = 0; i < SIZE; i++)
                            sub[i] = sub3[i];
                            min = minMarks(sub, SIZE);
                            max = maxMarks(sub, SIZE);
                            mean = meanValue(sub, SIZE);
                            median = medianValue(sub, SIZE);
                            variance = var(sub, SIZE);
                            std = STD(sub, SIZE);
                            filename = "MalayResult.txt";
                            filename2 = "MalayResult.html";
                    }
                    else if (choice3 == 0)
                    {
                        clearScreen();
                        goto menu;
                    }
                    else
                    {
                        cout << endl;
                        clearScreen();
                        cout << "------------ ERROR ------------" << endl << endl;
                        cout << "        Invalid choice!        " << endl;
                        cout << "  Please choose choice3 again  " << endl << endl;
                    }
                } while (choice3 < 0 || choice3 > 3);

                if(choice3 != 0)
                    makeTXT (filename, choice3, min, max, mean, median, variance, std);
                if(choice3 != 0)
                {
                    string name;
                    if (choice3 == 1) name = "Maths";
                    else if (choice3 == 2) name = "Science";
                    else if (choice3 == 3) name = "Malay";
                    makeHTML(filename2, name, choice3, min, max, mean, median, variance, std);
                }
                cout << endl;
                clearScreen();
                cout << "------------- Next Screen -------------" << endl << endl;
                cout << " Overall results has been successfully " << endl;
                cout << "     saved in a txt and html file!     " << endl << endl;
                cout << "---------------------------------------" << endl << endl;
                cout << " Press ENTER to go back to Main Menu ";
                cin.get (anyKey);
                cin.ignore();
                goto menu;
            }
            else
            {
                cout << endl;
                clearScreen();
                cout << "---------------- ERROR ----------------" << endl << endl;
                cout << "         There are no data found       " << endl;
                cout << "      Please load data from a file     " << endl << endl;
                cout << "---------------------------------------" << endl << endl;
                cout << " Press ENTER to go back to Main Menu ";
                cin.get (anyKey);
                cin.ignore();
                goto menu;
            }
        }
        else if (mainchoice == 0)
        {
            end();
            break;
        }
        else
        {
            cout << endl;
            clearScreen();
            cout << "---------------- ERROR ----------------" << endl << endl;
            cout << "            Invalid choice!            " << endl;
            cout << "      Please choose choice1 again      " << endl << endl;
            cout << "---------------------------------------" << endl << endl;
            cout << " Press ENTER to go back to Main Menu ";
            cin.get (anyKey);
            cin.ignore();
            goto menu;
        }
    } while (choice1 == 0 || mainchoice < 0 || mainchoice > 4);
    return 0;
}

void compareTxtHtml (int subject1[], int subject2[], int size, string subjectx, string subjecty, double gradient, double y_intercept, int nume, double deno, double answer)
{
    int subx[size], suby[size], subxy[size], subxx[size], subyy[size];
    int SumX = 0, SumX2 = 0, SumY = 0, SumY2 = 0;
    double totalx = 0.0, totaly = 0.0, totalxy = 0.0, totalxx = 0.0, totalyy = 0.0, total = 0.0;
    ofstream fout;
    fout.open("LinearPearson_Result.txt", ios::out);
    fout << "----------- Linear & Pearson Results -----------" << endl << endl;
    fout << "               " << subjectx << "              " << endl;
    fout << "               " << subjecty << "              " << endl << endl;
    fout << "===============================================" << endl;
    fout << "|             SubjextX VS SubjectY            |" << endl;
    fout << "===============================================" << endl << endl;
    fout << "No.\t" << "X\t" << "Y\t" << "XY\t" << "X2\t" << "Y2\t" << endl;
    for (int i = 0; i < size; i++)
    {
        subx[i] = subject1[i];
        suby[i] = subject2[i];
    }
    for (int i = 0; i < size; i++)
    {
        subxy[i] = subx[i] * suby[i];
        subxx[i] = subx[i] * subx[i];
        subyy[i] = suby[i] * suby[i];
        fout << (i + 1) << "\t" << subx[i] << "\t" << suby[i] << "\t"
             << subxy[i] << "\t" << subxx[i] << "\t" << subyy[i] << endl;
        totalx += subx[i];
        totaly += suby[i];
        totalxy += subxy[i];
        totalxx += subxx[i];
        totalyy += subyy[i];
    }
    fout << "----------------------------------------------" << endl;
    fout << "Total:\t" << totalx << "\t" << totaly << "\t"
         << totalxy << "\t" << totalxx << "\t" << totalyy << endl;
    fout << "----------------------------------------------" << endl << endl;
    fout << "----------- Linear Regression Line -----------" << endl << endl;
    gradient = (size * totalxy - totalx * totaly) / (size * totalxx - totalx * totalx);
    fout << "   a  = (" << size << " * " << totalxy << " - " << totalx << " * " << totaly << ") / " << endl;
    fout << "        (" << size << " * " << totalxx << " - " << totalx << " * " << totalx << ")" << endl;
    fout << "      = " << gradient << endl << endl;
    y_intercept = (totaly * totalxx - totalx * totalxy) / (size * totalxx - totalx * totalx);
    fout << "   b  = (" << totaly << " * " << totalxx << " - " << totalx << " * " << totalxy << ") / " << endl;
    fout << "        (" << size << " * " << totalxx << " - " << totalx << " * " << totalx << ")" << endl;
    fout << "      = " << y_intercept << endl << endl;
    fout << "   y' = " << gradient << "x + " << y_intercept << endl << endl;
    for (int count = 0; count < size; count++)
    {
        SumX = SumX + subject1[count];
        SumX2 = SumX2 + (subject1[count] * subject1[count]);
        SumY = SumY + subject2[count];
        SumY2 = SumY2 + (subject2[count]*subject2[count]);
    }
    fout << "------------- Pearson Correlation ------------" << endl << endl;
    total = size * totalxy;
    nume = total - (totalx * totaly);
    fout << "   Pearson's Numerator   = " << nume << endl << endl;
    int multiX2 = totalxx * size;
    int multiY2 = totalyy * size;
    int result = (multiX2 - (SumX*SumX))*(multiY2 - (SumY*SumY));
    if(result < 0.0)
        result = abs(result);
    deno = sqrt(result);
    fout << "   Pearson's Denominator = " << deno << endl << endl;
    answer = nume / deno;
    fout << "   Pearson's Coefficient = " << answer << endl << endl;
    fout.close();

    ofstream hout;
    hout.open("LinearPearson_Result.html");
    hout << "<!DOCTYPE html>\n";
    hout << "<html>\n";
    hout << "\t<head>\n";
    hout << "\t\t<title>Results Report</title>\n";
    hout << "\t</head>\n";
// open body
    hout << "\t<body>\n";
    hout << "\t\t<h1 align = \"center\"><font size = \"5\">----------- Linear & Pearson Results -----------</font></h1>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">" << subjectx << "</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">" << subjecty << "</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===========================</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">   SubjextX VS SubjectY    </font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===========================</font></p>\n";
    hout << "\t\t\t<table border = \"1\" align = \"center\" width = \"400\" cellpadding = \"5\" cellspacing = \"5\">\n";
    hout << "\t\t\t<caption align = \"center\"><font size = \"5\"> Linear and Pearson Table </font></caption>\n";
    hout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> No. </th><th align = \"center\">  X </th><th align = \"center\"> Y </th>"
         << "<th align = \"center\"> XY </th><th align = \"center\"> X2 </th><th align = \"center\"> Y2 </th>\n\t\t\t\t</tr>\n";
    for(int i = 0; i < size; i++)
    {
        hout << "\t\t\t\t<tr>\n\t\t\t\t\t<td align = \"center\">" << (i + 1) << "</td><td align = \"center\">" << subx[i] << "</td><td align = \"center\">"
             << suby[i] << "</td><td align = \"center\">" << subxy[i] << "</td><td align = \"center\">" << subxx[i] << "</td><td align = \"center\">" << subyy[i] << "</td>\n\t\t\t\t</tr>" ;
        hout << endl;
    }
    hout << "\t\t\t\t<tr>\n\t\t\t\t\t<td align = \"center\">Total</td><td align = \"center\">" << totalx << "</td><td align = \"center\">" << totaly << "</td><td align = \"center\">" << totalxy
         << "</td><td align = \"center\">" << totalxx << "</td><td align = \"center\">" << totalyy << "</td>\n\t\t\t\t</tr>\n\t\t\t</table>";
    hout << "\t\t<p align = \"center\"><font size = \"5\">----------- Linear Regression Line -----------</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">a  = (" << size << " * " << totalxy << " - " << totalx << " * " << totaly << ") / </font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">     (" << size << " * " << totalxx << " - " << totalx << " * " << totalx << ")</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">   = " << gradient << "</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">b  = (" << totaly << " * " << totalxx << " - " << totalx << " * " << totalxy << ") / </font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">     (" << size << " * " << totalxx << " - " << totalx << " * " << totalx << ")</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">   = " << y_intercept << "</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">y' = " << gradient << "x + " << y_intercept << "</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">------------- Pearson Correlation ------------</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">Pearson's Numerator   = " << nume << "</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">Pearson's Denominator   = " << deno << "</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">Pearson's Coefficient   = " << answer << "</font></p>\n";
// close body
    fout << "\t</body>\n";
    fout << "</html>\n";
    hout.close();
    return;
}

void FreqHistoTxtHtml (int subject[], int size, int choose)
{
    string str [10];        // to store *
    for (int i = 0; i < size; i++)
    {
        if(subject[i] >= 0 && subject[i] < 10)
            str[0] += "*";
        else if (subject[i] >= 10 && subject[i] < 20)
            str[1] += "*";
        else if (subject[i] >= 20 && subject[i] < 30)
            str[2] += "*";
        else if (subject[i] >= 30 && subject[i] < 40)
            str[3] += "*";
        else if (subject[i] >= 40 && subject[i] < 50)
            str[4] += "*";
        else if (subject[i] >= 50 && subject[i] < 60)
            str[5] += "*";
        else if (subject[i] >= 60 && subject[i] < 70)
            str[6] += "*";
        else if (subject[i] >= 70 && subject[i] < 80)
            str[7] += "*";
        else if (subject[i] >= 80 && subject[i] < 90)
            str[8] += "*";
        else if (subject[i] >= 90 && subject[i] <= 100)
            str[9] += "*";
    }
// TXT file
    ofstream fout;
    fout.open("FrequencyHistogramResult.txt", ios::out);
    fout << "---------- Frequency ----------" << endl << endl;
    fout << "       Subject : ";
    if(choose == 1)
        fout << "Maths" << endl << endl;
    else if(choose == 2)
        fout << "Science" << endl << endl;
    else if(choose == 3)
        fout << "Malay" << endl << endl;
    fout << "=============================== " << endl;
    fout << "|    Marks Frequency Dist.    | " << endl;
    fout << "=============================== " << endl << endl;
    fout << "      ===================       " << endl;
    fout << "      |  Marks  | Freq. |       " << endl;
    fout << "      |---------|-------|       " << endl;
    vector<bool> visit(size, false);
    for(int i = 0; i < size; i++)
    {
        if(visit[i] == true)
            continue;
        int count = 1;
        for(int j = i + 1; j < size; j++)
        {
            if(subject[i] == subject[j])
            {
                visit[j] = true;
                count++;
            }
        }
        fout << "      |    " << subject[i] << "\t|   " << count << "\t|" << endl;
    }
    fout << "      ===================" << endl << endl;
    fout << "=============================== " << endl;
    fout << "|          Histogram          | " << endl;
    fout << "=============================== " << endl << endl;
    fout << "   * represents 1 frequency     " << endl;
    fout << "         of the marks           " << endl << endl;
    fout << "   ==================================================== " << endl;
    fout << "       Marks\t|         Marks Frequency Dist.           " << endl;
    fout << "   -------------|-------------------------------------- " << endl;
    int i, j = 0;
    for (i = 0; j < 10; i += 10, j++)
    {
        string sti = to_string(i);
        if(i == 90)
            fout << "      " << i << " - " << i + 10 << "\t| " << str[j] << endl;
        else
		    fout << "      " << i << " - <" << i + 10 << "\t| " << str[j] << endl;
    }
    fout << "   ==================================================== " << endl << endl;
    fout.close();
// HTML browser
    ofstream hout;
    hout.open("FrequencyHistogramResult.html", ios::out);
    hout << "<!DOCTYPE html>\n";
    hout << "<html>\n";
    hout << "\t<head>\n";
    hout << "\t\t<title>Results Report</title>\n";
    hout << "\t</head>\n";
// open body
    hout << "\t<body>\n";
    hout << "\t\t<h1 align = \"center\"><font size = \"5\">----------- Frequency & Histogram Results -----------</font></h1>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">      Marks Frequency Dist.    </font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">Subject : ";
    if(choose == 1)
        hout << "Maths</font></p>\n" << endl;
    else if(choose == 2)
        hout << "Science</font></p>\n" << endl;
    else if(choose == 3)
        hout << "Malay</font></p>\n" << endl;
    hout << "\t\t\t<table border = \"1\" align = \"center\" width = \"400\" cellpadding = \"5\" cellspacing = \"5\">\n";
    hout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Marks </th><th align = \"center\">  Frequency </th>\n";
    for(int i = 0; i < size; i++)
    {
        if(visit[i] == true)
            continue;
        int count = 1;
        for(int j = i + 1; j < size; j++)
        {
            if(subject[i] == subject[j])
            {
                visit[j] = true;
                count++;
            }
        }
        hout << "\t\t\t\t<tr>\n\t\t\t\t\t<td align = \"center\">" << subject[i] << "</td><td align = \"center\">"
                << count << "</td>\n\t\t\t\t</tr>\n";
    }
    hout << "\t\t\t</table>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">            Histogram          </font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t\t<table border = \"1\" align = \"center\" width = \"400\" cellpadding = \"5\" cellspacing = \"5\">\n";
    hout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Marks </th><th align = \"center\">  Marks Frequency Dist. </th>\n\t\t\t\t</tr>\n";
    for (int i , j = 0; j < 10; i += 10, j++)
    {
        string sti = to_string(i);
        if(i == 90)
            hout << "\t\t\t\t<tr>\n\t\t\t\t\t<td align = \"center\">" << i << " - "
                 << i + 10 << "</td><td>" << str[j] << "</td>\n\t\t\t\t</tr>\n";
        else
            hout << "\t\t\t\t<tr>\n\t\t\t\t\t<td align = \"center\">" << i << " - <"
                 << i + 10 << "</td><td>" << str[j] << "</td>\n\t\t\t\t</tr>\n";
    }
    hout << "\t\t\t</table>\n";
// close body
    hout << "\t</body>\n";
    hout << "</html>\n";
    hout.close();
    return;
}

void AboveBelowAvgTxtHtml(int array[], int choose, int p, int size, bool st)
{
// TXT file
    ofstream fout;
    fout.open("AboveBelowAverageResult.txt", ios::out);
    fout << "------------ Results ------------" << endl << endl;
    fout << "=================================" << endl;
    fout << "  Above & Below Average: ";
    if (choose == 1)
        fout << "Maths" << endl;
    else if (choose == 2)
        fout << "Science" << endl;
    else if (choose == 3)
        fout << "Malay" << endl;
    fout << "=================================" << endl << endl;
    fout << "      The average is: " << p << endl << endl;
    do
    {
        fout << "---------- Above Average ---------- " << endl << endl;
        fout << "         ================           " << endl;
        fout << "         |     Marks    |           " << endl;
        fout << "         ================           " << endl;
        for (int i = 0; i < SIZE; i++)
        {
            if(array[i] >= p)
                fout << "         |      " << array[i] << "\t|" << endl;
        }
        fout << "         ================           " << endl << endl;
        fout << "---------- Below Average ---------- " << endl << endl;
        fout << "         ================           " << endl;
        fout << "         |     Marks    |           " << endl;
        fout << "         ================           " << endl;
        for (int i = 0; i < SIZE; i++)
        {
            if(array[i] <= p)
                fout << "         |      " << array[i] << "\t|" << endl;
        }
        fout << "         ================           " << endl << endl;
        st = true;
    } while (!st);
    fout.close();
// HTML browser
    ofstream hout;
    hout.open("AboveBelowAverageResult.html", ios::out);
    hout << "<!DOCTYPE html>\n";
    hout << "<html>\n";
    hout << "\t<head>\n";
    hout << "\t\t<title>Results Report</title>\n";
    hout << "\t</head>\n";
// open body
    hout << "\t<body>\n";
    hout << "\t\t<h1 align = \"center\"><font size = \"5\">----------- Above and Below Average -----------</font></h1>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">      Above & Below Average: ";
    if (choose == 1)
        hout << "Maths</font></p>\n";
    else if (choose == 2)
        hout << "Science</font></p>\n";
    else if (choose == 3)
        hout << "Malay</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">      The average is: " << p << "</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">---------- Above Average ----------</font></p>\n";
    hout << "\t\t\t<table border = \"1\" align = \"center\" width = \"150\" cellpadding = \"5\" cellspacing = \"5\">\n";
    hout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Marks </th>\n";
    for (int i = 0; i < SIZE; i++)
        {
            if(array[i] >= p)
                hout << "\t\t\t\t<tr>\n\t\t\t\t\t<td align = \"center\">" << array[i] << "</td>\n\t\t\t\t</tr>\n";
        }
    hout << "\t\t\t</table>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">---------- Below Average ----------</font></p>\n";
    hout << "\t\t\t<table border = \"1\" align = \"center\" width = \"150\" cellpadding = \"5\" cellspacing = \"5\">\n";
    hout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Marks </th>\n";
    for (int i = 0; i < SIZE; i++)
        {
            if(array[i] <= p)
                hout << "\t\t\t\t<tr>\n\t\t\t\t\t<td align = \"center\">" << array[i] << "</td>\n\t\t\t\t</tr>\n";
        }
    hout << "\t\t\t</table>\n";
// close body
    hout << "\t</body>\n";
    hout << "</html>\n";
    hout.close();
    return;
}

void sortAscTxtHtml (vector<long> a, vector<int> b, vector<int> c, vector<int> d, vector<int> e, int f, int size, int cols)
{
    int array[size][cols];
    ofstream fout;
    fout.open("SortAscending.txt", ios::out);
    fout << "-------------- Sorting Results --------------" << endl << endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(j == 0)
                array[i][j] = a[i];
            else if(j == 1)
                array[i][j] = b[i];
            else if(j == 2)
                array[i][j] = c[i];
            else if(j == 3)
                array[i][j] = d[i];
            else if(j == 4)
                array[i][j] = e[i];
        }
    }
    if (f == 1)
        goto displaySort1;
    else if(f == 2)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 4] > array[i][cols - 4])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if(f == 3)
    {
       for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 3] > array[i][cols - 3])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if (f == 4)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 2] > array[i][cols - 2])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if (f == 5)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 1] > array[i][cols - 1])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    displaySort1:
    fout << "=============================================" << endl;
    fout << "|          Sorting Data Ascending           |" << endl;
    fout << "=============================================" << endl << endl;
    fout << "---------------------------------------------" << endl;
    fout << "Student ID" << "\t" << "Age" << "\t" << "Maths" << "\t" << "Science" << "\t" << "Malay" << endl;
    fout << "---------------------------------------------" << endl;
    for(int i = 0; i < size; i++)           // display data after sorting (Asc)
    {
        for(int j = 0; j < 5; j++)
            fout << array[i][j] << "\t";
        fout << endl;
    }
    fout << "---------------------------------------------" << endl << endl;
    fout.close();
// HTML browser
    ofstream hout;
    hout.open("SortAscending.html", ios::out);
    hout << "<!DOCTYPE html>\n";
    hout << "<html>\n";
    hout << "\t<head>\n";
    hout << "\t\t<title>Results Report</title>\n";
    hout << "\t</head>\n";
// open body
    hout << "\t<body>\n";
    hout << "\t\t<h1 align = \"center\"><font size = \"5\">----------- Sort Ascending Result -----------</font></h1>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">    Sorting Data Ascending     </font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t\t<table border = \"1\" align = \"center\" width = \"150\" cellpadding = \"5\" cellspacing = \"5\">\n";
    hout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Student ID </th><th align = \"center\"> Age </th>";
    hout << "<th align = \"center\"> Maths </th><th align = \"center\"> Science </th><th align = \"center\"> Malay </th>\n";
    for(int i = 0; i < size; i++)
    {
        hout << "\t\t\t\t<tr>";
        for(int j = 0; j < 5; j++)
            hout << "\n\t\t\t\t\t<td align = \"center\">" << array[i][j] << "</td>\n";
        hout << "\t\t\t\t</tr>\n";
    }
    hout << "\t\t\t</table>\n";
// close body
    hout << "\t</body>\n";
    hout << "</html>\n";
    hout.close();
    return;
}

void sortDescTxtHtml (vector<long> a, vector<int> b, vector<int> c, vector<int> d, vector<int> e, int f, int size, int cols)
{
    int array[size][cols];
// TXT file
    ofstream fout;
    fout.open("SortDescending.txt", ios::out);
    fout << "-------------- Sorting Results --------------" << endl << endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(j == 0)
                array[i][j] = a[i];
            else if(j == 1)
                array[i][j] = b[i];
            else if(j == 2)
                array[i][j] = c[i];
            else if(j == 3)
                array[i][j] = d[i];
            else if(j == 4)
                array[i][j] = e[i];
        }
    }
    cout << endl;
    if (f == 1)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols] < array[i][cols])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if(f == 2)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 4] < array[i][cols - 4])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if(f == 3)
    {
       for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 3] < array[i][cols - 3])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if (f == 4)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 2] < array[i][cols - 2])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if (f == 5)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 1] < array[i][cols - 1])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    displaySort2:
    fout << "=============================================" << endl;
    fout << "|          Sorting Data Ascending           |" << endl;
    fout << "=============================================" << endl << endl;
    fout << "---------------------------------------------" << endl;
    fout << "Student ID" << "\t" << "Age" << "\t" << "Maths" << "\t" << "Science" << "\t" << "Malay" << endl;
    fout << "---------------------------------------------" << endl;
    for(int i = 0; i < size; i++)           // display data after sorting (Asc)
    {
        for(int j = 0; j < 5; j++)
            fout << array[i][j] << "\t";
        fout << endl;
    }
    fout << "---------------------------------------------" << endl << endl;
    fout.close();
// HTML browser
    ofstream hout;
    hout.open("SortDescending.html", ios::out);
    hout << "<!DOCTYPE html>\n";
    hout << "<html>\n";
    hout << "\t<head>\n";
    hout << "\t\t<title>Results Report</title>\n";
    hout << "\t</head>\n";
// open body
    hout << "\t<body>\n";
    hout << "\t\t<h1 align = \"center\"><font size = \"5\">----------- Sort Descending Result -----------</font></h1>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">    Sorting Data Descending     </font></p>\n";
    hout << "\t\t<p align = \"center\"><font size = \"5\">===============================</font></p>\n";
    hout << "\t\t\t<table border = \"1\" align = \"center\" width = \"150\" cellpadding = \"5\" cellspacing = \"5\">\n";
    hout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Student ID </th><th align = \"center\"> Age </th>";
    hout << "<th align = \"center\"> Maths </th><th align = \"center\"> Science </th><th align = \"center\"> Malay </th>\n";
    for(int i = 0; i < size; i++)
    {
        hout << "\t\t\t\t<tr>";
        for(int j = 0; j < 5; j++)
            hout << "\n\t\t\t\t\t<td align = \"center\">" << array[i][j] << "</td>\n";
        hout << "\t\t\t\t</tr>\n";
    }
    hout << "\t\t\t</table>\n";
// close body
    hout << "\t</body>\n";
    hout << "</html>\n";
    hout.close();
    return;
}

bool load(vector<long>& id, vector<int>& age, vector<int>& sub1, vector<int>& sub2, vector<int>& sub3, int size, bool check)
{
    string stuID, stuAge, maths, science, malay;
    string file ;
    clearScreen();
    cout << endl;
    cout << "--------- Next Screen ---------" << endl << endl;
    cout << "===============================" << endl;
    cout << "|          Load Data          |" << endl;
    cout << "===============================" << endl << endl;
    cout << " Enter data file name (a.csv): " << endl;
    cin >> file;
    cin.clear();
    cin.ignore(80, '\n');
    openfile:
    ifstream infile(file);  // open the file
    if (infile.is_open())   // if the file is open
    {
        string cols;                            // to ignore the first line
        getline(infile, cols);
        string lineOfText;                      // to ignore the second line
        getline(infile, lineOfText);
        string rows;                            // to ignore the third line
        getline(infile, rows);
        while (!infile.eof())
        {
            getline(infile, stuID, ',');
            id.push_back(stol(stuID));
            getline(infile, stuAge, ',');
            age.push_back(stoi(stuAge));
            getline(infile, maths, ',');
            sub1.push_back(stoi(maths));
            getline(infile, science,',');
            sub2.push_back(stoi(science));
            getline(infile, malay, '\n');
            sub3.push_back(stoi(malay));
        }
        clearScreen();
        cout << endl;
        cout << "--------- Next Screen ---------" << endl << endl;
        cout << "===============================" << endl;
        cout << "|          Load Data          |" << endl;
        cout << "===============================" << endl << endl;
        cout << "        Load successful!       " << endl;
    }
    else
        {
            clearScreen();
            cout << endl;
            cout << "--------------- ERROR ---------------" << endl << endl;
            cout << "=====================================" << endl;
            cout << "|             Load Data             |" << endl;
            cout << "=====================================" << endl << endl;
            cout << "      Error in opening the file      " << endl;
            cout << "Enter data file name again: ";
            cin >> file;
            cin.clear();
            cin.ignore(80, '\n');
            goto openfile;
        }
    infile.close();
    check = true;
    return check;
}

void sortAsc (vector<long> a, vector<int> b, vector<int> c, vector<int> d, vector<int> e, int f, int size, int cols)
{
    int array[size][cols];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(j == 0)
                array[i][j] = a[i];
            else if(j == 1)
                array[i][j] = b[i];
            else if(j == 2)
                array[i][j] = c[i];
            else if(j == 3)
                array[i][j] = d[i];
            else if(j == 4)
                array[i][j] = e[i];
        }
    }
    cout << endl;
    if (f == 1)
        goto displaySort;
    else if(f == 2)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 4] > array[i][cols - 4])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if(f == 3)
    {
       for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 3] > array[i][cols - 3])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if (f == 4)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 2] > array[i][cols - 2])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if (f == 5)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 1] > array[i][cols - 1])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    displaySort:
    clearScreen();
    cout << "---------------- Next Screen ----------------" << endl << endl;
    cout << "=============================================" << endl;
    cout << "|          Sorting Data Ascending           |" << endl;
    cout << "=============================================" << endl << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Student ID" << "\t" << "Age" << "\t" << "Maths" << "\t" << "Science" << "\t" << "Malay" << endl;
    cout << "---------------------------------------------" << endl;

    for(int i = 0; i < size; i++)           // display data after sorting (Asc)
    {
        for(int j = 0; j < 5; j++)
            cout << array[i][j] << "\t";
        cout << endl;
    }
    cout << "---------------------------------------------" << endl << endl;
    cout << "           Press ENTER to continue ";
    return;
}

void sortDesc (vector<long> a, vector<int> b, vector<int> c, vector<int> d, vector<int> e, int f, int size, int cols)
{
    int array[size][cols];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(j == 0)
                array[i][j] = a[i];
            else if(j == 1)
                array[i][j] = b[i];
            else if(j == 2)
                array[i][j] = c[i];
            else if(j == 3)
                array[i][j] = d[i];
            else if(j == 4)
                array[i][j] = e[i];
        }
    }
    cout << endl;
    if (f == 1)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols] < array[i][cols])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if(f == 2)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 4] < array[i][cols - 4])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if(f == 3)
    {
       for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 3] < array[i][cols - 3])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if (f == 4)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 2] < array[i][cols - 2])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    else if (f == 5)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[j][cols - 1] < array[i][cols - 1])
                {
                    for(int k = 0; k <= cols - 1; k++)
                    {
                        int temp = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
            }
        }
    }
    clearScreen();
    cout << "---------------- Next Screen ----------------" << endl << endl;
    cout << "=============================================" << endl;
    cout << "|          Sorting Data Descending          |" << endl;
    cout << "=============================================" << endl << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Student ID" << "\t" << "Age" << "\t" << "Maths" << "\t" << "Science" << "\t" << "Malay" << endl;
    cout << "---------------------------------------------" << endl;
    for(int i = 0; i < size; i++)           // display data after sorting (Asc)
    {
        for(int j = 0; j < 5; j++)
            cout << array[i][j] << "\t";
        cout << endl;
    }
    cout << "---------------------------------------------" << endl;
    cout << "           Press ENTER to continue ";
    return;
}

int minMarks(int marks[], int size)
{
    int Min = marks[0];

    for(int i = 1; i < size; i++)
    {
        if (marks[i] < Min)
            Min = marks[i];
    }
    return Min;
}

int maxMarks(int marks[], int size)
{
    int Max = marks[0];

    for(int i = 1; i < size; i++)
    {
        if (marks[i] > Max)
            Max = marks[i];
    }
    return Max;
}

double meanValue(int array[], int size)
{
    double sum = 0;

    for (int count = 0; count < size; count++)
        sum = sum + array[count];

    double avg = sum/size;

    return avg;
}

int medianValue(int a[],int size)
{
    int temp;

    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if( a[i] > a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    if (size % 2 == 0)
        return ( a[size / 2] + a[size / 2 - 1] ) / 2;        // if size is even
    else
        return a[size / 2];                                 // if size is odd
}

double STD(int array[], int size)
{
    double sum = 0.0, mean, variance = 0.0, stdDeviation;

    for (int count = 0; count < size; count++)
        sum = sum + array[count];

    mean = sum / size;

    for(int count = 0; count < size; count++)
        variance += pow(array[count] - mean, 2);

    variance = variance / (size - 1);
    stdDeviation = sqrt(variance);

    return stdDeviation;
}

double var(int array[], int size)
{
    double sum = 0.0, mean, variance = 0.0;
    for (int count = 0; count < size; count++)
        sum = sum + array[count];
    mean = sum / size;
    for(int count = 0; count < size; count++)
        variance += pow(array[count] - mean, 2);
    variance = variance / (size - 1);
    return variance;
}

void aboveBelowAvg (int array[], int choose, int p, int size, bool st)
{
    cout << "------------ Next Screen ------------" << endl << endl;
    cout << "  =================================" << endl;
    cout << "    Above & Below Average: ";
    if (choose == 1)
        cout << "Maths" << endl;
    else if (choose == 2)
        cout << "Science" << endl;
    else if (choose == 3)
        cout << "Malay" << endl;
    cout << "  =================================" << endl << endl;
    p = meanValue(array, size);
    cout << "      The average is: " << p << endl << endl;
    do{
        cout << "---------- Above Average ---------- " << endl << endl;
        cout << "         ================           " << endl;
        cout << "         |     Marks    |           " << endl;
        cout << "         ================           " << endl;
        for (int i = 0; i < SIZE; i++)
        {
            if(array[i] >= p)
                cout << "         |      " << array[i] << "\t|" << endl;
        }
        cout << "         ================           " << endl << endl;
        cout << "---------- Below Average ---------- " << endl << endl;
        cout << "         ================           " << endl;
        cout << "         |     Marks    |           " << endl;
        cout << "         ================           " << endl;
        for (int i = 0; i < SIZE; i++)
        {
            if(array[i] <= p)
                cout << "         |      " << array[i] << "\t|" << endl;
        }
        cout << "         ================           " << endl << endl;
        st = true;
    } while (!st);
}

void frequency (int subject[], int size)
{
    vector<bool> visit(size, false);
    cout << endl;
    cout << " ===============================" << endl;
    cout << " |    Marks Frequency Dist.    |" << endl;
    cout << " ===============================" << endl << endl;
    cout << "      ===================" << endl;
    cout << "      |  Marks  | Freq. |" << endl;
    cout << "      |---------|-------|" << endl;
    for(int i = 0; i < size; i++)
    {
        if(visit[i] == true)
            continue;
        int count = 1;
        for(int j = i + 1; j < size; j++)
        {
            if(subject[i] == subject[j])
            {
                visit[j] = true;
                count++;
            }
        }
        cout << "      |    " << subject[i] << "\t|   " << count << "\t|" << endl;
    }
    cout << "      ===================" << endl;
    return;
}

void histogram (int subject [], int size)
{
    string str [10];        // to store *
    for (int i = 0; i < size; i++)
    {
        if(subject[i] >= 0 && subject[i] < 10)
            str[0] += "*";
        else if (subject[i] >= 10 && subject[i] < 20)
            str[1] += "*";
        else if (subject[i] >= 20 && subject[i] < 30)
            str[2] += "*";
        else if (subject[i] >= 30 && subject[i] < 40)
            str[3] += "*";
        else if (subject[i] >= 40 && subject[i] < 50)
            str[4] += "*";
        else if (subject[i] >= 50 && subject[i] < 60)
            str[5] += "*";
        else if (subject[i] >= 60 && subject[i] < 70)
            str[6] += "*";
        else if (subject[i] >= 70 && subject[i] < 80)
            str[7] += "*";
        else if (subject[i] >= 80 && subject[i] < 90)
            str[8] += "*";
        else if (subject[i] >= 90 && subject[i] <= 100)
            str[9] += "*";
    }
    printHist(str);
    return;
}

void printHist (string* str)
{
    int i, j = 0;
    cout << endl;
    cout << "         ==========================" << endl;
    cout << "         |        Histogram       |" << endl;
    cout << "         ==========================" << endl << endl;
    cout << "\t* represents 1 frequency of the \n\t\t marks\n\n";
    cout << "   ==================================================== " << endl;
    cout << "       Marks\t|         Marks Frequency Dist.       " << endl;
    cout << "   -------------|-------------------------------------- " << endl;
	for (i = 0; j < 10; i += 10, j++)
    {
        string sti = to_string(i);
        if(i == 90)
            cout << "      " << i << " - " << i + 10 << "\t| " << str[j] << endl;
        else
		    cout << "      " << i << " - <" << i + 10 << "\t| " << str[j] << endl;
    }
    cout << "   ==================================================== " << endl << endl;
    return;
}

double slope (const int subject1[], const int subject2[], int size)
{
    double totalx = 0.0, totaly = 0.0, totalxy = 0.0, totalxx = 0.0;
    double a;
    for (int i = 0; i < size; i++)
    {
        totalx += subject1[i];
        totaly += subject2[i];
        totalxy += (subject1[i] * subject2[i]);
        totalxx += (subject1[i] * subject1[i]);
    }
    a = (size * totalxy - totalx * totaly) / (size * totalxx - totalx * totalx);
    cout << "   a  = (" << size << " * " << totalxy << " - " << totalx << " * " << totaly << ") / " << endl;
    cout << "        (" << size << " * " << totalxx << " - " << totalx << " * " << totalx << ")" << endl;
    return a;
}

double intercept (const int subject1[], const int subject2[], int size)
{
    double totalx = 0.0, totaly = 0.0, totalxy = 0.0, totalxx = 0.0;
    double b;
    for (int i = 0; i < size; i++)
    {
        totalx += subject1[i];
        totaly += subject2[i];
        totalxy += (subject1[i] * subject2[i]);
        totalxx += (subject1[i] * subject1[i]);
    }
    b = (totaly * totalxx - totalx * totalxy) / (size * totalxx - totalx * totalx);
    cout << "   b  = (" << totaly << " * " << totalxx << " - " << totalx << " * " << totalxy << ") / " << endl;
    cout << "        (" << size << " * " << totalxx << " - " << totalx << " * " << totalx << ")" << endl;
    return b;
}

void LinearPearsonTable (const int subject1[], const int subject2[], int size, string subjectx, string subjecty)
{
    int subx[size], suby[size], subxy[size], subxx[size], subyy[size];
    int totalx = 0, totaly = 0, totalxy = 0, totalxx = 0, totalyy = 0;
    cout << "----------------- Next Screen -----------------" << endl << endl;
    cout << "               " << subjectx << "              " << endl;
    cout << "               " << subjecty << "              " << endl << endl;
    cout << "===============================================" << endl;
    cout << "|             SubjextX VS SubjectY            |" << endl;
    cout << "===============================================" << endl << endl;
    cout << "No.\t" << "X\t" << "Y\t" << "XY\t" << "X2\t" << "Y2\t" << endl;
    for (int i = 0; i < size; i++)
    {
        subx[i] = subject1[i];
        suby[i] = subject2[i];
    }
    for (int i = 0; i < size; i++)
    {
        subxy[i] = subx[i] * suby[i];
        subxx[i] = subx[i] * subx[i];
        subyy[i] = suby[i] * suby[i];
        cout << (i + 1) << "\t" << subx[i] << "\t" << suby[i] << "\t"
             << subxy[i] << "\t" << subxx[i] << "\t" << subyy[i] << endl;
        totalx += subx[i];
        totaly += suby[i];
        totalxy += subxy[i];
        totalxx += subxx[i];
        totalyy += subyy[i];
    }
    cout << "----------------------------------------------" << endl;
    cout << "Total:\t" << totalx << "\t" << totaly << "\t"
         << totalxy << "\t" << totalxx << "\t" << totalyy << endl;
    cout << "----------------------------------------------" << endl << endl;
    return;
 }

int pearsonNumerator (const int course1[], const int course2[], int size)
{
    int SumX = 0;
    int SumY = 0;
    int SumXY = 0;
    int total = 0;
    int result;
    for (int count = 0; count < size; count++)
    {
        SumX = SumX + course1[count];
        SumY = SumY + course2[count];
        SumXY = SumXY + (course1[count]*course2[count]);
    }
    total = size*SumXY;
    result = total - (SumX*SumY);
    cout << "   Pearson's Numerator = " << size << "*" << SumXY << " - " << SumX << "*" << SumY << endl;
    return result;
}

double pearsonDenominator (const int course1[], const int course2[], int size)
{
    int SumX = 0, SumX2 = 0, SumY = 0, SumY2 = 0;
    double rootResult;
    for (int count = 0; count < size; count++)
    {
        SumX = SumX + course1[count];
        SumX2 = SumX2 + (course1[count] * course1[count]);
        SumY = SumY + course2[count];
        SumY2 = SumY2 + (course2[count]*course2[count]);
    }
    int multiX2 = SumX2*size;
    int multiY2 = SumY2*size;
    int result = (multiX2 - (SumX*SumX))*(multiY2 - (SumY*SumY));
    if(result < 0)
        result = abs(result);
    cout << "   Pearson's Denominator = " << "sqrt((" << size << "*" << SumX2 << " - " << SumX << "*" << SumX << ")" << endl
         << "\t\t\t   *(" << size << "*" << SumY2 << " - " << SumY << "*" << SumY << "))" << endl;
    rootResult = sqrt(result);
    return rootResult;
}

void makeTXT (string file, int choose, int p, int q, double r, int s, double t, double u)
{
    ofstream fout;
    fout.open(file.c_str(), ios::out);
    if (choose == 1)
        fout << "---------- MATHEMATICS ----------" << endl << endl;
    else if (choose == 2)
        fout << "------------ SCIENCE ------------" << endl << endl;
    else if (choose == 3)
        fout << "------------- MALAY -------------" << endl << endl;
    fout << "=================================" << endl;
    fout << "|    Min Marks  |   Max Marks   |" << endl;
    fout << "=================================" << endl;
    fout << "|" << setw(7) << p << setw(8) << "\t|" << setw(7) << q << "\t|" << endl;
    fout << "=================================" << endl << endl;
    fout << "        ================" << endl;
    fout << "        |      Mean    |" << endl;
    fout << "        ================" << endl;
    fout << "        |     " << r << setw(5) << "|" << endl;
    fout << "        ================" << endl << endl;
    fout << "        ================" << endl;
    fout << "        |    Median    |" << endl;
    fout << "        ================" << endl;
    fout << "        |     " << s << setw(5) << "|" << endl;
    fout << "        ================" << endl << endl;
    fout << "        ================" << endl;
    fout << "        |    Variance  |" << endl;
    fout << "        ================" << endl;
    fout << "        |    " << t << setw(4) << "|" << endl;
    fout << "        ================" << endl << endl;
    fout << "        ================" << endl;
    fout << "        |      STD     |" << endl;
    fout << "        ================" << endl;
    fout << "        |    " << u << setw(4) << "|" << endl;
    fout << "        ================" << endl << endl;
    fout.close();
}

void makeHTML (string file2, string subName, int choose, int p, int q, double r, int s, double t, double u)
{
    ofstream fout;
    fout.open(file2.c_str());
    fout << "<!DOCTYPE html>\n";
    fout << "<html>\n";
    fout << "\t<head>\n";
    fout << "\t\t<title>Results Report</title>\n";
    fout << "\t</head>\n";
// open body
    fout << "\t<body>\n";
    fout << "\t\t<h1 align = \"center\"><font size = \"5\">";
    if (choose == 1) fout << "---------- MATHEMATICS ---------- </font></h1>\n";
    else if (choose == 2) fout << "------------ SCIENCE ------------ </font></h1>\n";
    else if (choose == 3) fout << "------------- MALAY ------------- </font></h1>\n";
    // min & max
    fout << "\t\t\t<table border = \"1\" align = \"center\" width = \"400\" cellpadding = \"5\" cellspacing = \"5\">\n";
    fout << "\t\t\t<caption align = \"center\"> Min & Max Marks </caption>\n";
    fout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Subject </th><th align = \"center\"> Min Marks </th><th align = \"center\"> Max Marks </th>\n\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
    fout << "\t\t\t\t\t<td align = \"center\">" << subName << "</td><td align = \"center\">" << p << "</td><td align = \"center\">" << q << "</td>\n";
    fout << "\t\t\t\t</tr>\n";
    fout << "\t\t\t</table>\n";
    // mean
    fout << "\t\t\t<table border = \"1\" align = \"center\" width = \"200\" cellpadding = \"5\" cellspacing = \"5\">\n";
    fout << "\t\t\t<caption align = \"center\"> Mean Marks </caption>\n";
    fout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Subject </th><th align = \"center\"> Mean </th>\n\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
    fout << "\t\t\t\t\t<td align = \"center\">" << subName << "</td><td align = \"center\">" << r << "</td>\n";
    // median
    fout << "\t\t\t<table border = \"1\" align = \"center\" width = \"200\" cellpadding = \"5\" cellspacing = \"5\">\n";
    fout << "\t\t\t<caption align = \"center\"> Median Marks </caption>\n";
    fout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Subject </th><th align = \"center\"> Median </th>\n\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
    fout << "\t\t\t\t\t<td align = \"center\">" << subName << "</td><td align = \"center\">" << s << "</td>\n";
    // variance
    fout << "\t\t\t<table border = \"1\" align = \"center\" width = \"200\" cellpadding = \"5\" cellspacing = \"5\">\n";
    fout << "\t\t\t<caption align = \"center\"> Variance </caption>\n";
    fout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Subject </th><th align = \"center\"> Variance </th>\n\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
    fout << "\t\t\t\t\t<td align = \"center\">" << subName << "</td><td align = \"center\">" << t << "</td>\n";
    // Standard Deviation
    fout << "\t\t\t<table border = \"1\" align = \"center\" width = \"200\" cellpadding = \"5\" cellspacing = \"5\">\n";
    fout << "\t\t\t<caption align = \"center\"> Standard Deviation </caption>\n";
    fout << "\t\t\t\t<tr>\n\t\t\t\t\t<th align = \"center\"> Subject </th><th align = \"center\"> STD </th>\n\t\t\t\t</tr>\n\t\t\t\t<tr>\n";
    fout << "\t\t\t\t\t<td align = \"center\">" << subName << "</td><td align = \"center\">" << u << "</td>\n";
// close body
    fout << "\t</body>\n";
    fout << "</html>\n";
    fout.close();
}

void displayHomepage ()
{
    cout << endl;
    cout << "===================================================" << endl;
    cout << "|  Welcome to the Student Academic Report System  |" << endl;
    cout << "===================================================" << endl << endl;
    cout << "           Press ENTER to continue!              " << endl << endl;
    return;
}

int mainmenu ()
{
    int mainchoice;
    cout << endl;
    cout << "---------- Next Screen ----------" << endl << endl;
    cout << "=================================" << endl;
    cout << "|           Main Menu           |" << endl;
    cout << "=================================" << endl << endl;
    cout << " 1. Load & Sort Data From a File " << endl;
    cout << " 2. Computation By Subjects      " << endl;
    cout << " 3. Compare By Subjects          " << endl;
    cout << " 4. Overall Statistical Report   " << endl;
    cout << " 0. Exit Program                 " << endl << endl;
    cout << "---------------------------------" << endl << endl;
    cout << "   Please enter your choice: ";
    cin >> mainchoice;
    return mainchoice;
}

void displaySubjects1 ()
{
    cout << endl;
    cout << "--------- Next Screen ---------" << endl << endl;
    cout << "===============================" << endl;
    cout << "|  Computational by Subjects  |" << endl;
    cout << "===============================" << endl << endl;
    cout << "There are 3 available subjects:" << endl;
    cout << "       1. Maths                " << endl;
    cout << "       2. Science              " << endl;
    cout << "       3. Malay                " << endl;
    cout << "       0. Back to main menu    " << endl << endl;
    cout << "-------------------------------" << endl << endl;
    return;
}

void displaySubjects2()
{
    cout << endl;
    cout << "--------- Next Screen ---------" << endl << endl;
    cout << "===============================" << endl;
    cout << "|     Compare by Subjects     |" << endl;
    cout << "===============================" << endl << endl;
    cout << "There are 3 available subjects:" << endl;
    cout << "       1. Maths                " << endl;
    cout << "       2. Science              " << endl;
    cout << "       3. Malay                " << endl;
    cout << "       0. Go back              " << endl << endl;
    cout << "-------------------------------" << endl << endl;
    return;
}

void displaySubjects3()
{
    cout << endl;
    cout << "--------- Next Screen ---------" << endl << endl;
    cout << "===============================" << endl;
    cout << "|  Overall Statistical Report  |" << endl;
    cout << "===============================" << endl << endl;
    cout << "There are 3 available subjects:" << endl;
    cout << "       1. Maths                " << endl;
    cout << "       2. Science              " << endl;
    cout << "       3. Malay                " << endl;
    cout << "       0. Back to main menu    " << endl << endl;
    cout << "-------------------------------" << endl << endl;
    return;
}

void displayTasks ()
{
    cout << "---------- Next Screen ----------" << endl << endl;
    cout << "=================================" << endl;
    cout << "              Tasks              " << endl;
    cout << "=================================" << endl << endl;
    cout << "1. Minimum & Maximum Marks       " << endl;
    cout << "2. Mean                          " << endl;
    cout << "3. Median                        " << endl;
    cout << "4. Variance                      " << endl;
    cout << "5. Standard Deviation            " << endl;
    cout << "6. Frequency Dist. & Histogram   " << endl;
    cout << "7. Above & Below Average         " << endl;
    cout << "0. Back to Computation by Subject" << endl << endl;
    cout << "---------------------------------" << endl << endl;
    cout << "Please enter your choice: ";
}

void end ()
{
    clearScreen();
    cout << endl;
    cout << "--------- Final Screen ---------" << endl << endl;
    cout << "================================" << endl;
    cout << "|         Exit Program         |" << endl;
    cout << "================================" << endl << endl;
    cout << "      The program has ended!    " << endl;
    cout << "       Thank you so much!       " << endl << endl;
    cout << "--------------------------------" << endl << endl;
    return;
}

void clearScreen()
{
    system("cls||clear");
    return;
}
