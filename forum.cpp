#include "forum.h"

forum::forum(const char* name) 
{
    int i;
    forum_title = new char[strlen(name)+1];
    strcpy(forum_title,name);
    cout << "Forum with title: "<<  forum_title << " has just been created!"<< endl;
}

forum::~forum() 
{
    int i, j;
    cout << "Forum with title: "<<  get_title() << " is about to be destroyed!"<< endl;
    for(i = 0;i < SIZE; i++)
    {
        cout << "Thread with title: "<<  get_thread(i) << " is about to be destroyed!"<< endl;
        for(j = 0;j < SIZE; j++)
            cout << "Post with id: "<<  get_post_id(i,j) << " is about to be destroyed!"<< endl;
    }
    delete[] forum_title;
}

void date::set(int i, int j, int k)
{
    month = i;
    day = j;
    year = k;
}

void date::get(int& i, int& j, int& k)
{
    i = month;
    j = day ;
    k = year;
}

void forum::set_forum()
{
    int i;
    //Array with thread titles
    string temp1[] = {"Κανόνες και χρήσιμες πληροϕορίες", "Help", "My first thread", "Nonsense", "Blablabla"};
    //Array with thread creators
    string temp2[] = {"creator 1","creator 2","creator 3","creator 4","creator 5"};
    for(i = 0; i < SIZE; i++ )
    {
        //cout << " " << temp2[i] << " " << temp1[i] << endl;
        set_thread(temp2[i], temp1[i], i);
        cout << "Thread with title: "<<  get_thread(i) << " has just been created!"<< endl;  
    }  
}

char* forum::get_title()
{
    return forum_title;
}

void forum::set_thread(const string name,const string title, int i)
{
    thread();
    threads[i].set_thread(name, title, i);    
}

thread:: thread()
{
    //do nothing
    return;
}

void thread::set_thread(const string name,const string title, int j)
{
   int i;
   char temp[100];
   //Array with post titles
   string temp1[][SIZE] = { {"Κανόνας 1", "Κανόνας 2", "Κανόνας 3", "Κανόνας 4"},
                        {"Help me 1","Help me 2","Help me 3","Help me 4"},
                        {"Blablablaaaaa 1","Blablablaaaaa 2","Blablablaaaaa 3","Blablablaaaaa 4"},
                        {"Nonsense 1111","Nonsense 22222","Nonsense 33333","Nonsense 4444"}};
    
    //Array with post creators
    string temp2[][SIZE] = { {"author 1","author 2","author 3","author 2"},
                             {"admin 1","admin 2","admin 3","admin 4"},
                             {"anybody 1","anybody 2","anybody 3","anybody 4"},
                             {"nobody 1","nobody 2","nobody 3","nobody 4"}};
    thread_creator = name;  
    subject = title;
    int year = 2015;
    int month = (rand() % 12)+1;
    int day = (rand() % 30)+1;
    set(month, day, year);
    get(month, day, year);

    for(i = 0; i < SIZE; i++ )
    {
        sprintf(temp, "%s %d", title.c_str(), i);
        if (i == 0) set_post(thread_creator, temp, temp1[j][i],j,i);
        else set_post(temp2[j][i], temp, temp1[j][i],j,i);
    }     
}



string forum::get_thread_creator(int i)
{
    string temp;
    temp = threads[i].get_thread_creator();
    return temp;
}

string thread::get_thread_creator()
{
    return thread_creator;
}

string forum::get_thread(int i)
{
    string subject;
    subject = threads[i].get_thread();
    return subject;
}

string thread::get_thread()
{
    return subject;
}

void thread::set_post(const string name,const char* title,const string txt, int num, int i)
{
    post();
    posts[i].set_post(name, title, txt, num );
}

post:: post()
{
    //do nothing
    return;
}

void post::set_post(const string name,const char* title,const string txt, int num)
{
    static int i = 0;
    post_creator = name;
    post_title = new char[strlen(title)+1];
    strcpy(post_title,title);
    text = txt;
    id = i;
    int year = 2015;
    int month = (rand() % 12)+1;
    int day = (rand() % 30)+1;
    set(month, day, year);
    i++;
}

string thread::get_post(int i)
{
    string subject;
    subject = posts[i].get_post();
    return subject;
}

string post::get_post()
{
    return post_title;
}

string thread::get_post_txt(int i)
{
    string temp;
    temp = posts[i].get_post_txt();
    return temp;
}

string post::get_post_txt()
{
    return text;
}

string thread::get_post_creator(int i)
{
    string temp;
    temp = posts[i].get_post_creator();
    return temp;
}

string post::get_post_creator()
{
    return post_creator;
}

int forum::get_post_id(int i,int j)
{
    threads[i].get_post_id(j);
}

int  thread::get_post_id(int i)
{
    int temp;
    temp = posts[i].get_post_id();
    return temp;
}

int  post::get_post_id()
{
    return id;
}

void thread::set(int month, int day, int year)
{
    thread_date.set(month, day, year );
}

void post::set(int month, int day, int year)
{
    post_date.set(month, day, year);
}

void forum::get(int &month, int &day, int &year,int i)
{
    threads[i].get(month, day, year);
}

void thread::get(int &month, int &day, int &year)
{
    thread_date.get(month, day, year);
}

void post::get(int &month, int &day, int &year)
{
    post_date.get(month, day, year);
}

thread forum::get_whole_thread(int i)
{
    thread temp = threads[i];
    return temp;
    
}

post thread::get_whole_post(int i)
{
    post temp = posts[i];
    return temp;
}

void thread::print()
{
    int i, j, month, day, year;
        cout << "\nThread title "<<  get_thread() << endl;
        cout << "Thread writer: "<<  get_thread_creator() <<  endl; 
        get(month, day, year);
        cout << "Thread date: "<<  day << " "<< month << "  " << year <<  endl;
        for(j = 0; j < SIZE; j++ )
        {
            cout << "Post title: "<<  get_post(j) <<  endl;
            cout << "Post id: "<<  get_post_id(j) <<  endl;
            cout << "Post writer: "<<  get_post_creator(j) <<  endl;
            get(month, day, year);
            cout << "Post date: " <<  day << " "<< month << "  " << year <<  endl;
            cout << "Post text: "<<  get_post_txt(j) <<  endl;
        }
}

