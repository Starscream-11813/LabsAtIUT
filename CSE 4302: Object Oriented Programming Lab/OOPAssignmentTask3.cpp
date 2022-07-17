#include<bits/stdc++.h>
using namespace std;

#define LD                      long double
#define ll                      long long int
#define FastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff                      first
#define ss                      second

class Candidate
{
private:
    ll ID;
    string mobile_phone_no;
    LD public_exam_mark1;
    LD public_exam_mark_2;
    static LD max_mark1,max_mark2;
    static int total_candidiates;
    int merit_position;
public:
    Candidate()
    {
        //cout<<"ctor called"<<endl;
        total_candidiates++;
        ID=total_candidiates;
        merit_position=ID;
    }
    void set_public_exam_mark(LD mark1, LD mark2)
    {
        public_exam_mark1=mark1;
        max_mark1=max(max_mark1,mark1);
        public_exam_mark_2=mark2;
        max_mark2=max(max_mark2,mark2);
    }
    void set_mobile_phone_no(string p)
    {
        mobile_phone_no=p;
    }
    void update_mobile_phone_no(string p)
    {
        mobile_phone_no="";
        mobile_phone_no+=p;
    }
    void set_merit_position(int x)
    {
        merit_position=x;
    }
    LD get_total_marks() const
    {
        return (public_exam_mark1+public_exam_mark_2);
    }

    void show_all()
    {
        cout<<"ID: "<<ID<<endl;
        cout<<"Mobile Phone No.: "<<mobile_phone_no<<endl;
        cout<<"1st Public Exam Mark: "<<public_exam_mark1<<endl;
        cout<<"2nd Public Exam Mark: "<<public_exam_mark_2<<endl;
        cout<<"Total Marks Obtained: "<<public_exam_mark1+public_exam_mark_2<<endl;
        cout<<"Highest 1st Public Exam Mark: "<<max_mark1<<endl;
        cout<<"Highest 2nd Public Exam Mark: "<<max_mark2<<endl;
        cout<<"Total Candidates Registered: "<<total_candidiates<<endl;
        cout<<"Merit Position :"<<merit_position<<endl;
    }
};
int Candidate::total_candidiates=0;
LD Candidate::max_mark1=0.0;
LD Candidate::max_mark2=0.0;
bool sortbymeritcmp(const Candidate &x, const Candidate &y)///Comparator Function for sorting.
{
    return (bool)(x.get_total_marks() > y.get_total_marks());
}

void sorting_by_merit(vector<Candidate> &v, int registered_till_now)
{
    sort(v.begin(),v.begin()+registered_till_now+1,sortbymeritcmp);
    for(int i=0; i<=registered_till_now; i++)
    {
        v[i].set_merit_position(i+1);
    }
}
int main()
{
    FastIO;
    vector<Candidate>v(4);///4 candidates registered.
    v[0].set_public_exam_mark(69.0,96.5);
    v[1].set_public_exam_mark(45.5,88.25);
    v[2].set_public_exam_mark(55.6,85.35);
    v[3].set_public_exam_mark(42.5,68.75);
    v[0].set_mobile_phone_no("+8801712618045");
    v[1].set_mobile_phone_no("+8801512718443");
    v[2].set_mobile_phone_no("+8801118616049");
    v[3].set_mobile_phone_no("+8801732618642");
    v[3].update_mobile_phone_no("+8801234556769");
    //sorting_by_merit(v,3); ///After sorting...
    v[0].show_all();
    v[1].show_all();
    v[2].show_all();
    v[3].show_all();
    return 0;
}
