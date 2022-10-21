#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct person {
    string name;
    string sex;
    int age = 0;
    string number;
    string place;
};
void sort(struct person ml[], int* pTotal) {
    int num = *pTotal;
    while (num > 1) {
        for (int i = 0; i < num - 1; i++) {
            if (ml[i].age < ml[i + 1].age) {
                person temp = ml[i];
                ml[i] = ml[i + 1];
                ml[i + 1] = temp;
            }
        }
        num--;
    }
}
void addPerson(struct person ml[], int *pTotal) {
    string nname, nsex, nnumber, nplace;
    int nage;
    cout << "Please input his/her name:  ";
    cin >> nname;
    ml[*pTotal].name = nname;
    cout << "Please input his/her sex  ";
    cin >> nsex;
    ml[*pTotal].sex = nsex;
    cout << "Please input his/her number  ";
    cin >> nnumber;
    ml[*pTotal].number = nnumber;
    cout << "Please input his/her place  ";
    cin >> nplace;
    ml[*pTotal].place = nplace;
    cout << "Please input his/her age  ";
    cin >> nage;
    ml[*pTotal].age = nage;
    *pTotal = *pTotal + 1;
    cout << "Add person successfully\n\n\n";
}
void showPerson(struct person ml[], int* pTotal) {
    if (*pTotal == 0) cout << "No Persons\n\n\n";
    else {
        for (int i = 0; i < *pTotal; i++) {
            cout << "name:  " << ml[i].name << "\nsex:  " << ml[i].sex << "\nage:  " << ml[i].age << "\nnumber:  " << ml[i].number << "\nplace:  " << ml[i].place << "\n\n";
        }
    }
}
void delPerson(struct person ml[], int *pTotal) {
    if (*pTotal == 0) cout << "No Persons\n\n\n";
    else {
        string delname;
        cout << "Which person will you delete?";
        cin >> delname;
        bool flag = true;
        for (int i = 0; i < *pTotal; i++) {
            if (ml[i].name == delname) {
                ml[i].name = "";
                ml[i].number = "";
                ml[i].sex = "";
                ml[i].place = "";
                ml[i].age = 0;
                sort(ml, pTotal);
                *pTotal = *pTotal - 1;
                cout << "The person was deleted successfully\n\n\n";
                flag = false;
            }
        }
        if (flag)
            cout << "The person can't be found\n\n\n";
        flag = true;
    }
}
void findPerson(struct person ml[], int* pTotal) {
    if (*pTotal == 0) cout << "No Persons\n\n\n";
    else {
        string findname;
        cout << "Which person will you find?";
        cin >> findname;
        bool flag = true;
        for (int i = 0; i < *pTotal; i++) {
            if (ml[i].name == findname) {
                cout << "name: " << ml[i].name << "\nnumber:" << ml[i].number << "\nsex : " << ml[i].sex << "\nplace : " << ml[i].place << "\nage : " << ml[i].age << "\n\n\n";
                flag = false;
            }
        }
        if (flag)
            cout << "The person can't be found\n\n\n";
        flag = true;
    }
}
void changePerson(struct person ml[], int* pTotal) {
    if (*pTotal == 0) cout << "No Persons\n\n\n";
    else {
        string changename;
        cout << "Which person will you change?";
        cin >> changename;
        for (int i = 0; i < *pTotal; i++) {
            if (ml[i].name == changename) {
                string newname, newsex, newnumber, newplace;
                int newage;
                cout << "The person was found successfully, please input the new name  ";
                cin >> newname;
                ml[i].name = newname;
                cout << "Please input the new sex  ";
                cin >> newsex;
                ml[i].sex = newsex;
                cout << "Please input the new number  ";
                cin >> newnumber;
                ml[i].number = newnumber;
                cout << "Please input the new place  ";
                cin >> newplace;
                ml[i].place = newplace;
                cout << "Please input the new age  ";
                cin >> newage;
                ml[i].age = newage;
            }
            else {
                cout << "The person can't be found\n\n\n";
            }
        }
    } 
}
void clearallPerson(struct person ml[], int *pTotal) {
    cout << "This action is dangerous.Are you sure? Y or N\n";
    string whetherclear;
    cin >> whetherclear;
    if (whetherclear == "Y") {
        for (int i = 0; i < 1000; i++) {
            ml[i].name = "";
            ml[i].number = "";
            ml[i].sex = "";
            ml[i].place = "";
            ml[i].age = 0;
        }
        *pTotal = 0;
        cout << "Clear all person successfully\n\n";
    }
    else
        cout << "Exit clear all person \n\n";
}
int main() {
    int total = 2;
    int* pTotal = &total;
    bool flag = true;
    int mind = 0;
    person mailList[1000];
    mailList[0] = {"lanson", "男", 18, "18960", "FJ"};
    mailList[1] = { "yl", "女", 17, "15005", "FJ" };
    while (flag) {
        cout << "Please input your desire\n\n";
        cout << "add Person : 1\n";
        cout << "show Person : 2\n";
        cout << "delete Person : 3\n";
        cout << "find Person : 4\n";
        cout << "change Person : 5\n";
        cout << "clear all Person : 6\n";
        cout << "exit : 7\n\n\n";
        cin >> mind;
        switch (mind) {
            case 1:
                cout << "\n\n";
                addPerson(mailList, pTotal);
                break;
            case 2:
                cout << "\n\n";
                showPerson(mailList, pTotal);
                break;
            case 3:
                cout << "\n\n";
                delPerson(mailList, pTotal);
                break;
            case 4:
                cout << "\n\n";
                findPerson(mailList, pTotal);
                break;
            case 5:
                cout << "\n\n";
                changePerson(mailList, pTotal);
                break;
            case 6:
                cout << "\n\n";
                clearallPerson(mailList, pTotal);
                break;
            case 7:
                cout << "\n\nexit\n";
                flag = false;
                system("cls");
                cout << "Exit the mail list successfully\n\n\n";
                break;
            default:
                cout << "Wrong Number! Please input right number\n\n\n";
        }
    }
}