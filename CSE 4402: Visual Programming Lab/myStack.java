/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab02_2a_180041205;

/**
 *
 * @author Rifat
 */
public class myStack 
{
    char items[];
    int top;

    myStack(int size)
    {
        items=new char[size];
        top=-1;
    }
    public void push(char c)
    {
        if(top+1==items.length)
        {
            System.out.println("Stack is already full.");
            System.exit(1);
        }
        top++;
        items[top]=c;
    }
    public boolean isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public char pop()
    {
        if(isEmpty())
        {
            System.out.println("Nothing left to pop.");
            System.exit(1);
        }
        char tos=items[top];//Top of Stack.
        top--;
        return tos;
    }
    public char top()
    {
        if(isEmpty()) 
        {
            //System.out.println("No items in stack.");
            //System.exit(1);
            return '\0';

        }
        return items[top];
    }
}
