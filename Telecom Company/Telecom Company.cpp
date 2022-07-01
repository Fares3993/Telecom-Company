#include <iostream>  
#include <string>  
using namespace std;
// storage date of the subscribtion  
struct date {
    int day = 1, month = 1, year = 2020;
};
// line data storage  
struct lines {
    int package_type;
    string line_num;
    float balance = 10;
    date start_date, renewal_date;
}line[3];
// client data storage  
struct client_data {
    long long ID;
    string e_mail, name, address, password;
}new_client, existing_client;
//declaration of function used  
void check_number(string& check);
void Existing_client(client_data& data);
void renew_subscribtion(int& sub_num);
void transfer_balance(int& trans);
void using_fun(int& operate_num);
void choose_package(int& change_package);
void get_data(client_data& cldata);
void get_lindata(lines& ldata);
void line1_number(int& x);
void line2_number(int& x);
void line3_number(int& x);
void charge_balance(lines& charge);
//global variables  
int numchange, num_choose, i;
string test1, test2, check_num;
//start main  
int main()
{
    int operation_num;//is an input in usin_fun  
    //to Ask the user if he is a new  or existing client  
    cout << "Enter the number of your chosen\n";
    cout << "1- New client\n" << "2- Existing client\n";
    int select, x;//the number chosen by the client  
    cin >> select;
    //if the user choose new client  
    if (select == 1) {
        //this loop used to add a line (three lines at moat)  
        for (i = 0; i < 3; i++) {
            if (i == 0) {//this if condition to ask the client to enter his data once ( dont ask him about his data when adding a line)  
                get_data(new_client);
            }
            //this function to choose the number of the new line and ask the user if he wants to change package type and if he wants to do any operation   
            get_lindata(line[i]);
            /*this loop to ask the user if he wants to continue doing operation like
            (1- phone call,2- send massag,3- transfer balance,4- charge balance,5- subscription renewa) or exit*/
            while (true) {
                cout << "press 1 to continue \n";
                cout << "press 2 to exit \n";
                cin >> operation_num;
                if (operation_num == 1)
                    using_fun(operation_num);
                else if (operation_num == 2)
                    break;
            }

            cout << "press 1 to add line\n";
            cout << "press 2 to exit\n";
            cin >> x;
            //these two if conditions to ask the user if he wants to add a line or exit  
            if (x == 1)
                continue;
            if (x == 2)
                break;
        }
    }
    //if the user choose existing client  
    else if (select == 2) {
        // Existing client data  
        existing_client.address = "AAAAAAAAA";
        existing_client.e_mail = "BBBBBBBBB";
        existing_client.ID = 20002443944;
        existing_client.name = "ABCD";
        existing_client.password = "AA123BB@#";
        line[0].line_num = "01323004577";
        check_num = line[0].line_num;
        // to storage the phone number and the password and compare them with user entry  
        test1 = line[0].line_num;
        test2 = existing_client.password;
        //this function to enter the phone number and the password of the existig client and compare them with user entry  
        Existing_client(existing_client);
        //this loop used to add a line (three lines at moat)  
        for (i = 0; i < 3; i++) {
            //this if condition to ask the client to choose phone number whin adding a line  
            if (i > 0) {
                get_lindata(line[i]);
            }
            /*this loop to ask the user if he wants to continue doing operation like
            (1- phone call,2- send massag,3- transfer balance,4- charge balance,5- subscription renewa) or exit*/
            while (true) {
                cout << "press 1 to continue \n";
                cout << "press 2 to exit \n";
                cin >> operation_num;
                if (operation_num == 1)
                    using_fun(operation_num);
                else if (operation_num == 2)
                    break;
            }
            cout << "press 1 to add line\n";
            cout << "press 2 to exit\n";
            cin >> x;
            //these two if conditions to ask the user if he wants to add a line or exit  
            if (x == 1)
                continue;
            if (x == 2)
                break;
        }


    }

    return 0;
}//end main  

//this function to check the phone number that the user had entered to change his package  
void check_number(string& check) {
    cout << "Enter your phone number\n";
    cin >> line[i].line_num;
    if (line[i].line_num == check_num) {
        choose_package(numchange);
    }
    else {
        cout << "the number that you had entered is incorrect please try again\n";
        check_number(check_num);
    }
}

//this function to enter the phone number and the password of the existig client and compare them with user entry  
void Existing_client(client_data& data) {
    cout << "Enter your phone number\n";
    cin >> line[0].line_num;
    cout << "Enter the password\n";
    cin >> existing_client.password;
    if (line[0].line_num == test1 && existing_client.password == test2) {
        cout << "sign in successful\n";
        cout << "your name is " << existing_client.name << "\n";
    }
    else {
        cout << "the phone number or the password are incorrect!! try again\n";
        Existing_client(existing_client);
    }
}

/*this function to ask the user if he wants to renew the subscribtion or change his package, and do them and
tell him the start and renewal date*/
void renew_subscribtion(int& sub_num) {
    if (sub_num == 5) {
        int num;
        cout << "press 1 to renew your subscription \n";
        cout << "press 2 to change your package \n";
        cin >> num;
        if (num == 1) {
            int selection_num, num1 = 5;
            cout << "your balance is" << line[i].balance << "\n";
            cout << "select your exiting package \n" << "1- package 10\n" << "2- package 20\n" << "3- package 50\n" << "4- package 100\n";
            cin >> selection_num;
            /*these if and else if conditions to know if the client have enough balance to renew his subscribtion or not
             and allow the user to recharege his balance*/
            if (selection_num == 1 && line[i].balance >= 10) {
                cout << "your subscription renewed successfully\n";
                cout << "start date is " << line[i].start_date.day << "/" << line[i].start_date.month + 1 << "/" << line[i].start_date.year << "\n";
                cout << "renewal date is " << line[i].renewal_date.day << "/" << line[i].renewal_date.month + 2 << "/" << line[i].renewal_date.year << "\n";
            }
            else if (selection_num == 2 && line[i].balance >= 20) {
                cout << "your subscription renewed successfully\n";
                cout << "start date is " << line[i].start_date.day << "/" << line[i].start_date.month + 1 << "/" << line[i].start_date.year << "\n";
                cout << "renewal date is " << line[i].renewal_date.day << "/" << line[i].renewal_date.month + 2 << "/" << line[i].renewal_date.year << "\n";
            }
            else if (selection_num == 3 && line[i].balance >= 50) {
                cout << "your subscription renewed successfully\n";
                cout << "start date is " << line[i].start_date.day << "/" << line[i].start_date.month + 1 << "/" << line[i].start_date.year << "\n";
                cout << "renewal date is " << line[i].renewal_date.day << "/" << line[i].renewal_date.month + 2 << "/" << line[i].renewal_date.year << "\n";
            }
            else if (selection_num == 4 && line[i].balance >= 100) {
                cout << "start date is " << line[i].start_date.day << "/" << line[i].start_date.month + 1 << "/" << line[i].start_date.year << "\n";
                cout << "renewal date is " << line[i].renewal_date.day << "/" << line[i].renewal_date.month + 2 << "/" << line[i].renewal_date.year << "\n";
                cout << "your subscription renewed successfully\n";
            }
            else {
                cout << "your balance is not enough\n";
                cout << "if you want to recharge press 1\n";
                cout << "if you want to try again press 2\n";
                cin >> selection_num;
                if (selection_num == 1) {
                    charge_balance(line[i]);
                    renew_subscribtion(num1);
                }
                else if (selection_num == 2) {

                    renew_subscribtion(num1);
                }

            }
        }
        else if (num == 2) {
            check_number(check_num);
        }
    }
}

//this function to tansfer balance and if the client dont have enough balance he can recharge it  
void transfer_balance(int& trans)
{
    if (trans == 3) {
        string phone_num;
        int trans_balance;
        cout << "Enter the phone number that consists of 11 number\n";
        cin >> phone_num;
        cout << "Enter the balance that you want to transfer\n";
        cin >> trans_balance;
        if (trans_balance > line[i].balance)
        {
            int select_num;
            cout << "your balance is not enough\n";
            cout << "if you want to recharge press 1\n";
            cout << "if you want to try again press 2\n";
            cin >> select_num;
            if (select_num == 1)
                charge_balance(line[i]);
            else if (select_num == 2) {
            }
            int num2 = 3;
            transfer_balance(num2);
        }
        else if (trans_balance <= line[i].balance) {
            line[i].balance -= trans_balance;
            cout << trans_balance << " L.E has been deducted from your balance\n" << "your existing balance is " << line[i].balance << "\n";
        }
    }


}

/*this function to ask the user if he wants to do any operation like
(1 - phone call, 2 - send massag, 3 - transfer balance, 4 - charge balance, 5 - subscription renewa) or exit*/
void using_fun(int& operate_num) {
    cout << "Enter the number of your chosen\n";
    cout << "1- phone call\n";
    cout << "2- send massage\n";
    cout << "3- transfer balance \n";
    cout << "4- charge balance\n";
    cout << "5- subscription renewal\n";
    cin >> operate_num;
    int phone_num1;
    if (operate_num == 1) {

        cout << "Enter the phone number that consists of 11 number\n";
        cin >> phone_num1;
        line[i].balance -= 0.25;
        cout << "0.25 L.E has been deducted from your balance\n" << "your existing balance is " << line[i].balance << "\n";

    }
    else if (operate_num == 2) {
        string text;
        cout << "Enter the phone number that consists of 11 number\n";
        cin >> phone_num1;
        cout << "Enter the massage \n";
        cin >> text;
        line[i].balance -= 0.25;
        cout << "0.25 L.E has been deducted from your balance\n" << "your existing balance is " << line[i].balance << "\n";
    }
    else if (operate_num == 4) {
        charge_balance(line[i]);
    }
    transfer_balance(operate_num);
    renew_subscribtion(operate_num);

}

//this function to ask the user about the package type that he need and recharge his balance if it is not enough  
void choose_package(int& change_package) {
    int num_type, numchoose;
    bool c = false;
    cout << "choose your package type\n";
    cout << "1- package 10\n" << "2- package 20\n" << "3- package 50\n" << "4- package 100\n";
    cin >> num_type;
    if (num_type == 1 && line[i].balance >= 10) {
        line[i].package_type = 10;
        cout << "you are in package " << line[i].package_type << "\n";
        c = true;
    }
    else if (num_type == 2 && line[i].balance >= 20) {
        line[i].package_type = 20;
        cout << "you are in package " << line[i].package_type << "\n";
        c = true;
    }
    else if (num_type == 3 && line[i].balance >= 50) {
        line[i].package_type = 50;
        cout << "you are in package " << line[i].package_type << "\n";
        c = true;
    }
    else if (num_type == 4 && line[i].balance >= 100) {
        line[i].package_type = 100;
        cout << "you are in package " << line[i].package_type << "\n";
        c = true;
    }
    else {
        cout << "your balance is not enough\n";
        cout << "if you want to recharge press 1\n";
        cout << "if you want to try again press 2\n";
        cin >> numchoose;
        if (numchoose == 1) {
            charge_balance(line[i]);
            choose_package(numchange);
        }
        else if (numchoose == 2)
        {
            choose_package(numchange);
        }
    }
    if (c == true) {
        cout << "start date is " << line[i].start_date.day << "/" << line[i].start_date.month << "/" << line[i].start_date.year << "\n";
        cout << "renewal date is " << line[i].renewal_date.day << "/" << line[i].renewal_date.month + 1 << "/" << line[i].renewal_date.year << "\n";
    }
}

//this function allow the client to choose the phone number of his first line   
void line1_number(int& x) {
    cout << "choose your phone number\n";
    cout << "1 - '01354456787'\n" << "2 - '01343537896'\n" << "3 - '01386564273'\n" << "4 - '01374152533'\n" << "5 - '01322376411'\n";
    cin >> x;
    if (x == 1) {
        line[i].line_num = "01354456787";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 2) {
        line[i].line_num = "01343537896";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 3) {
        line[i].line_num = "01386564273";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 4) {
        line[i].line_num = "01374152533";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 5) {
        line[i].line_num = "01322376411";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else cout << "try again\n";

}

//this function allow the client to choose the phone number of his second line   
void line2_number(int& x) {
    cout << "choose your phone number\n";
    cout << "1 - '01367482532'\n" << "2 - '01356584794'\n" << "3 - '01396633475'\n" << "4 - '01328469173'\n" << "5 - '01322948871'\n";
    cin >> x;
    if (x == 1) {
        line[i].line_num = "01367482532";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 2) {
        line[i].line_num = "01356584794";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 3) {
        line[i].line_num = "01396633475";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 4) {
        line[i].line_num = "01328469173";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 5) {
        line[i].line_num = "01322948871";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else cout << "try again\n";

}

//this function allow the client to choose the phone number of his third line   
void line3_number(int& x) {
    cout << "choose your phone number\n";
    cout << "1 - '01344183867'\n" << "2 - '01392723846'\n" << "3 - '01340540835'\n" << "4 - '01367049821'\n" << "5 - '01390895610'\n";
    cin >> x;
    if (x == 1) {
        line[i].line_num = "01344183867";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 2) {
        line[i].line_num = "01392723846";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 3) {
        line[i].line_num = "01340540835";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 4) {
        line[i].line_num = "01367049821";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else if (x == 5) {
        line[i].line_num = "01390895610";
        cout << "your number is " << line[i].line_num << "\n";
        check_num = line[i].line_num;
    }
    else cout << "try again\n";

}

//this function allow the client to choose the phone number  
void get_lindata(lines& ldata)
{
    int num3;
    if (i == 0) {//to choose the number of the first line  
        line1_number(num_choose);
    }
    else if (i == 1) {//to choose the number of the second line  
        line2_number(num_choose);
    }
    else if (i == 2) {//to choose the number of the third line  
        line3_number(num_choose);
    }
    cout << "Welcome to our company\n";
    cout << "you are in normal package\n";
    cout << "if you want to change your package press 1\n";
    cout << "press 2 to continue \n";
    cin >> num3;
    if (num3 == 1)
    {
        cout << "your balance is " << line[i].balance << "\n ";
        choose_package(numchange);
    }
    else if (num3 == 2) {
        using_fun(num3);
    }
}

//this function to storage client data  
void get_data(client_data& cldata)
{
    cout << "Enter your name\n";
    cin >> cldata.name;
    cout << "Enter your ID number\n";
    cin >> cldata.ID;
    cout << "Enter your address\n";
    cin >> cldata.address;
    cout << "Enter your password\n";
    cin >> cldata.password;
    cout << "Enter your e-mail\n";
    cin >> cldata.e_mail;
}

//this function to charge the balance  
void charge_balance(lines& charge) {
    int numcard;
    cout << "1- to charge 5 L.E Enter the number of card that consists of 5 numbers\n";
    cout << "2- to charge 10 L.E Enter the number of card that consists of 6 numbers\n";
    cout << "3- to charge 20 L.E Enter the number of card that consists of 7 numbers\n";
    cout << "4- to charge 50 L.E Enter the number of card that consists of 8 numbers\n";
    cout << "5- to charge 100 L.E Enter the number of card that consists of 9 numbers\n";
    cin >> numcard;
    if (numcard >= 10000 && numcard <= 99999) {
        line[i].balance += 5;
        cout << "your balance becomes " << line[i].balance << "\n ";
    }
    else if (numcard >= 100000 && numcard <= 999999) {
        line[i].balance += 10;
        cout << "your balance becomes " << line[i].balance << "\n ";
    }
    else if (numcard >= 1000000 && numcard <= 9999999) {
        line[i].balance += 20;
        cout << "your balance becomes " << line[i].balance << "\n ";
    }
    else if (numcard >= 10000000 && numcard <= 99999999) {
        line[i].balance += 50;
        cout << "your balance becomes " << line[i].balance << "\n ";
    }
    else if (numcard >= 100000000 && numcard <= 999999999) {
        line[i].balance += 100;
        cout << "your balance becomes " << line[i].balance << "\n ";
    }
    else {
        cout << "that number is incorrect please try again\n";
        charge_balance(line[i]);
    }
}
