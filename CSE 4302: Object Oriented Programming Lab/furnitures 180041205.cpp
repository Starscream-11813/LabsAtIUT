#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
enum class SofaSize {One,Two,Three,Four,Five};
enum class AlmirahSize {Two,Three,Four};
enum class BedSize {Single,SemiDouble,Double};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    void commonProductDetails()
    {
        cout<<"-----------------------------------------"<<endl;
        cout<<"Regular Price: "<<price<<endl;
        cout<<"Discounted Price: "<<price-discount<<endl;
        cout<<"Material: ";
        cout<<Furniture::getMadeof();///Calling the getMadeOf() function of the base class.
        cout<<endl;
    }
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscountPercentage(double dp)///Sets the Discount Price as a percentage of the Original Price.
    {
        setDiscount((double)((dp/100.0)*price));///Formula: ((Percentage/100)*(Original Price))==New Discount.
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    double getDiscount()///function that returns the discount of the furniture.
    {
        return discount;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails()=0;
};
class Bed:public Furniture
{
public:
    BedSize bSize;
    Bed(double p,double d,Material m,BedSize b):Furniture(p,d,m),bSize(b)///Bed's Constructor.
    {}
    string getBedSize()///returns the BedSize by checking the enum values.
    {
        if(bSize==BedSize::Single)
        {
            return "Single";
        }
        else if(bSize==BedSize::SemiDouble)
        {
            return "SemiDouble";
        }
        else if(bSize==BedSize::Double)
        {
            return "Double";
        }
    }
    void productDetails()///Product Details function for Bed.
    {
        commonProductDetails();
        cout<<"Bed Size: ";
        cout<<Bed::getBedSize();///Derived class function.
        cout<<endl;
        cout<<"######################################"<<endl;
    }
};
class Sofa:public Furniture
{
public:
    SofaSize sNumber;
    Sofa(double p,double d,Material m,SofaSize s):Furniture(p,d,m),sNumber(s)///Sofa's Constructor.
    {}
    string getSofaSize()///returns the SofaSize by checking the enum values.
    {
        if(sNumber==SofaSize::One)
        {
            return "One";
        }
        else if(sNumber==SofaSize::Two)
        {
            return "Two";
        }
        else if(sNumber==SofaSize::Three)
        {
            return "Three";
        }
        else if(sNumber==SofaSize::Four)
        {
            return "Four";
        }
        else if(sNumber==SofaSize::Five)
        {
            return "Five";
        }
    }
    void productDetails()///Product Details function for Sofa.
    {
        commonProductDetails();
        cout<<"Sofa Size: ";
        cout<<Sofa::getSofaSize();///Derived class function.
        cout<<endl;
        cout<<"######################################"<<endl;
    }
};
class Almirah:public Furniture
{
public:
    AlmirahSize dCount;
    Almirah(double p,double d,Material m,AlmirahSize dc):Furniture(p,d,m),dCount(dc)///Almirah's Constructor.
    {}
    string getAlmirahSize()///returns the AlmirahSize by checking the enum values.
    {
        if(dCount==AlmirahSize::Two)
        {
            return "Two";
        }
        else if(dCount==AlmirahSize::Three)
        {
            return "Three";
        }
        else if(dCount==AlmirahSize::Four)
        {
            return "Four";
        }
    }
    void productDetails()///Product Details function for Almirah.
    {
        commonProductDetails();
        cout<<"Almirah Size: ";
        cout<<Almirah::getAlmirahSize();///Derived class function.
        cout<<endl;
        cout<<"######################################"<<endl;
    }
};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures);///Function Prototype.
void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures)///Function Definition.
{
    vector<pair<double,Furniture*> >v(no_of_furnitures);///{discount price,Furniture object pointer}-->how each pair of the vector looks. Vector size equals the number of Furnitures (2nd Parameter).
    for(int i=0;i<no_of_furnitures;i++)
    {
        v[i].first=furnitures[i]->getDiscount();///Assign the discount to the 1st slot. This is our main focus for sorting.
        v[i].second=furnitures[i];///Assign the Furniture object pointer to the 2nd slot.
    }
    sort(v.begin(),v.end());///Pair soring is done on the basis of the 1st slot element. So, here, it's being sorted on the basis of Discount.
    reverse(v.begin(),v.end());///Since the Scenario dictates to sort in descending order, we just reverse the vector.
    for(int i=0;i<no_of_furnitures;i++)
    {
        furnitures[i]=v[i].second;///Now, we assign the sorted Furniture object pointers to the pointer array that was originally passed as the 1st parameter of the function.
    }
    ///Descending Order Sorting Complete!~
}

int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new Almirah(13000,345,Material::Wood,AlmirahSize::Two);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);///Lines 203, 204, 205, 206 will work now. (Task 1 Done)

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[1]->setDiscountPercentage(10);///Setting 10% Discount Percentage.
    f_list[2]->setDiscountPercentage(69);///Setting 69% Discount Percentage.(Task 3 Done)
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();///The version of productDetails() function of their respective (derived) classes will be called.(Task 2 Done)
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    So that following lines can be executed without error
    */
    sort_furniture_discount(f_list,4);///Sorting the List.(Task 4 Done)
    cout<<endl<<endl<<"After Sorting: "<<endl;///Printing the sorted List.
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    /**task 4 ends here*/
    for(int i=0; i<4; i++)///Deallocating the dynamically allocated memories. (Good coding practice)
    {
        delete f_list[i];
    }
    return 0;
}
