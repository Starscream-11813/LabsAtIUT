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
public class Lab01_2A_180041205 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        if(isPalindrome(s))
        {
            System.out.println("It is a palindrome.");
        }
        else
        {
            System.out.println("It is NOT a palindrome.");
        }
    }
    public static boolean isPalindrome(String s)
    {
        s=s.toLowerCase();
        boolean flag=true;
        for (int i = 0; i < s.length()/2; i++)
        {
            if(s.charAt(i)!=s.charAt(s.length()-i-1))
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
    
}
