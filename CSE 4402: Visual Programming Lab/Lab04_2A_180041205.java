/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab04_2a_180041205;
import java.io.*;
import java.util.Scanner;
/**
 *
 * @author Nobel
 */
public class Lab04_2A_180041205 {
    public static String decrypt_vigenere(String c, String k)
    {
        int idx1, idx2=0;
        String str="";
        for(idx1=0;idx1<c.length();idx1++)
        {
            char ch1=c.charAt(idx1);
            if(c.charAt(idx1)>='A' && c.charAt(idx1)<='Z')
            {
                int dis=k.charAt(idx2)-'A';
                //ch1=Character.forDigit(ch1-dis,10);
                ch1=(char)(ch1-dis);
                if(ch1<'A')
                {
                    //ch1=Character.forDigit(ch1+26, 10);
                    ch1=(char)(ch1+26);
                }
                idx2++;
            }
            else if(ch1>='a' && ch1<='z')
            {
                int dis=k.charAt(idx2)-'A';
                //ch1=Character.forDigit(ch1-dis,10);
                ch1=(char)(ch1-dis);
                if(ch1<'A')
                {
                    //ch1=Character.forDigit(ch1+26, 10);
                    ch1=(char)(ch1+26);
                }
                idx2++;
            }
            str+=ch1;
            if(idx2==k.length()-1)//Key Length-1 cuz of an extra '\n'.
            {
                idx2=0;
            }
        }
        return str;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try
        {
            File in1=new File("C:\\Users\\Nobel\\OneDrive\\Documents\\NetBeansProjects\\Lab04_2A_180041205\\src\\lab04_2a_180041205\\input.txt");
            Scanner fileReader1=new Scanner(in1);
            String ciphertext="";
            while(fileReader1.hasNextLine())
            {
                ciphertext=ciphertext+fileReader1.nextLine()+"\n";
            }
            System.out.println("Ciphertext:\n"+ciphertext);
            fileReader1.close();
            File in2=new File("C:\\Users\\Nobel\\OneDrive\\Documents\\NetBeansProjects\\Lab04_2A_180041205\\src\\lab04_2a_180041205\\key.txt");
            Scanner fileReader2=new Scanner(in2);
            String key="";
            while(fileReader2.hasNextLine())
            {
                key = key + fileReader2.nextLine() + "\n";
            }
            System.out.println("Key:\n" + key);
            String plaintext=decrypt_vigenere(ciphertext, key);
            System.out.println("Decrypted plaintext:\n"+plaintext);
            try
            {
                FileWriter out1=new FileWriter("C:\\Users\\Nobel\\OneDrive\\Documents\\NetBeansProjects\\Lab04_2A_180041205\\src\\lab04_2a_180041205\\output.txt");
                out1.write(plaintext);
                out1.close();
            }
            catch(Exception e)
            {
                System.out.println(e);
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("An error occurred while processing file");
            e.printStackTrace();
        }
    }
    
}
