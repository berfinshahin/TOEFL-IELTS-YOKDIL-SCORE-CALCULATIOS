#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class exam 
{
    protected:
        string name;
        int total_score;
        int day, month, year;
    
    public:
        exam(string n, int s, int d, int m, int y)
            : name(n), total_score(s), day(d), month(m), year(y) {}
            virtual void display() = 0;
};

class TOEFL: 
public exam 
{
    private:
    int reading_score;
    int listening_score;
    int speaking_score;
    int writing_score;
    
    public:
        TOEFL(string n, int s, int d, int m, int y, int r, int l, int sp, int w)
            : exam(n, s, d, m, y), reading_score(r), listening_score(l), speaking_score(sp), writing_score(w) {}
            virtual void display() 
            {
                cout<<"Name: "<<name<<endl;
                cout<<"Exam: TOEFL"<<endl;
                cout<<"Date of exam: "<<day<<"/"<<month<<"/"<<year<<endl;
                cout<<"Reading: "<<reading_score<<endl;
                cout<<"Listening: "<<listening_score<<endl;
                cout<<"Speaking: "<<speaking_score<<endl;
                cout<<"Writing: "<<writing_score<<endl;
                cout<<"Total score: "<<reading_score+listening_score+speaking_score+writing_score<<endl;
            }
};

class IELTS : 
public exam 
{
    int listening_score;
    int reading_score;
    int writing_score;
    int speaking_score;
    double total_band_score;
    
    public:
        IELTS(string n, int s, int d, int m, int y, int l, int r, int w, int sp)
            : exam(n, s, d, m, y), listening_score(l), reading_score(r), writing_score(w), speaking_score(sp) 
            {
                double ls = getBandScore(listening_score);
                double rs = getBandScore(reading_score);
                double ws = getBandScore(writing_score);
                double ss = getBandScore(speaking_score);
                total_band_score = round(((ls + rs + ws + ss) / 4.0) * 2.0) / 2.0;
            }
    
    double getBandScore(int score) 
    {
        double band_score = 0.0;
        switch(score)
        {
            case 40:
                band_score = 9.0;
                break;
            case 39:
                band_score = 8.5;
                break;
            case 38:
                band_score = 8.0;
                break;
            case 37: case 36:
                band_score = 7.5;
                break;
            case 35: case 34:
                band_score = 7.0;
                break;
            case 33: case 32:
                band_score = 6.5;
                break;
            case 31: case 30:
                band_score = 6.0;
                break;
            case 29: case 28: case 27: case 26:
                band_score = 5.5;
                break;
            case 25: case 24: case 23:
                band_score = 5.0;
                break;
            case 22: case 21: case 20: case 19:
                band_score = 4.5;
                break;
            case 18: case 17: case 16: case 15:
                band_score = 4.0;
                break;
            case 14: case 13: case 12:
                band_score = 3.5;
                break;
            case 11: case 10: case 9: case 8:
                band_score = 3.0;
                break;
            case 7: case 6: case 5:
                band_score = 2.5;
                break;
            case 4: case 3: case 2:
                band_score=2.0;
                break;
            case 1:
                band_score=1.0;
                break;                                          
        }
        
        return band_score;
    }
    
    virtual void display() 
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Exam: IELTS"<<endl;  
        cout<<"Date of exam: "<<day<<"/"<<month<<"/"<<year<<endl;
        cout<<"Reading: "<<getBandScore(reading_score)<<endl;
        cout<<"Listening: "<<getBandScore(listening_score)<<endl;
        cout<<"Speaking: "<<getBandScore(speaking_score)<<endl;
        cout<<"Writing: "<<getBandScore(writing_score)<<endl;
        cout<<"Total score: "<<total_band_score<<endl;
    }
};

class YokDil : 
public exam 
{
    int num_correct;
    double total_score;
    
    public:
    YokDil(string n, int s, int d, int m, int y, int c)
        : exam(n, s, d, m, y), num_correct(c) 
        {
            total_score = num_correct * 1.25;
        }
    
    virtual void display() 
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Exam: YokDil"<<endl;
        cout<<"Date of exam: "<<day<<"/"<<month<<"/"<<year<<endl;
        cout<<"Total score: "<<total_score<<endl;
    }
};

int main() 
{
    exam* Exam;
    string name;
    int day,month,year;
    char type;

    cout<<"Enter name of student: ";
    
    getline(cin, name);

    cout<<"Enter date of exam: ";
    cin>>day>>month>>year;

    cout<<"Enter T or t for TOEFL, I or i for IELTS, Y or y for YokDil: ";
    cin>>type;

    if (type == 'T' || type == 't') 
    {
        int reading,listening,speaking,writing;
        cout<<"Enter score for Reading: ";
        cin>>reading;
        cout<<"Enter score for Listening: ";
        cin>>listening;
        cout<<"Enter score for Speaking: ";
        cin>>speaking;
        cout<<"Enter score for Writing: ";
        cin>>writing;

    Exam = new TOEFL(name, reading + listening + speaking + writing, day, month, year, reading, listening, speaking, writing);

    } 
    
    else if (type == 'I' || type == 'i')
    {
        int reading, listening, speaking, writing;
        cout<<"Enter score for Reading: ";
        cin>>reading;
        cout<<"Enter score for Listening: ";
        cin>>listening;
        cout<<"Enter score for Speaking: ";
        cin>>speaking;
        cout<<"Enter score for Writing: ";
        cin>>writing;

    Exam = new IELTS(name, reading + listening + speaking + writing, day, month, year, listening, reading, writing, speaking);

    } 
    
    else if (type == 'Y' || type == 'y') 
    {
        int correct_answers;
        cout<<"Enter number of correct answers: ";
        cin>>correct_answers;

    Exam = new YokDil(name, correct_answers * 1.25, day, month, year, correct_answers);

    } 
    
    else 
    {
        cout<<"Invalid exam type!"<<endl;
        return 0;
    }
    
    Exam->display();
    
    delete Exam;

    return 0;
}

