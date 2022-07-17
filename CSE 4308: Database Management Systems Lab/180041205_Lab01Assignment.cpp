#include<bits/stdc++.h>
using namespace std;

//Commands and Functions
#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define ABS(x)                  ((x)<0?-(x):(x))
#define min3(a,b,c)             min(a,min(b,c))
#define Godspeed                ios_base::sync_with_stdio(0);cin.tie(NULL)
#define urs(r...)               typename decay<decltype(r)>::type
#define FOR(i,a,b)              for(urs(b) i=a;i<=b;i++)
#define ROF(i,a,b)              for(urs(b) i=a;i>=b;i--)
#define REP(i,b)                for(urs(b) i=0;i<b;i++)
#define rep(i, begin, end)      for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define PER(i,a,b)              for(urs(b) i=a;i>b;i--)
#define FOREACH(i,t)            for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define what_is(x)              cerr << #x << " is " << x << endl;
//Datatypes
#define ll                      long long
#define ULL                     unsigned long long
#define LD                      long double
#define UI                      unsigned int
#define US                      unsigned short
//Data Structures
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define pldld pair<long long double, long long double>

struct customer
{
    int Customer_id;
    string Name;
    int Age;
    string Gender;
    int No_Of_Purchases;
    char Customer_Type[20];
};
struct product
{
    int Product_id;
    string Name;
    int Price;
    int Weight;
};
customer addmode,viewmode,removalmode;
product addmodep,viewmodep,removalmodep;
void clean();
void add_customer();
void add_product();
void searchcustomer();
void purgethenovelties();
void updatecustomer();
void showinterface();
void clean()
{
    system("cls");
}
void add_customer()
{
    FILE *fp;
    fp=fopen("Customer.txt","a+");

addcustomerentrycheckpoint:
    /*cout<<"Customer ID: ";
    cin>>addmode.Customer_id;
    cout<<endl;
    cout<<"Name: ";
    cin>>addmode.Name;
    cout<<endl;
    cout<<"Age: ";
    cin>>addmode.Age;
    cout<<endl;
    cout<<"Gender: ";
    cin>>addmode.Gender;
    cout<<endl;
    cout<<"Number of Purchases: ";
    cin>>addmode.No_Of_Purchases;
    cout<<endl;
    cout<<"Customer Type: ";
    cin>>addmode.Customer_Type;
    cout<<endl;*/
    printf("Customer ID: ");
    scanf("%d",&addmode.Customer_id);
    cout<<endl;
    printf("Name: ");
    scanf("%s",&addmode.Name);
    cout<<endl;
    printf("Age: ");
    scanf("%d",&addmode.Age);
    cout<<endl;
    printf("Gender (Male or Female): ");
    scanf("%s",&addmode.Gender);
    cout<<endl;
    printf("Number of Purchases: ");
    scanf("%d",&addmode.No_Of_Purchases);
    cout<<endl;
    printf("Customer Type: ");
    scanf("%s",&addmode.Customer_Type);
    cout<<endl;
    fprintf(fp,"%d %s %d %s %d %s\n",addmode.Customer_id,addmode.Name,addmode.Age,addmode.Gender,addmode.No_Of_Purchases,addmode.Customer_Type);
    fclose(fp);
addcustomerexitcheckpoint:
    cout<<endl<<endl;
    cout<<"Press 1 to return to Main Menu"<<endl;
    cout<<"Press 0 to Exit the Interface"<<endl;
    int choice;
    cin>>choice;
    clean();
    if(choice==0)
    {
        cout<<"Interface Exited Successfully!"<<endl;
        exit(0);
    }
    else if(choice==1)
    {
        showinterface();
    }
    else
    {
        cout<<"Invalid choice"<<endl;
        goto addcustomerexitcheckpoint;
    }
}
void add_product()
{
    FILE *fp;
    fp=fopen("Product.txt","a+");

addproductentrycheckpoint:
    printf("Product ID: ");
    scanf("%d",&addmodep.Product_id);
    printf("Name: ");
    scanf("%s",&addmodep.Name);
    printf("Price($): ");
    scanf("%d",&addmodep.Price);
    printf("Weight(kg): ");
    scanf("%d",&addmodep.Weight);
    fprintf(fp,"%d %s %d %d\n",addmodep.Product_id,addmodep.Name,addmodep.Price,addmodep.Weight);
    fclose(fp);
addproductexitcheckpoint:
    cout<<endl<<endl;
    cout<<"Press 1 to return to Main Menu"<<endl;
    cout<<"Press 0 to Exit the Interface"<<endl;
    int choice;
    cin>>choice;
    clean();
    if(choice==0)
    {
        cout<<"Interface Exited Successfully!"<<endl;
        exit(0);
    }
    else if(choice==1)
    {
        showinterface();
    }
    else
    {
        cout<<"Invalid choice"<<endl;
        goto addproductexitcheckpoint;
    }
}
void searchcustomer()
{
    FILE *vfp;
    vfp=fopen("Customer.txt","r");
    int line=0;
    cout<<"Enter the ID of the Customer: "<<endl;
    int cusid;
    cin>>cusid;
    while(fscanf(vfp,"%d %s %d %s %d %s",&addmode.Customer_id,&addmode.Name,&addmode.Age,&addmode.Gender,&addmode.No_Of_Purchases,&addmode.Customer_Type)!=EOF)
    {
        if(cusid==addmode.Customer_id)
        {
            /*cout<<"Customer ID: ";
            cout<<addmode.Customer_id<<endl;
            cout<<"Name: ";
            cout<<addmode.Name<<endl;
            cout<<"Age: ";
            cout<<addmode.Age<<endl;
            cout<<"Gender: ";
            cout<<addmode.Gender<<endl;
            cout<<"Number of Purchases: ";
            cout<<addmode.No_Of_Purchases<<endl;
            cout<<"Customer Type: ";
            cout<<addmode.Customer_Type<<endl;*/
            printf("Customer ID: ");
            printf("%d",addmode.Customer_id);
            cout<<endl;
            printf("Name: ");
            printf("%s",addmode.Name);
            cout<<endl;
            printf("Age: ");
            printf("%d",addmode.Age);
            cout<<endl;
            printf("Gender: ");
            printf("%s",addmode.Gender);
            cout<<endl;
            printf("Number of Purchases: ");
            printf("%d",addmode.No_Of_Purchases);
            cout<<endl;
            printf("Customer Type: ");
            printf("%s",addmode.Customer_Type);
            cout<<endl;
            line++;
        }
    }
    fclose(vfp);
    if(!line)
    {
        clean();
        cout<<"No Customer of this ID has been registered!"<<endl;
    }
searchcustomerexitcheckpoint:
    cout<<endl<<endl;
    cout<<"Press 1 to return to Main Menu"<<endl;
    cout<<"Press 0 to Exit the Interface"<<endl;
    int choice;
    cin>>choice;
    clean();
    if(choice==0)
    {
        cout<<"Interface Exited Successfully!"<<endl;
        exit(0);
    }
    else if(choice==1)
    {
        showinterface();
    }
    else
    {
        cout<<"Invalid choice"<<endl;
        goto searchcustomerexitcheckpoint;
    }

}
void purgethenovelties()
{
    FILE *prepurge,*postpurge;
    prepurge=fopen("Product.txt","r");
    postpurge=fopen("temp.txt","w");
    while(fscanf(prepurge,"%d %s %d %d",&addmodep.Product_id,&addmodep.Name,&addmodep.Price,&addmodep.Weight)!=EOF)
    {
        if(addmodep.Price<=1000)
        {
            fprintf(postpurge,"%d %s %d %d\n",addmodep.Product_id,addmodep.Name,addmodep.Price,addmodep.Weight);
        }
    }
    fclose(prepurge);
    fclose(postpurge);
    remove("Product.txt");
    rename("temp.txt","Product.txt");
    cout<<"Products with price greater than 1000$ have been removed from the record!"<<endl;
    cout<<"Check the Product.txt file ASAP!"<<endl;
purgethenoveltiesexitcheckpoint:
    cout<<endl<<endl;
    cout<<"Press 1 to return to Main Menu"<<endl;
    cout<<"Press 0 to Exit the Interface"<<endl;
    int choice;
    cin>>choice;
    clean();
    if(choice==0)
    {
        cout<<"Interface Exited Successfully!"<<endl;
        exit(0);
    }
    else if(choice==1)
    {
        showinterface();
    }
    else
    {
        cout<<"Invalid choice"<<endl;
        goto purgethenoveltiesexitcheckpoint;
    }
}
void updatecustomer()
{
    FILE *preupdate,*postupdate;
    preupdate=fopen("Customer.txt","r");
    postupdate=fopen("temp.txt","w");
    while(fscanf(preupdate,"%d %s %d %s %d %s",&addmode.Customer_id,&addmode.Name,&addmode.Age,&addmode.Gender,&addmode.No_Of_Purchases,&addmode.Customer_Type)!=EOF)
    {
        if(addmode.No_Of_Purchases>20)
        {
            //addmode.Customer_Type="Frequent";
            strcpy(addmode.Customer_Type,"Frequent");
        }
        fprintf(postupdate,"%d %s %d %s %d %s\n",addmode.Customer_id,addmode.Name,addmode.Age,addmode.Gender,addmode.No_Of_Purchases,addmode.Customer_Type);
    }
    fclose(preupdate);
    fclose(postupdate);
    remove("Customer.txt");
    rename("temp.txt","Customer.txt");
    cout<<"Customer Status have been changed!"<<endl;
    cout<<"Check the Customer.txt file ASAP!"<<endl;
updatecustomerexitcheckpoint:
    cout<<endl<<endl;
    cout<<"Press 1 to return to Main Menu"<<endl;
    cout<<"Press 0 to Exit the Interface"<<endl;
    int choice;
    cin>>choice;
    clean();
    if(choice==0)
    {
        cout<<"Interface Exited successfully!"<<endl;
        exit(0);
    }
    else if(choice==1)
    {
        showinterface();
    }
    else
    {
        cout<<"Invalid choice"<<endl;
        goto updatecustomerexitcheckpoint;
    }
}
void showinterface()
{
    clean();
    cout<<"Customer Database Interface:"<<endl;
    cout<<"1: Enter Data in the Customer.txt."<<endl;
    cout<<"2: Enter Data in the Project.txt."<<endl;
    cout<<"3: Search a Customer with their ID."<<endl;
    cout<<"4: Get rid of all products with price above 1000$."<<endl;
    cout<<"5: Update Customers with 20+ purchases as \"Frequent\" type."<<endl;
    cout<<"0: Exit the Interface."<<endl;
    cout<<"\n\nEnter your choice:"<<endl;
    int choice;
    cin>>choice;
    if(choice==0)
    {
        cout<<"Interface Exited Successfully"<<endl;
        exit(0);
    }
    else if(choice==1)
    {
        add_customer();
    }
    else if(choice==2)
    {
        add_product();
    }
    else if(choice==3)
    {
        searchcustomer();
    }
    else if(choice==4)
    {
        purgethenovelties();
    }
    else if(choice==5)
    {
        updatecustomer();
    }
    else
    {
        cout<<"Invalid Choice!"<<endl;
        showinterface();
    }
}
int main()
{
    Godspeed;
    showinterface();
    return 0;
}

