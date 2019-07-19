## A Basic Introduction About C++

``` c++
#include <iostream>
#include <cmath>

using namespace std;

/* ---------Data Types--------- */
int datatypes(){

    char grade = 'A';
    int age = 50;
    double gpa = 2.3;
    bool isMale = false;
    string phrase = "Giraffe";

    return 0;
}

/* -----------Strings----------- */
int working_with_strings(){

    string phrase = "Giraffe Academy"; // index start from 0
    phrase[0] = 'A';
    cout << phrase.length() << endl;
    cout << phrase[1];
    cout << phrase.find("Academy", 0);
    cout << phrase.substr(8, 3);
    string phrasesub;
    phrasesub = phrase.substr(8, 3);
    cout << phrasesub;

    return 0;
}

/* -----------Numbers----------- */
int working_with_numbers(){

    cout << 40;
    cout << 5 - 7;

    int wnum = 5;
    double dnum = 8.8;

    wnum++;  // wnum = wnum + 1;

    wnum += 80;

    cout << 10 / 3;  // return integer 3;
    cout << 10.0 / 3.0;  // return float 3.33333;

    // #include <cmath>
    cout << pow(3, 2);
    cout << sqrt(36);
    cout << round(5.3);
    cout << floor(5.6);
    cout << ceil(5.3);
    cout << fmax(3, 10);

    return 0;
}

/* ------------Input------------ */
int getting_user_input(){

    int age;  // get int
    char grade;  // get char

    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your grade: ";
    cin >> grade;

    cout << "You are " << age << "years old" << "grade" << grade;

    string name; // get string
    getline(cin, name);

    cout << "Your name" << name;

    return 0;
}

/* ----------Practice1---------- */
int building_a_calculator(){

    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << num1 + num2;

    return 0;
}

/* ----------Practice2---------- */
int building_a_mad_libs_game(){

    string color, pluralNoun, celebrity;

    cout << "Enter a color: ";
    getline(cin, color);
    cout << "Enter a plural Noun: ";
    getline(cin, pluralNoun);
    cout << "Enter a celebrity: ";
    getline(cin, celebrity);

    cout << color << "lala";
    cout << pluralNoun << "nana";
    cout << celebrity << "I love";

    return 0;
}

/* ------------Arrays------------ */
int arrays(){

    int luckyNums[] = {4, 8, 15, 16, 23, 42};  // index start from 0;

    cout << luckyNums[0];

    luckyNums[0] = 19;
    cout << luckyNums[0];

    int luckyNumswithSize[20] = {4, 8, 15, 16, 23, 42};
    luckyNumswithSize[10] = 100;
    cout << luckyNumswithSize[10];

    return 0;
}

/* -----------Functions---------- */
// If we want to execute the function, we should 'calling it' in main function.
// function with parameters.
void functions_above(string name, int age){
    cout << "Hello " << name << "you are" << age;
}

/* ------------Return------------ */
// return type: int, char, double,
double return_statement(double num){
    //cube
    double result = num * num * num;

    return result;  // get a double type value back;
}

/* ------------If_Else------------ */
int if_statements(bool isMale, bool isTall){

    if(isMale){
        cout << "You are a male";
    }
    else{
        cout << "You are not male";
    }

    // and &&; or ||; not !
    if(isMale && isTall){
        cout << "You are male and tall";
    }
    else if(isMale && !isTall){
        cout << "You are a short male";
    }
    else if(!isMale && isTall){
        cout << "You are note male and tall";
    }
    else{
        cout << "You are note male and short";
    }

    return 0;
}

int more_if_statement(int num1, int num2, int num3){
    // getmax
    int result;

    if(num1 >= num2 && num1 >= num3){
        result = num1;
    }
    /* ------------------------- */
    if(num1 > num2){
        result = num1;
    }
    else if(num1 == num2){  // != not equal;
        result = num1;
    }
    else{
        result = num2;
    }

    return result;
}

/* ------------Switch------------ */
string switch_statement(int dayNum){
    // get day of week
    string dayName;

    switch (dayNum) {
        case 0:
            dayName = "Sunday";
            break;

        case 1:
            dayName = "Monday";
            break;

        case 2:
            dayName = "Tuesday";
            break;

        case 3:
            dayName = "Wednesday";
            break;

        case 4:
            dayName = "Thursday";
            break;

        case 5:
            dayName = "Friday";
            break;

        case 6:
            dayName = "Saturday";
            break;

        default:
            dayName = "Invalid Day Number";
    }

    return dayName;
}

/* ----------While_Loop---------- */
int while_loops(){

    int index = 1;
    while (index <= 5){
        cout << index << endl;
        index++;
    }

    do{
        cout << index << endl;
        index++;
    }while (index <= 5);

    return 0;
}

/* ----------Practice3---------- */
int building_a_guessing_game(){

    int secretNum = 7;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    bool outOfGuesses = false;

    while (secretNum != guess && !outOfGuesses){
        if (guessCount < guessLimit){
            cout << "Enter guess: ";
            cin >> guess;
            guessCount++;
        }
        else{
            outOfGuesses = true;
        }
    }

    if (outOfGuesses){
        cout << "You Lose!";
    }
    else{
        cout << "You Win!";
    }

    return 0;
}

/* -----------For_Loop----------- */
int for_loops(){

    int nums[] = {1, 2, 5, 7, 3};
    for (int num : nums){  // use use range based for loop instead
        cout << num << endl;
    }

    for (int i = 1; i <= 5; i++){
        cout << i << endl;
    }

    return 0;
}

/* ----------Practice4---------- */
int exponent_function(int baseNum, int powNum){

    int result = 1;
    for (int i = 0; i < powNum; i++) {
        result *= baseNum;  // result = result * baseNum;
    }

    return result;
}

/* ----------Nested_Loop---------- */
int twod_array_nested_loops(){  // nested loop: a loop inside a loop;

    int numberGrid[3][2] = {
            {1, 2},
            {3, 4},
            {5, 6}
    };

    cout << numberGrid[0][1];

    for (int i = 0; i < 3; i++){
        // nested loop
        for (int j = 0; j < 2; j++){
            cout << numberGrid[i][j];
        }
    }

    return 0;
}

/* -----------Comments----------- */
int comments(){

    // here is a comment, only works on a single line;

    /*
     here
     is
     another
     comment
     works on multi lines
     */

    return 0;
}

/* -----------Pointers----------- */
int pointers(){

    int age = 19;
    double gpa = 2.7;
    string name = "Mike";

    // RAM, Memory
    cout << &age;  // memory address(pointer) of variable age;

    int* pAge = &age;
    double* pGpa = &gpa;
    string* pString = &name;

    cout << pAge;
    cout << *pAge;

    return 0;
}

/* -------Classes & Objects------- */
// To represent any objects in real world, we need to create a class(a new data type).
class Book{
public:
    string title;
    string author;
    int pages;

    // Constructor Functions 1 
    Book(string aTitle, string aAuthor, int aPages){
        title = move(aTitle);
        author = move(aAuthor);
        pages = aPages;
    }
    
    // Constructor Functions 2
    Book(){
        title = "no title";
        author = "no author";
        pages = 0;
    }
};


class Student{
public:
    string name;
    string major;
    double gpa;

    Student(string aName, string aMajor, double aGpa){
        name = move(aName);
        major = move(aMajor);
        gpa = aGpa;
    }
    
    // Function
    bool hasHonors(){
        if (gpa >= 3.5){
            return true;
        }
        else{
            return false;
        }
    }
};

/* -------Setter & Getter------- */
class Movie{
private:
    string rating;

public:
    string title;
    string director;

    Movie(string aTitle, string aDirector, string aRating){
        title = move(aTitle);
        director = move(aDirector);
        setRating(move(aRating));
    }
    // Setter 
    void setRating(string aRating){
        if (aRating == "G" || aRating == "PG" || aRating == "PG-13" || aRating == "R"){
            rating = move(aRating);
        }
        else{
            rating = "NR";
        }
    }
    // Getter
    string getRating(){
        return rating;
    }
};

/* ---------Inheritance--------- */
class Chef{
public:
    void makeChicken(){
        cout << "The chef makes chicken" << endl;
    }
    void makeSalad(){
        cout << "The chef makes salad" << endl;
    }
    void makeSpecialDish(){
        cout << "The chef makes bbq ribs" << endl;
    }
};

class ItalianChef : public Chef{
public:
    void makePasta(){
        cout << "The chef makes bbq pasta" << endl;
    }
    void makeSpecialDish(){
        cout << "The chef makes chicken parm" << endl;
    }
};


// declaration for the functions defined below the main function.
void functions_below(const string &name, int age);

int main()
{
    // there is no need a declaration when we define the function above the main function.
    // but if we define the function below the main funcion, we then need a declaration statement:
   
    functions_above("Mike", 60);  // This tells c++ that I want to execute all of the codes that inside this function;
    functions_below("Tom", 45);
    functions_below("Jim", 13);

    // Classes and Objects
    Book book1;  // create an instance
    cout << book1.pages;

    Book book2;  // create an instance
    book1.title = "Lord of the Ring";
    book1.author = "Tolkein";
    book1.pages = 700;
    cout << book2.pages;

    Book book3("Harry Potter", "JK Rowling", 500);
    cout << book3.pages;

    // Object Functions
    Student student1("Jim", "Business", 2.4);
    Student student2("Pam", "Art", 3.6);
    cout << student1.hasHonors();
    cout << student2.hasHonors();

    // Getter & Setters
    Movie avengers("The Avenagers", "Joss Whedon", "PG-13");
    avengers.setRating("R");
    cout << avengers.getRating();

    // Inheritance
    Chef chef;
    chef.makeChicken();

    ItalianChef italianChef;
    italianChef.makeChicken();

    chef.makeSpecialDish();
    italianChef.makeSpecialDish();

    return 0;
}

/* ----------Declaration---------- */
void functions_below(const string &name, int age){
    cout << "Hello " << name << "you are" << age;
}
```
