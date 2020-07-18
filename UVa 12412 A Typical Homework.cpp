#include<bits/stdc++.h>
using namespace std;
#define Om ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
struct Student
{
    string SID;
    int CID, score[4], TotalNumber, Rank, NumberOfPassed, position;
    double Average;
    string name;

    Student(string s, int c, string n, int *a): SID(s), CID(c), name(n), TotalNumber(0), Average(0.0), position(0), NumberOfPassed(0)
    {
        for(int i=0; i<4; i++)
        {
            score[i] = a[i];
            TotalNumber += a[i];
        }
        Average = TotalNumber/4.0;
    }
    bool operator<(const Student &a)const
    {
        return a.TotalNumber < TotalNumber;
    }
    void calculation()
    {
        for(int i=0; i<4; i++)
            if(score[i] >= 60)
                NumberOfPassed++;
    }
};
vector<Student>v;
set<string>s;
string Subject[] = {"Chinese", "Mathematics", "English", "Programming"};
void PrintData()
{
    cout<<"Welcome to Student Performance Management System (SPMS)."<<endl<<endl;
    cout<<"1 - Add"<<endl;
    cout<<"2 - Remove"<<endl;
    cout<<"3 - Query"<<endl;
    cout<<"4 - Show ranking"<<endl;
    cout<<"5 - Show Statistics"<<endl;
    cout<<"0 - Exit"<<endl<<endl;
}
void Add()
{
    while(true)
    {
        cout<<"Please enter the SID, CID, name and four scores. Enter 0 to finish."<<endl;
        string sid;
        int cid;
        string name;
        int a[4];
        cin>>sid;
        if(sid == "0")
            return;
        cin>>cid>>name;
        for(int i=0; i<4; i++)
            cin>>a[i];
        if(s.count(sid))
            cout<<"Duplicated SID."<<endl;
        else
        {
            Student st(sid, cid, name, a);
            st.calculation();
            v.push_back(st);
            s.insert(sid);
        }
    }
}
void Remove()
{
    while(true)
    {
        cout<<"Please enter SID or name. Enter 0 to finish."<<endl;
        string tmp;
        cin>>tmp;
        if(tmp=="0")
            return;
        int cnt=0;
        vector<int>Deleted;
        for(vector<Student>::iterator it = v.begin(); it != v.end(); it++)
        {
            if(it->SID==tmp || it->name==tmp)
            {
                Deleted.push_back(it-v.begin());
                cnt++;
            }
        }
        for(vector<int>::iterator it = Deleted.begin(); it != Deleted.end(); it++)
        {
            v.erase(v.begin()+*it);
            s.erase( (v.begin()+*it)->SID );
        }
        cout<<cnt<<" student(s) removed."<<endl;
    }
}
void Query()
{
    while(true)
    {
        cout<<"Please enter SID or name. Enter 0 to finish."<<endl;
        string tmp;
        cin>>tmp;
        if(tmp == "0")
            return;
        vector<Student>rnk;
        for(vector<Student>:: iterator it = v.begin(); it != v.end(); it++)
        {
            if(it->SID==tmp || it->name==tmp)
                it->position = it - v.begin();
            rnk.push_back(*it);
        }
        stable_sort(rnk.begin(), rnk.end());
        for(vector<Student>:: iterator it = rnk.begin(); it != rnk.end(); it++)
        {
            if(it == rnk.begin())
                v[it->position].Rank = 1;
            else if(it->TotalNumber == (it-1)->TotalNumber)
                v[it->position].Rank = v[(it-1)->position].Rank;
            else
                v[it->position].Rank = it-rnk.begin()+1;
        }
        for(vector<Student>:: iterator it = v.begin(); it != v.end(); it++)
        {
            if(it->SID == tmp  || it->name == tmp)
            {
                cout<<it->Rank<<" "<<it->SID<<" "<<it->CID<<" "<<it->name<<" ";
                for(int i=0; i<4; i++)
                {
                    cout<<it->score[i]<<" ";
                }
                cout<<it->TotalNumber<<" "<<setprecision(2)<<fixed<<it->Average<<endl;
            }
        }
    }
}
void ShowRanking()
{
    cout<<"Showing the ranklist hurts students' self-esteem. Don't do that."<<endl;
}
void calculationAll(int sub, double &average, int &pass, int &notpass)
{
    int sum=0;
    for(vector<Student>:: iterator it = v.begin(); it != v.end(); it++)
    {
        int sc = it->score[sub];
        if(sc >= 60)
            pass++;
        else
            notpass++;
        sum += sc;
    }
    average = 1.0*sum/v.size();
}
void calculationSingle(int cid, int sub, double &average, int &pass, int &notpass)
{
    int sum=0, numofStudent=0;
    for(vector<Student>:: iterator it = v.begin(); it != v.end(); it++)
    {
        if(it->CID == cid)
        {
            numofStudent++;
            int sc = it->score[sub];
            if(sc >= 60)
                pass++;
            else
                notpass++;
            sum += sc;
        }
    }
    average = 1.0*sum/numofStudent;
}
void ShowStatistics()
{
    cout<<"Please enter class ID, 0 for the whole statistics."<<endl;
    int cid;
    cin>>cid;
    if(cid)
    {
        for(int i=0; i<4; i++)
        {
            int pass=0, notpass=0;
            double average = 0.0;
            calculationSingle(cid, i, average, pass, notpass);
            cout<<Subject[i]<<endl;
            cout<<"Average Score: "<<setprecision(2)<<fixed<<average<<endl;
            cout<<"Number of passed students: "<<pass<<endl;
            cout<<"Number of failed students: "<<notpass<<endl<<endl;
        }
        int passOne=0, passTwo=0, passThree=0, PassAll=0, failAll=0;
        for(vector<Student>:: iterator it = v.begin(); it != v.end(); it++)
        {
            if(it->CID == cid)
            {
                int a = it->NumberOfPassed;
                if(a>0)
                    passOne++;
                if(a>1)
                    passTwo++;
                if(a>2)
                    passThree++;
                if(a==4)
                    PassAll++;
                if(a==0)
                    failAll++;
            }
        }
        cout<<"Overall:"<<endl;
        cout<<"Number of students who passed all subjects: "<<PassAll<<endl;
        cout<<"Number of students who passed 3 or more subjects: "<<passThree<<endl;
        cout<<"Number of students who passed 2 or more subjects: "<<passTwo<<endl;
        cout<<"Number of students who passed 1 or more subjects: "<<passOne<<endl;
        cout<<"Number of students who failed all subjects: "<<failAll<<endl<<endl;

    }
    else
    {
        for(int i=0; i<4; i++)
        {
            int pass=0, notpass=0;
            double average = 0.0;
            calculationAll(i, average, pass, notpass);
            cout<<Subject[i]<<endl;
            cout<<"Average Score: "<<setprecision(2)<<fixed<<average<<endl;
            cout<<"Number of passed students: "<<pass<<endl;
            cout<<"Number of failed students: "<<notpass<<endl<<endl;
        }
        int passOne=0, passTwo=0, passThree=0, PassAll=0, failAll=0;
        for(vector<Student>:: iterator it = v.begin(); it != v.end(); it++)
        {
            int a = it->NumberOfPassed;
            if(a>0)
                passOne++;
            if(a>1)
                passTwo++;
            if(a>2)
                passThree++;
            if(a>3)
                PassAll++;
            if(a==0)
                failAll++;
        }
        cout<<"Overall:"<<endl;
        cout<<"Number of students who passed all subjects: "<<PassAll<<endl;
        cout<<"Number of students who passed 3 or more subjects: "<<passThree<<endl;
        cout<<"Number of students who passed 2 or more subjects: "<<passTwo<<endl;
        cout<<"Number of students who passed 1 or more subjects: "<<passOne<<endl;
        cout<<"Number of students who failed all subjects: "<<failAll<<endl<<endl;

    }
}
int main()
{
    Om;
    while(true)
    {
        PrintData();
        int n;
        cin>>n;
        if(!n)
            return 0;
        else if(n==1)
            Add();
        else if(n==2)
            Remove();
        else if(n==3)
            Query();
        else if(n==4)
            ShowRanking();
        else if(n==5)
            ShowStatistics();
    }
    return 0;
}


