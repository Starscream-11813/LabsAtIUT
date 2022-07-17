import java.sql.*;
public class Lab9DBMS
{
    public static void main(String[] args)
    {
        String user="system",password="test123";//Please change the username and password.
        String url="jdbc:oracle:thin:@localhost:1521/XE";//Type of Driver @ Port Number of our Database.
        String query1="select A_ID,sum(Amount) from Transactions group by A_ID";//Returns the A_ID and aggregate of transaction values the person with A_ID was involved with.
        String query2="select A_ID, Amount, Type from Transactions";//Returns the A_ID, Amount and Type of transaction from Transactions table.
        String query3="select count(*) from Account";//Returns the total number of accounts in a single column.
        int CIP=0, VIP=0, Ordinary=0, Uncatergorized=0,cAccounts=0;//Variable names are self-explanatory.
        try
        {
            Class.forName("oracle.jdbc.driver.OracleDriver");//Registering the driver class. Makes our project aware of the library file.
            Connection conn = DriverManager.getConnection(url, user, password);//Connecting to our database using Connection class. getConnection() is a static function with 3 given parameters and its job is to facilitate the connection.
            Statement stm=conn.createStatement();//Need this to execute the queries later on.
            //System.out.println("Successful!~\n");
            ResultSet res3=stm.executeQuery(query3);//Executing query3 by passing it through the executeQuery() method of Statement class.
            while(res3.next())//Traversing through the rows of the output table.
            {
                cAccounts=res3.getInt(1);//scans the value obtained in the 1st column.
            }
            int[] totalTransaction=new int[cAccounts+1];//Initializing array with a size equal to the total number of accounts.
            int[] currentBalance=new int[cAccounts+1];
            ResultSet res=stm.executeQuery(query1);//Executing query1 by passing it through the executeQuery() method of Statement class.
            while(res.next())//Traversing through the rows of the output table.
            {
                int accID=res.getInt(1);//A_ID column.
                int temp=res.getInt(2);//SUM(AMOUNT) column.
                totalTransaction[accID]=temp;//Assigning the value to respective index of the array. Format:totalTransaction[Account ID]=total of the transactions the person was involved with.
            }
            ResultSet res2=stm.executeQuery(query2);//Executing query2 by passing it through the executeQuery() method of Statement class.
            while(res2.next())//Traversing through the rows of the output table.
            {
                int accID=res2.getInt(1);//A_ID column.
                int temp=res2.getInt(2);//Amount column.
                int flag=Integer.parseInt(res2.getString(3));//Type column. The char(1) value is scanned as a string and then parsed as an integer.
                //System.out.println("Flag: "+flag);
                if(flag==0)//If money was deposited to the account.
                {
                    currentBalance[accID]=currentBalance[accID]+temp;//Add it to the account's current balance.
                }
                else//If money was withdrawn from the account.
                {
                    currentBalance[accID]=currentBalance[accID]-temp;//Subtract it from the account's current balance.
                }
            }
            for(int i=1;i<=cAccounts;i++)//Now, we iterate through the arrays.
            {
                if(currentBalance[i]>1000000 && totalTransaction[i]>5000000)//Condition given in the scenario for CIP.
                {
                    CIP++;
                }
                else if(currentBalance[i]>500000 && currentBalance[i]<900000 && totalTransaction[i]>3500000 && totalTransaction[i]<4500000)//Condition given in the scenario for VIP.
                {
                    VIP++;
                }
                else if(currentBalance[i]<40000 && totalTransaction[i]<3000000)//Condition given in the scenario for Ordinary person.
                {
                    Ordinary++;
                }
                else//Condition given in the scenario for Uncatergorized persons.
                {
                    Uncatergorized++;
                }
                //System.out.println("CB: "+currentBalance[i]);
            }
            System.out.println("Total Number of Accounts: "+cAccounts);//Printing the output as dictated in the scenario statement.
            System.out.println("CIP count: "+CIP);
            System.out.println("VIP count: "+VIP);
            System.out.println("Ordinary count: "+Ordinary);
            System.out.println("Uncategorized: "+Uncatergorized);
            conn.close();//Close the connection with out database.
            stm.close();//The following 4 lines are already executed when the Connection object is closed. So, they are redundant and may be omitted if wanted.
            res.close();
            res2.close();
            res3.close();
        }
        catch(SQLException e)//Handles SQLException. Will throw the exception code if the program faces any failure to connect to the database.
        {
            System.out.println("Error: Can't connect to Database. Exception Code: "+e);
        }
        catch (ClassNotFoundException e)//Handles ClassNotFoundException. Will throw the exception code if the program fails to load any classes probably because of a faulty CLASSPATH.
        {
            System.out.println("Error: Driver registration failed. Exception Code: "+e);
        }
    }
}
