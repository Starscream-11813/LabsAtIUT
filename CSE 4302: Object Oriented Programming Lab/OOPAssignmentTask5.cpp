#include<bits/stdc++.h>
using namespace std;

#define LD                      long double
#define ll                      long long int
#define FastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff                      first
#define ss                      second
#define pb                      push_back


class Team
{
private:
    vector<string>players;
    vector<int>runs;
    map<string, int>m;
    int total;
    string highest_run_batsman;
    int highest_run;
public:
    Team()
    {
        m.clear();
        //players.clear();
        //runs.clear();
        for(int i=0; i<11; i++)
        {
            players.pb("");
            runs.pb(0);
        }
        //fill(players.begin(),players.end(),"");
        //fill(runs.begin(),runs.end(),0);
        total=0;
        highest_run=0;
        highest_run_batsman="";
    }
    void set_Team()
    {
        cout<<"Enter team members and their respective runs: "<<endl;
        for(int i=0; i<11; i++)/// 11 players form a single team.
        {
            int run;
            string s1;
            cin>>s1>>run;
            players[i]=s1;
            runs[i]=run;
            m[s1]=run;
            total+=run;
            if(highest_run<run)
            {
                highest_run_batsman=s1;
            }
            highest_run=max(highest_run,run);
        }
    }
    int get_total_runs()
    {
        return total;
    }
    int get_highest_run()
    {
        return highest_run;
    }
    string get_highest_run_batsman()
    {
        return highest_run_batsman;
    }
};

class Game
{
    string MOT;
    string winning_team;
public:
    Team Team1,Team2;
    Game()
    {
        Team1.set_Team();
        Team2.set_Team();
    }
    string get_winning_team()
    {
        if (Team1.get_total_runs() > Team2.get_total_runs())
        {
            winning_team = "Team 1";
        }
        else
        {
            winning_team = "Team 2";
        }
        return winning_team;
    }
    string get_Man_of_the_Match()
    {
        if (Team1.get_highest_run() > Team2.get_highest_run())
        {
            MOT = Team1.get_highest_run_batsman();
        }
        else
        {
            MOT = Team2.get_highest_run_batsman();
        }
        return MOT;
    }
};
int main()
{
    FastIO;
    Game U19WorldCupFinal;
    cout<<"Winner of the U19 World Cup 2020 is: "<<U19WorldCupFinal.get_winning_team()<<endl;
    cout<<"Man of the Match: "<<U19WorldCupFinal.get_Man_of_the_Match()<<endl;
    return 0;
}
