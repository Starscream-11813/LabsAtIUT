/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab02_2a_180041205;
import java.util.Scanner;
/**
 *
 * @author Rifat
 */
public class Lab02_2A_180041205 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        // TODO code application logic here
        int size = 100;
        myStack st = new myStack(size);

        //Sample Inputs: [()]{}{[()()]()}, [(]), [{()}], {()}[], ], [, [), ()), (()
        String brackets;
        System.out.println("Enter a string of parentheses: ");
        Scanner sc = new Scanner(System.in);
        brackets = sc.nextLine();
        for (int i = 0; i < brackets.length(); i++)
        {
            if (brackets.charAt(i) == '[' || brackets.charAt(i) == '{' || brackets.charAt(i) == '(')
            {
                st.push(brackets.charAt(i));
            }
            else
            {
                if (i == 0 && (brackets.charAt(i) == ']' || brackets.charAt(i) == '}' || brackets.charAt(i) == ')'))
                {
                    st.push(brackets.charAt(i)); //For handling cases like "]", "}{)" or ")(".
                    break;
                }
                if ((st.top() == '[' && brackets.charAt(i) == ']') || (st.top() == '{' && brackets.charAt(i) == '}') || (st.top() == '(' && brackets.charAt(i) == ')'))
                {
                    st.pop();
                }
                else
                {
                    st.push(brackets.charAt(i)); //For handling cases like "())".
                }
            }
        }
        if (st.isEmpty())
        {
            System.out.println("Balanced");
        }
        else
        {
            System.out.println("Not balanced");
        }
    }
}
    

