/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab01_2a_180041205;
import java.util.Scanner;
/**
 *
 * @author Rifat
 */
public class Lab01_2A_180041205_Task2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        String s2="";
        for(int i=0;i<s.length();i++)
        {
            if(!ODD(i))
            {
                s2+=s.charAt(i);
                s2+='*';
            }
            else
            {
                s2+=s.charAt(i);
            }
        }
        System.out.println(s2);
    }
    static boolean ODD(int x)
    {
        if(x%2==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
