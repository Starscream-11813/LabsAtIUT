/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab03_2a_180041205;

/**
 *
 * @author Rifat
 */
public class Calendar {
    int date;
    int month;
    int year;
    String dayOfWeek;
    Calendar()
    {
        date=-1;
        month=-1;
        year=-1;
        dayOfWeek="";
    }
    public void setDate(String d)
    {
        date=Integer.parseInt(d.substring(0, 2));
        month=Integer.parseInt(d.substring(3, 5));
        year=Integer.parseInt(d.substring(6));
        dayOfWeek=this.setDayOfWeek();
    }
    public String isLeapYear()
    {
        boolean flag;
        if(year%4==0)
        {
            if(year%100==0)
            {
                if(year%400==0)
                {
                    flag=true;
                }
                else
                {
                    flag=false;
                }
            }
            else
            {
                flag=true;
            }
        }
        else
        {
            flag=false;
        }
        if(flag==true)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
    public boolean isLeapYear2()
    {
        boolean flag;
        if(year%4==0)
        {
            if(year%100==0)
            {
                if(year%400==0)
                {
                    flag=true;
                }
                else
                {
                    flag=false;
                }
            }
            else
            {
                flag=true;
            }
        }
        else
        {
            flag=false;
        }
        return flag;
    }
    public boolean isValidDate()
    {
        if(year>9999 || year<1)
        {
            return false;
        }
        if(month<1 || month>12)
        {
            return false;
        }
        if(date<1 || date>31)
        {
            return false;
        }
        if(month==2)
        {
            if(this.isLeapYear2())
            {
                return (date<=29);
            }
            else
            {
                return (date<=28);
            }
        }
        if(month==4 || month==9 || month==6 || month==11)
        {
            return (date<=30);
        }
        return true;
    }
    public String nextDate()
    {
        int date2=date;
        int month2=month;
        int year2=year;
        int epoch=31;
        date2++;
        if(month2==4 || month2==9 || month2==6 || month2==11)
        {
            epoch=30;
        }
        else if(month2==2)
        {
            if(this.isLeapYear2())epoch=29;
            else epoch=28;
        }
        if(date2>epoch)
        {
            date2=1;
            month2++;
            if(month2>12)
            {
                month2=1;
                year2++;
            }
        }
        String res= Integer.toString(date2)+"/"+Integer.toString(month2)+"/"+Integer.toString(year2);
        return res;
    }
    public String previousDate()
    {
        int date2=date;
        int month2=month;
        int year2=year;
        if(date2==1)
        {
            if(month2==4 || month2==9 || month2==6 || month2==11)
            {
                date2=31;
                month2--;
            }
            else if(month2==3)
            {
                if(this.isLeapYear2())
                {
                    date2=29;
                }
                else
                {
                    date2=28;
                }
                month2--;
            }
            else if(month2==1)
            {
                date2=31;
                month2=12;
                year2--;
            }
            else if(month2==2)
            {
                date2=31;
                month2--;
            }
            else
            {
                date2=30;
                month2--;
            }
        }
        else
        {
            date2--;
        }
        //System.out.println(date+" "+month+" "+year);
        String res= Integer.toString(date2)+"/"+Integer.toString(month2)+"/"+Integer.toString(year2);
        return res;
    }
    public String setDayOfWeek()//Sakamoto's Algorithm.
    {
        int date2=date;
        int month2=month;
        int year2=year;
        String[] m;
        m=new String[7];
        m[0]="Sunday";
        m[1]="Monday";
        m[2]="Tuesday";
        m[3]="Wednesday";
        m[4]="Thursday";
        m[5]="Friday";
        m[6]="Saturday";
        int table[]={0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        if(month2<3)
        {
            year2--;
        }
        int day=year2+(year2/4)-(year2/100)+(year2/400)+table[month2-1]+date2;
        day%=7;
        return m[day];
    }
}
