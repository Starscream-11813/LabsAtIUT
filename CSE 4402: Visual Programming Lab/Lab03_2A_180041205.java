/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab03_2a_180041205;
import java.util.*;
import java.util.Scanner;
//import net.codejava.Lab03_2A_180041205.Calendar;
/**
 *
 * @author Rifat
 */
public class Lab03_2A_180041205 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Calendar c=new Calendar();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a date in the format DD/MM/YYYY: ");
        String d=sc.nextLine();
        c.setDate(d);
        if(c.isValidDate())
        {
            System.out.println("Leap year: " + c.isLeapYear());
            System.out.println("Day: " + c.dayOfWeek);
            System.out.println("Next date: " + c.nextDate());
            System.out.println("Previous date: " + c.previousDate());
        }
        else
        {
            System.out.println("Not a valid date.");
        }
    }
    
}
